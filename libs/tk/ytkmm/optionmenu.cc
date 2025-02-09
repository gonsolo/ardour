// Generated by gmmproc 2.45.3 -- DO NOT MODIFY!

#undef GTK_DISABLE_DEPRECATED
 
#ifndef GTKMM_DISABLE_DEPRECATED


#include <glibmm.h>

#include <ytkmm/optionmenu.h>
#include <ytkmm/private/optionmenu_p.h>


// -*- c++ -*-
/* $Id: optionmenu.ccg,v 1.6 2004/04/17 14:44:45 murrayc Exp $ */

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

#include <ytkmm/menu.h>
#include <ytkmm/window.h>
#include <ytk/ytk.h>

namespace Gtk
{


OptionMenu::OptionMenu()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::Button(Glib::ConstructParams(optionmenu_class_.init()))
{
  // Connect to the signal instead of overriding the on_hierarchy_changed()
  // method because invocation of C++ default signal handlers is skipped
  // for gtkmmproc-generated classes (a gtkmm-wide optimization).

  signal_realize().connect(sigc::mem_fun(*this, &OptionMenu::init_accels_handler_));
}

OptionMenu::~OptionMenu()
{
  //GTKMM_LIFECYCLE
  //Remove the menu so that the Menu forgets about this OptionMenu.
  //Normally the GtkOptionMenu just destroys the Menu (see gtk_option_menu_destroy),
  //but we prevent premature destruction in general for all widgets,
  //so the Menu would survive and remember a dead GtkOptionMenu.
  remove_menu();

  destroy_();
}

void OptionMenu::init_accels_handler_()
{
  if(gobj())
  {
    Window *const toplevel = dynamic_cast<Window*>(get_toplevel());
    if(toplevel && get_menu())
    {
      get_menu()->accelerate(*toplevel);
    }
  }
}

} /* namespace Gtk */


namespace
{


static const Glib::SignalProxyInfo OptionMenu_signal_changed_info =
{
  "changed",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


namespace Glib
{

Gtk::OptionMenu* wrap(GtkOptionMenu* object, bool take_copy)
{
  return dynamic_cast<Gtk::OptionMenu *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& OptionMenu_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &OptionMenu_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_option_menu_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void OptionMenu_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


  klass->changed = &changed_callback;
}


void OptionMenu_Class::changed_callback(GtkOptionMenu* self)
{
  Glib::ObjectBase *const obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    CppObjectType *const obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_changed();
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->changed)
    (*base->changed)(self);
}


Glib::ObjectBase* OptionMenu_Class::wrap_new(GObject* o)
{
  return manage(new OptionMenu((GtkOptionMenu*)(o)));

}


/* The implementation: */

OptionMenu::OptionMenu(const Glib::ConstructParams& construct_params)
:
  Gtk::Button(construct_params)
{
  }

OptionMenu::OptionMenu(GtkOptionMenu* castitem)
:
  Gtk::Button((GtkButton*)(castitem))
{
  }

OptionMenu::CppClassType OptionMenu::optionmenu_class_; // initialize static member

GType OptionMenu::get_type()
{
  return optionmenu_class_.init().get_type();
}


GType OptionMenu::get_base_type()
{
  return gtk_option_menu_get_type();
}


void OptionMenu::set_menu(Menu& menu)
{
  gtk_option_menu_set_menu(gobj(), (menu).Gtk::Widget::gobj());
}

Menu* OptionMenu::get_menu()
{
  return Glib::wrap((GtkMenu*)(gtk_option_menu_get_menu(gobj())));
}

const Menu* OptionMenu::get_menu() const
{
  return const_cast<OptionMenu*>(this)->get_menu();
}

void OptionMenu::remove_menu()
{
  gtk_option_menu_remove_menu(gobj());
}

int OptionMenu::get_history() const
{
  return gtk_option_menu_get_history(const_cast<GtkOptionMenu*>(gobj()));
}

void OptionMenu::set_history(guint index)
{
  gtk_option_menu_set_history(gobj(), index);
}


Glib::SignalProxy0< void > OptionMenu::signal_changed()
{
  return Glib::SignalProxy0< void >(this, &OptionMenu_signal_changed_info);
}


void Gtk::OptionMenu::on_changed()
{
  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->changed)
    (*base->changed)(gobj());
}


} // namespace Gtk

#endif // GTKMM_DISABLE_DEPRECATED


