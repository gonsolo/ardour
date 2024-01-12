// -*- c++ -*-
// Generated by gmmproc 2.45.3 -- DO NOT MODIFY!
#ifndef _GTKMM_PLUG_H
#define _GTKMM_PLUG_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* $Id: plug.hg,v 1.2 2005/01/25 16:16:33 murrayc Exp $ */

/* Copyright (C) 1998-2002 The gtkmm Development Team
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

#include <gtkmm/window.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkPlug GtkPlug;
typedef struct _GtkPlugClass GtkPlugClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class Plug_Class; } // namespace Gtk
namespace Gtk
{


class Plug : public Window
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Plug CppObjectType;
  typedef Plug_Class CppClassType;
  typedef GtkPlug BaseObjectType;
  typedef GtkPlugClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~Plug();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class Plug_Class;
  static CppClassType plug_class_;

  // noncopyable
  Plug(const Plug&);
  Plug& operator=(const Plug&);

protected:
  explicit Plug(const Glib::ConstructParams& construct_params);
  explicit Plug(GtkPlug* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkPlug*       gobj()       { return reinterpret_cast<GtkPlug*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkPlug* gobj() const { return reinterpret_cast<GtkPlug*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_embedded().
  virtual void on_embedded();


private:

  
  //gtkmmproc error: _gtk_plug_add_to_socket : ignored method defs lookup failed//gtkmmproc error: _gtk_plug_remove_from_socket : ignored method defs lookup failed
  //This is not available on Win32.
//This source file will not be compiled on Win32,
//and no class defined in it will be registered by wrap_init().

public:
  Plug();
  explicit Plug(GdkNativeWindow socket_id);
  Plug(const Glib::RefPtr<Gdk::Display>& display, GdkNativeWindow socket_id);

  
  /** Gets the window ID of a Gtk::Plug widget, which can then
   * be used to embed this window inside another window, for
   * instance with Gtk::Socket::add_id().
   * 
   * @return The window ID for the plug.
   */
  GdkNativeWindow get_id() const;

  
  /** Determines whether the plug is embedded in a socket.
   * 
   * @newin{2,14}
   * 
   * @return <tt>true</tt> if the plug is embedded in a socket.
   */
  bool get_embedded() const;

  
  /** Retrieves the socket the plug is embedded in.
   * 
   * @newin{2,14}
   * 
   * @return The window of the socket, or <tt>0</tt>.
   */
  Glib::RefPtr<Gdk::Window> get_socket_window();
  
  /** Retrieves the socket the plug is embedded in.
   * 
   * @newin{2,14}
   * 
   * @return The window of the socket, or <tt>0</tt>.
   */
  Glib::RefPtr<const Gdk::Window> get_socket_window() const;

  /** Whether or not the plug is embedded.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_embedded() const;


  /** The window of the socket the plug is embedded in.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Window> > property_socket_window() const;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%embedded()</tt>
   *
   */

  Glib::SignalProxy0< void > signal_embedded();


};

} /* namespace Gtk */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::Plug
   */
  Gtk::Plug* wrap(GtkPlug* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_PLUG_H */

