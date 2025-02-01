// Generated by gmmproc 2.45.3 -- DO NOT MODIFY!

#undef GTK_DISABLE_DEPRECATED
 //Include this before the other headers, such as main.h,
//so that the undef is used.
#include <gtkmm/window.h>
 

#include <glibmm.h>

#include <gtkmm/main.h>
#include <gtkmm/private/main_p.h>


// -*- c++ -*-
/* $Id: main.ccg,v 1.13 2006/09/19 20:08:42 murrayc Exp $ */

/* 
 *
 * Copyright 1998-2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <glib.h>
#include <gtkmmconfig.h>
#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <glibmm/init.h>
#include <giomm/init.h>
#include <pangomm/wrap_init.h>
#ifdef GTKMM_ATKMM_ENABLED
#include <ztkmm/wrap_init.h>
#endif //GTKMM_ATKMM_ENABLED
#include <gdkmm/wrap_init.h>
#include <gtkmm/wrap_init.h>

namespace
{

/* This class tells sigc++ how to break GTK+ main signal connections.  Since
 * the gtk_*_remove() functions have the same signature, all main signals can
 * be handled by a single class.  Special handling is needed for signals that
 * don't support destroy notification; see the comment on connection_list_.
 */
class GtkMainConnectionNode
{
public:
  // A function taking a connection id, e.g. gtk_timeout_remove().
  typedef void (*RemoveFunc) (guint);

  explicit GtkMainConnectionNode(const sigc::slot_base& slot);

  static void* notify(void* data);
  static void destroy_notify_handler(void* data);

  // Call this after installing the GTK+ callback.
  void install(guint conn_id, RemoveFunc remove_func, bool has_destroy_notify);

  inline sigc::slot_base* get_slot();

  static bool list_remove(GtkMainConnectionNode* conn_node);
  static void list_notify_all();

private:
  sigc::slot_base slot_;
  static GSList*  connection_list_;

  guint           conn_id_;
  RemoveFunc      remove_func_;
  bool            has_destroy_notify_;
  bool            destroyed_;
};


/* The global connection_list_ is needed to deal with GTK+ main signals
 * that don't support destroy notification.  This applies only to
 * gtk_key_snooper_install() and gtk_init_add().
 *
 * The list is static and not a member of Gtk::Main, in order to support
 * connection to Gtk::Main::signal_run() before Gtk::Main is instantiated.
 * Thus, it's possible to install initialization hooks in global constructors,
 * for instance.
 */
// static
GSList* GtkMainConnectionNode::connection_list_ = 0;

GtkMainConnectionNode::GtkMainConnectionNode(const sigc::slot_base& slot)
:
  slot_(slot),
  conn_id_             (0),
  remove_func_         (0),
  has_destroy_notify_          (false),
  destroyed_           (false)
{
  slot_.set_parent(this, &GtkMainConnectionNode::notify);
}

//static:
void* GtkMainConnectionNode::notify(void* data)
{
  // notification from the sigc++ side ...

  GtkMainConnectionNode *const self = static_cast<GtkMainConnectionNode*>(data);

  // this call might be triggered from destroy_notify_handler().
  if(!self->destroyed_)
  {
    // during (*remove_func_)() destroy_notify_handler() might get called.
    // This must not lead to the destruction of the object!
    self->destroyed_ = true;

    // disconnect from the gtk+ side.
    (*(self->remove_func_))(self->conn_id_);

    // remove self from global list.
    if (!self->has_destroy_notify_)
      list_remove(self);

    // destruction of slot_ notifies all objects referring to it.
    delete self;
  }

  return 0;
}

// static
void GtkMainConnectionNode::destroy_notify_handler(void* data)
{
  // notification from the gtk+ side ...

  GtkMainConnectionNode *const self = static_cast<GtkMainConnectionNode*>(data);

  // this call might be triggered from notify().
  if(!self->destroyed_)
  {
    self->destroyed_ = true;

    // The GTK+ side is disconnected now, thus the ID is no longer valid.
    self->conn_id_ = 0;

    // remove self from global list.
    if (!self->has_destroy_notify_)
      list_remove(self);

    // destruction of slot_ notifies all objects referring to it.
    delete self;
  }
}

void GtkMainConnectionNode::install(
    guint conn_id, GtkMainConnectionNode::RemoveFunc remove_func, bool has_destroy_notify)
{
  conn_id_     = conn_id;
  remove_func_ = remove_func;
  has_destroy_notify_  = has_destroy_notify;

  if (!has_destroy_notify_)
    connection_list_ = g_slist_prepend(connection_list_, this);
}

inline
sigc::slot_base* GtkMainConnectionNode::get_slot()
{
  return &slot_;
}

// static
bool GtkMainConnectionNode::list_remove(GtkMainConnectionNode* conn_node)
{
  // The conn_node pointer is only valid if we still hold
  // a reference of the ConnectionNode in our global list.
  //
  if(GSList *const link = g_slist_find(connection_list_, conn_node))
  {
    connection_list_ = g_slist_delete_link(connection_list_, link);
    return true;
  }

  return false;
}

/* Cleanup function to be called by the Gtk::Main destructor.  The elements
 * are removed prior to notification, in order to avoid invalid elements in
 * the container.
 */
// static
void GtkMainConnectionNode::list_notify_all()
{
  while(connection_list_ != 0)
  {
    GtkMainConnectionNode *const conn_node =
        static_cast<GtkMainConnectionNode*>(connection_list_->data);

    connection_list_ = g_slist_delete_link(connection_list_, connection_list_);

    // no need to search the list in notify().
    conn_node->has_destroy_notify_ = true;

    // conn_node gets destroyed from notify().
    notify(conn_node);
  }
}

} // anonymous namespace


namespace Gtk
{


#ifndef GTKMM_DISABLE_DEPRECATED


/**** Gtk::RunSig **********************************************************/

sigc::connection RunSig::connect(const RunSig::SlotType& slot)
{
  GtkMainConnectionNode *const conn_node = new GtkMainConnectionNode(slot);
  const sigc::connection connection(*conn_node->get_slot());

  // The callback will be invoked the next time gtk_main() is called.
  gtk_init_add(&RunSig::gtk_callback, conn_node);

  conn_node->install(0, 0, false); // there's no gtk_init_remove()
  return connection;
}

// static
gboolean RunSig::gtk_callback(gpointer data)
{
  GtkMainConnectionNode *const conn_node =
      static_cast<GtkMainConnectionNode*>(data);

  if(GtkMainConnectionNode::list_remove(conn_node))
  {
    try
    {
      // Recreate the specific SlotType from the generic slot_base.
      SlotType* pSlot = static_cast<SlotType*>(conn_node->get_slot());
      (*pSlot)();
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }

    // We don't need it anymore, since RunSig is a one-shot signal.
    GtkMainConnectionNode::destroy_notify_handler(conn_node);
  }

  return 0;
}

/**** Gtk::QuitSig *********************************************************/

sigc::connection QuitSig::connect(const QuitSig::SlotType& slot, guint main_level)
{
  GtkMainConnectionNode *const conn_node = new GtkMainConnectionNode(slot);
  const sigc::connection connection(*conn_node->get_slot());

  const guint conn_id = gtk_quit_add_full(
      main_level, &QuitSig::gtk_callback, 0 /* marshaller */,
      conn_node, &GtkMainConnectionNode::destroy_notify_handler);

  conn_node->install(conn_id, &gtk_quit_remove, true);
  return connection;
}

// static
gboolean QuitSig::gtk_callback(gpointer data)
{
  try
  {
    // Call the slot:
    GtkMainConnectionNode* node = static_cast<GtkMainConnectionNode*>(data);
    SlotType* pSlot = static_cast<SlotType*>(node->get_slot());
    (*pSlot)();
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }

  return 0;
}
#endif // GTKMM_DISABLE_DEPRECATED


/**** Gtk::KeySnooperSig ***************************************************/

sigc::connection KeySnooperSig::connect(const KeySnooperSig::SlotType& slot)
{
  GtkMainConnectionNode *const conn_node = new GtkMainConnectionNode(slot);
  const sigc::connection connection(*conn_node->get_slot());

  const guint conn_id = gtk_key_snooper_install(&KeySnooperSig::gtk_callback, conn_node);

  conn_node->install(conn_id, &gtk_key_snooper_remove, false);
  return connection;
}

// static
gint KeySnooperSig::gtk_callback(GtkWidget* widget, GdkEventKey* event, gpointer data)
{
  try
  {
    // Recreate the specific SlotType from the generic slot node.
    GtkMainConnectionNode* conn_node = static_cast<GtkMainConnectionNode*>(data);
    SlotType* pSlot = static_cast<SlotType*>(conn_node->get_slot());
    return (*pSlot)(Glib::wrap(widget), event);
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }

  return 0;
}


/**** Gtk::Main -- static data *********************************************/

#ifndef GTKMM_DISABLE_DEPRECATED

RunSig        Main::signal_run_;
QuitSig       Main::signal_quit_;
#endif // GTKMM_DISABLE_DEPRECATED


KeySnooperSig Main::signal_key_snooper_;
Main*         Main::instance_ = 0;


/**** Gtk::Main -- construction/destruction ********************************/

Main::Main(int& argc, char**& argv, bool set_locale)
{
  init(&argc, &argv, set_locale);
}

Main::Main(int* argc, char*** argv, bool set_locale)
{
  init(argc, argv, set_locale);
}

/*Main::Main(int* argc, char*** argv, const std::string& parameter_string, const Glib::ArrayHandle<const Glib::OptionEntry&>& entries, const std::string& translation_domain)
{
  init(argc, argv, parameter_string, entries, translation_domain);
}*/

// Default ctor only used by subclasses:
Main::Main()
{
  if(instance_ == 0)
  {
    init_gtkmm_internals();
    instance_ = this;
  }
  else
  {
    g_warning("Gtk::Main instantiated twice");
  }
}

Main::~Main()
{
  // A second Gtk::Main will produce a warning, but
  // Main::~Main would still run. So this prevents the crash.
  if(instance_ == this)
  {
    instance_ = 0;
    GtkMainConnectionNode::list_notify_all();

    // Release the gtkmm type registration tables,
    // allowing Main to be instantiated again:
    Glib::wrap_register_cleanup();
    Glib::Error::register_cleanup();
  }
}

// protected
void Main::init(int* argc, char*** argv, bool set_locale)
{
  if(instance_)
  {
    g_warning("Gtk::Main::init() called twice");
  }
  else
  {
    if(!set_locale)
      gtk_disable_setlocale();

    //TODO: Add support for gtk_init_check().
    gtk_init(argc, argv);

    init_gtkmm_internals();
    instance_ = this;
  }
}

Main::Main(int& argc, char**& argv, Glib::OptionContext& option_context)
{
  if(instance_)
  {
    g_warning("Gtk::Main::init() called twice");
  }
  else
  {
    init_gtkmm_internals();
    instance_ = this;

    //This reimplements some stuff from gtk_init_with_options(),
    //without calling check_setugid(), because that is not public API.

    add_gtk_option_group(option_context);

    option_context.parse(argc, argv);
  }
}

// This is a static method so that it can be used before Main is instantiated,
// for instance in Gnome::canvas_init().  But if you use this method, you
// _must_ have a Gtk::Main, so that Main::~Main() is called to clean this up
// later.  Of course I can't imagine any situation in which you wouldn't have
// a Gtk::Main.
//
void Main::init_gtkmm_internals()
{
  static bool init_done = false;

  if(!init_done)
  {
    Glib::init();
    Gio::init();

    // Populate the map of GTypes to C++ wrap_new() functions.
    Pango::wrap_init();
#ifdef GTKMM_ATKMM_ENABLED
    Atk::wrap_init();
#endif //GTKMM_ATKMM_ENABLED
    Gdk::wrap_init();
    Gtk::wrap_init();

    init_done = true;
  }
}

void Main::add_gtk_option_group(Glib::OptionContext& option_context, bool open_default_display)
{
  //Get the option group:
  Glib::OptionGroup gtkgroup( gtk_get_option_group(open_default_display) ); //Takes ownership of the GOptionGroup.

  //Give it to the option_context, which will also then own the underlying GOptionGroup, deleting it when necessary:
  option_context.add_group(gtkgroup);
}


/**** Gtk::Main -- static forwarder methods ********************************/

Main* Main::instance()
{
  return instance_;
}

void Main::run()
{
  instance_->run_impl();
}

void Main::run(Gtk::Window& window)
{
  window.show();
  window.signal_hide().connect(sigc::mem_fun(*instance_, &Main::on_window_hide));
  instance_->run_impl();
}

void Main::quit()
{
  instance_->quit_impl();
}

guint Main::level()
{
  return instance_->level_impl();
}

bool Main::iteration(bool blocking)
{
  return instance_->iteration_impl(blocking);
}

bool Main::events_pending()
{
  return instance_->events_pending_impl();
}


/**** Gtk::Main -- static signal accessors *********************************/

#ifndef GTKMM_DISABLE_DEPRECATED

RunSig& Main::signal_run()
{
  return signal_run_;
}

QuitSig& Main::signal_quit()
{
  return signal_quit_;
}
#endif // GTKMM_DISABLE_DEPRECATED


KeySnooperSig& Main::signal_key_snooper()
{
  return signal_key_snooper_;
}


/**** Gtk::Main -- protected virtuals **************************************/

void Main::run_impl()
{
  gtk_main();
}

void Main::quit_impl()
{
  gtk_main_quit();
}

guint Main::level_impl()
{
  return gtk_main_level();
}

bool Main::iteration_impl(bool blocking)
{
  return gtk_main_iteration_do(blocking);
}

bool Main::events_pending_impl()
{
  return gtk_events_pending();
}

void Main::on_window_hide()
{
  quit_impl();
}

} /* namespace Gtk */


namespace
{
} // anonymous namespace


