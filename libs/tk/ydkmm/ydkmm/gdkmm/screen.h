// -*- c++ -*-
// Generated by gmmproc 2.45.3 -- DO NOT MODIFY!
#ifndef _GDKMM_SCREEN_H
#define _GDKMM_SCREEN_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* $Id: screen.hg,v 1.8 2006/06/10 15:26:24 murrayc Exp $ */

/* screen.h
 *
 * Copyright (C) 1998-2002 The gtkmm Development Team
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

//#include <gdkmm/visual.h>
//#include <gdkmm/window.h>
#include <gdkmm/region.h> //Just to solve GDK_DISABLE_DEPRECATED problems when this header is included from elsewhere.
#include <gdkmm/rectangle.h>
#include <glibmm/object.h>
#include <cairomm/fontoptions.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GdkScreen GdkScreen;
typedef struct _GdkScreenClass GdkScreenClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class Screen_Class; } // namespace Gdk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{

class Display;
class Colormap;
class Visual;
class Window;

/** Object representing a physical screen
 * Gdk::Screen objects are the GDK representation of a physical screen. It is used throughout GDK and GTK+ to specify
 * which screen the top level windows are to be displayed on. It is also used to query the screen specification and
 * default settings such as the default colormap (get_default_colormap()), the screen width (get_width()), etc.
 * Note that a screen may consist of multiple monitors which are merged to form a large screen area.
 */

class Screen : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef Screen CppObjectType;
  typedef Screen_Class CppClassType;
  typedef GdkScreen BaseObjectType;
  typedef GdkScreenClass BaseClassType;

private:  friend class Screen_Class;
  static CppClassType screen_class_;

private:
  // noncopyable
  Screen(const Screen&);
  Screen& operator=(const Screen&);

protected:
  explicit Screen(const Glib::ConstructParams& construct_params);
  explicit Screen(GdkScreen* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~Screen();

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GdkScreen*       gobj()       { return reinterpret_cast<GdkScreen*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GdkScreen* gobj() const { return reinterpret_cast<GdkScreen*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GdkScreen* gobj_copy();

private:

protected:

public:
  
  /** Gets the default colormap for @a screen.
   * 
   * @newin{2,2}
   * 
   * @return The default Gdk::Colormap.
   */
  Glib::RefPtr<Colormap> get_default_colormap();
  
  /** Gets the default colormap for @a screen.
   * 
   * @newin{2,2}
   * 
   * @return The default Gdk::Colormap.
   */
  Glib::RefPtr<const Colormap> get_default_colormap() const;

  
  /** Sets the default @a colormap for @a screen.
   * 
   * @newin{2,2}
   * 
   * @param colormap A Gdk::Colormap.
   */
  void set_default_colormap(const Glib::RefPtr<const Colormap>& colormap);
  
  /** Gets the system's default colormap for @a screen
   * 
   * @newin{2,2}
   * 
   * @return The default colormap for @a screen.
   */
  Glib::RefPtr<Colormap> get_system_colormap();
  
  /** Gets the system's default colormap for @a screen
   * 
   * @newin{2,2}
   * 
   * @return The default colormap for @a screen.
   */
  Glib::RefPtr<const Colormap> get_system_colormap() const;

  
  /** Get the system's default visual for @a screen.
   * This is the visual for the root window of the display.
   * The return value should not be freed.
   * 
   * @newin{2,2}
   * 
   * @return The system visual.
   */
  Glib::RefPtr<Visual> get_system_visual();
  
  /** Get the system's default visual for @a screen.
   * This is the visual for the root window of the display.
   * The return value should not be freed.
   * 
   * @newin{2,2}
   * 
   * @return The system visual.
   */
  Glib::RefPtr<const Visual> get_system_visual() const;

  
  /** Gets the preferred colormap for rendering image data on @a screen.
   * Not a very useful function; historically, GDK could only render RGB
   * image data to one colormap and visual, but in the current version
   * it can render to any colormap and visual. So there's no need to
   * call this function.
   * 
   * @newin{2,2}
   * 
   * Deprecated: 2.22: Use get_system_colormap()
   * 
   * @return The preferred colormap.
   */
  Glib::RefPtr<Colormap> get_rgb_colormap();
  
  /** Gets the preferred colormap for rendering image data on @a screen.
   * Not a very useful function; historically, GDK could only render RGB
   * image data to one colormap and visual, but in the current version
   * it can render to any colormap and visual. So there's no need to
   * call this function.
   * 
   * @newin{2,2}
   * 
   * Deprecated: 2.22: Use get_system_colormap()
   * 
   * @return The preferred colormap.
   */
  Glib::RefPtr<const Colormap> get_rgb_colormap() const;

  
  /** Gets a "preferred visual" chosen by GdkRGB for rendering image data
   * on @a screen. In previous versions of
   * GDK, this was the only visual GdkRGB could use for rendering. In
   * current versions, it's simply the visual GdkRGB would have chosen as 
   * the optimal one in those previous versions. GdkRGB can now render to 
   * drawables with any visual.
   * 
   * @newin{2,2}
   * 
   * Deprecated: 2.22: Use get_system_visual()
   * 
   * @return The Gdk::Visual chosen by GdkRGB.
   */
  Glib::RefPtr<Visual> get_rgb_visual();
  
  /** Gets a "preferred visual" chosen by GdkRGB for rendering image data
   * on @a screen. In previous versions of
   * GDK, this was the only visual GdkRGB could use for rendering. In
   * current versions, it's simply the visual GdkRGB would have chosen as 
   * the optimal one in those previous versions. GdkRGB can now render to 
   * drawables with any visual.
   * 
   * @newin{2,2}
   * 
   * Deprecated: 2.22: Use get_system_visual()
   * 
   * @return The Gdk::Visual chosen by GdkRGB.
   */
  Glib::RefPtr<const Visual> get_rgb_visual() const;

  
  /** Gets a colormap to use for creating windows or pixmaps with an
   * alpha channel. The windowing system on which GTK+ is running
   * may not support this capability, in which case <tt>0</tt> will
   * be returned. Even if a non-<tt>0</tt> value is returned, its
   * possible that the window's alpha channel won't be honored
   * when displaying the window on the screen: in particular, for
   * X an appropriate windowing manager and compositing manager
   * must be running to provide appropriate display.
   * 
   * This functionality is not implemented in the Windows backend.
   * 
   * For setting an overall opacity for a top-level window, see
   * Gdk::Window::set_opacity().
   * 
   * @newin{2,8}
   * 
   * @return A colormap to use for windows with
   * an alpha channel or <tt>0</tt> if the capability is not available.
   */
  Glib::RefPtr<Colormap> get_rgba_colormap();
  
  /** Gets a colormap to use for creating windows or pixmaps with an
   * alpha channel. The windowing system on which GTK+ is running
   * may not support this capability, in which case <tt>0</tt> will
   * be returned. Even if a non-<tt>0</tt> value is returned, its
   * possible that the window's alpha channel won't be honored
   * when displaying the window on the screen: in particular, for
   * X an appropriate windowing manager and compositing manager
   * must be running to provide appropriate display.
   * 
   * This functionality is not implemented in the Windows backend.
   * 
   * For setting an overall opacity for a top-level window, see
   * Gdk::Window::set_opacity().
   * 
   * @newin{2,8}
   * 
   * @return A colormap to use for windows with
   * an alpha channel or <tt>0</tt> if the capability is not available.
   */
  Glib::RefPtr<const Colormap> get_rgba_colormap() const;

  
  /** Gets a visual to use for creating windows or pixmaps with an
   * alpha channel. See the docs for get_rgba_colormap()
   * for caveats.
   * 
   * @newin{2,8}
   * 
   * @return A visual to use for windows with an
   * alpha channel or <tt>0</tt> if the capability is not available.
   */
  Glib::RefPtr<Visual> get_rgba_visual();
  
  /** Gets a visual to use for creating windows or pixmaps with an
   * alpha channel. See the docs for get_rgba_colormap()
   * for caveats.
   * 
   * @newin{2,8}
   * 
   * @return A visual to use for windows with an
   * alpha channel or <tt>0</tt> if the capability is not available.
   */
  Glib::RefPtr<const Visual> get_rgba_visual() const;

  
  /** Returns whether windows with an RGBA visual can reasonably
   * be expected to have their alpha channel drawn correctly on
   * the screen.
   * 
   * On X11 this function returns whether a compositing manager is
   * compositing @a screen.
   * 
   * @newin{2,10}
   * 
   * @return Whether windows with RGBA visuals can reasonably be
   * expected to have their alpha channels drawn correctly on the screen.
   */
  bool is_composited() const;

  
  /** Gets the root window of @a screen.
   * 
   * @newin{2,2}
   * 
   * @return The root window.
   */
  Glib::RefPtr<Window> get_root_window();
  
  /** Gets the root window of @a screen.
   * 
   * @newin{2,2}
   * 
   * @return The root window.
   */
  Glib::RefPtr<const Window> get_root_window() const;

  
  /** Gets the display to which the @a screen belongs.
   * 
   * @newin{2,2}
   * 
   * @return The display to which @a screen belongs.
   */
  Glib::RefPtr<Display> get_display();
  
  /** Gets the display to which the @a screen belongs.
   * 
   * @newin{2,2}
   * 
   * @return The display to which @a screen belongs.
   */
  Glib::RefPtr<const Display> get_display() const;

  
  /** Gets the index of @a screen among the screens in the display
   * to which it belongs. (See get_display())
   * 
   * @newin{2,2}
   * 
   * @return The index.
   */
  int get_number() const;
  
  /** Gets the width of @a screen in pixels
   * 
   * @newin{2,2}
   * 
   * @return The width of @a screen in pixels.
   */
  int get_width() const;
  
  /** Gets the height of @a screen in pixels
   * 
   * @newin{2,2}
   * 
   * @return The height of @a screen in pixels.
   */
  int get_height() const;
  
  /** Gets the width of @a screen in millimeters. 
   * Note that on some X servers this value will not be correct.
   * 
   * @newin{2,2}
   * 
   * @return The width of @a screen in millimeters.
   */
  int get_width_mm() const;
  
  /** Returns the height of @a screen in millimeters. 
   * Note that on some X servers this value will not be correct.
   * 
   * @newin{2,2}
   * 
   * @return The heigth of @a screen in millimeters.
   */
  int get_height_mm() const;

 
  /** Lists the available visuals for the specified @a screen.
   * A visual describes a hardware image data format.
   * For example, a visual might support 24-bit color, or 8-bit color,
   * and might expect pixels to be in a certain format.
   * @newin{2,2}
   * 
   * @return A list of visuals.
   */
  Glib::ListHandle< Glib::RefPtr<Visual> > list_visuals();

 
  /** Obtains a list of all toplevel windows known to GDK on the screen @a screen.
   * A toplevel window is a child of the root window (see
   * gdk_get_default_root_window()).
   * @newin{2,2}
   * 
   * @return List of toplevel windows.
   */
  Glib::ListHandle< Glib::RefPtr<Window> > get_toplevel_windows();

  
  /** Determines the name to pass to Gdk::Display::open() to get
   * a Gdk::Display with this screen as the default screen.
   * 
   * @newin{2,2}
   * 
   * @return The name.
   */
  Glib::ustring make_display_name();

  
  /** Returns the number of monitors which @a screen consists of.
   * 
   * @newin{2,2}
   * 
   * @return Number of monitors which @a screen consists of.
   */
  int get_n_monitors() const;
  
  /** Gets the primary monitor for @a screen.  The primary monitor
   * is considered the monitor where the 'main desktop' lives.
   * While normal application windows typically allow the window
   * manager to place the windows, specialized desktop applications
   * such as panels should place themselves on the primary monitor.
   * 
   * If no primary monitor is configured by the user, the return value
   * will be 0, defaulting to the first monitor.
   * 
   * @newin{2,20}
   * 
   * @return An integer index for the primary monitor, or 0 if none is configured.
   */
  int get_primary_monitor() const;
  
  /** Retrieves the Gdk::Rectangle representing the size and position of
   * the individual monitor within the entire screen area.
   * 
   * Note that the size of the entire screen area can be retrieved via
   * get_width() and get_height().
   * 
   * @newin{2,2}
   * 
   * @param monitor_num The monitor number, between 0 and gdk_screen_get_n_monitors (screen).
   * @param dest A Gdk::Rectangle to be filled with the monitor geometry.
   */
  void get_monitor_geometry(int monitor_num, Rectangle& dest) const;
  
  /** Returns the monitor number in which the point ( @a x, @a y) is located.
   * 
   * @newin{2,2}
   * 
   * @param x The x coordinate in the virtual screen.
   * @param y The y coordinate in the virtual screen.
   * @return The monitor number in which the point ( @a x, @a y) lies, or
   * a monitor close to ( @a x, @a y) if the point is not in any monitor.
   */
  int get_monitor_at_point(int x, int y) const;
  
  /** Returns the number of the monitor in which the largest area of the 
   * bounding rectangle of @a window resides.
   * 
   * @newin{2,2}
   * 
   * @param window A Gdk::Window.
   * @return The monitor number in which most of @a window is located,
   * or if @a window does not intersect any monitors, a monitor,
   * close to @a window.
   */
  int get_monitor_at_window(const Glib::RefPtr<Window>& window) const;

  
  /** Gets the width in millimeters of the specified monitor, if available.
   * 
   * @newin{2,14}
   * 
   * @param monitor_num Number of the monitor, between 0 and gdk_screen_get_n_monitors (screen).
   * @return The width of the monitor, or -1 if not available.
   */
  int get_monitor_width_mm(int monitor_num) const;
  
  /** Gets the height in millimeters of the specified monitor.
   * 
   * @newin{2,14}
   * 
   * @param monitor_num Number of the monitor, between 0 and gdk_screen_get_n_monitors (screen).
   * @return The height of the monitor, or -1 if not available.
   */
  int get_monitor_height_mm(int monitor_num) const;
  
  /** Returns the output name of the specified monitor.
   * Usually something like VGA, DVI, or TV, not the actual
   * product name of the display device.
   * 
   * @newin{2,14}
   * 
   * @param monitor_num Number of the monitor, between 0 and gdk_screen_get_n_monitors (screen).
   * @return A newly-allocated string containing the name of the monitor,
   * or <tt>0</tt> if the name cannot be determined.
   */
  Glib::ustring get_monitor_plug_name(int monitor_num) const;

  
  /** On X11, sends an X ClientMessage event to all toplevel windows on
   *  @a screen. 
   * 
   * Toplevel windows are determined by checking for the WM_STATE property, 
   * as described in the Inter-Client Communication Conventions Manual (ICCCM).
   * If no windows are found with the WM_STATE property set, the message is 
   * sent to all children of the root window.
   * 
   * On Windows, broadcasts a message registered with the name
   * GDK_WIN32_CLIENT_MESSAGE to all top-level windows. The amount of
   * data is limited to one long, i.e. four bytes.
   * 
   * @newin{2,2}
   * 
   * @param event The Gdk::Event.
   */
  void broadcast_client_message(GdkEvent* event);

  
  /** Gets the default screen for the default display. (See
   * Gdk::Display::get_default()).
   * 
   * @newin{2,2}
   * 
   * @return A Gdk::Screen, or <tt>0</tt> if there is no default display.
   */
  static Glib::RefPtr<Screen> get_default();

  template <class ValueType>
  bool get_setting(const Glib::ustring& name, ValueType& value) const;
  

  /** Sets the default font options for the screen. These
   * options will be set on any Pango::Context's newly created
   * with gdk_pango_context_get_for_screen(). Changing the
   * default set of font options does not affect contexts that
   * have already been created.
   * 
   * @newin{2,10}
   * 
   * @param options A #cairo_font_options_t, or <tt>0</tt> to unset any
   * previously set default font options.
   */
  void set_font_options(const Cairo::FontOptions& options);

  // Note: This returns a const, so we assume that we must copy it:
   

  /** Gets any options previously set with set_font_options().
   * 
   * @newin{2,10}
   * 
   * @return The current font options, or <tt>0</tt> if no default
   * font options have been set.
   */
  Cairo::FontOptions get_font_options() const;

  
  /** Sets the resolution for font handling on the screen. This is a
   * scale factor between points specified in a Pango::FontDescription
   * and cairo units. The default value is 96, meaning that a 10 point
   * font will be 13 units high. (10 * 96. / 72. = 13.3).
   * 
   * @newin{2,10}
   * 
   * @param dpi The resolution in "dots per inch". (Physical inches aren't actually
   * involved; the terminology is conventional.).
   */
  void set_resolution(double dpi);
  
  /** Gets the resolution for font handling on the screen; see
   * set_resolution() for full details.
   * 
   * @newin{2,10}
   * 
   * @return The current resolution, or -1 if no resolution
   * has been set.
   */
  double get_resolution() const;

  
  /** Returns the screen's currently active window.
   * 
   * On X11, this is done by inspecting the _NET_ACTIVE_WINDOW property
   * on the root window, as described in the Extended Window
   * Manager Hints. If there is no currently currently active
   * window, or the window manager does not support the
   * _NET_ACTIVE_WINDOW hint, this function returns <tt>0</tt>.
   * 
   * On other platforms, this function may return <tt>0</tt>, depending on whether
   * it is implementable on that platform.
   * 
   * The returned window should be unrefed using Glib::object_unref() when
   * no longer needed.
   * 
   * @newin{2,10}
   * 
   * @return The currently active window, or <tt>0</tt>.
   */
  Glib::RefPtr<Gdk::Window> get_active_window();
  
  /** Returns the screen's currently active window.
   * 
   * On X11, this is done by inspecting the _NET_ACTIVE_WINDOW property
   * on the root window, as described in the Extended Window
   * Manager Hints. If there is no currently currently active
   * window, or the window manager does not support the
   * _NET_ACTIVE_WINDOW hint, this function returns <tt>0</tt>.
   * 
   * On other platforms, this function may return <tt>0</tt>, depending on whether
   * it is implementable on that platform.
   * 
   * The returned window should be unrefed using Glib::object_unref() when
   * no longer needed.
   * 
   * @newin{2,10}
   * 
   * @return The currently active window, or <tt>0</tt>.
   */
  Glib::RefPtr<const Gdk::Window> get_active_window() const;

 
  /** Returns a List of Gdk::Window<!-- -->s representing the current
   * window stack.
   * 
   * On X11, this is done by inspecting the _NET_CLIENT_LIST_STACKING
   * property on the root window, as described in the Extended Window
   * Manager Hints. If the window manager does not support the
   * _NET_CLIENT_LIST_STACKING hint, this function returns <tt>0</tt>.
   * 
   * On other platforms, this function may return <tt>0</tt>, depending on whether
   * it is implementable on that platform.
   * 
   * The returned list is newly allocated and owns references to the
   * windows it contains, so it should be freed using Glib::list_free() and
   * its windows unrefed using Glib::object_unref() when no longer needed.
   * 
   * @newin{2,10}
   * 
   * @return A list of Gdk::Window<!-- -->s for the current window stack,
   * or <tt>0</tt>.
   */
  Glib::ListHandle< Glib::RefPtr<Window> > get_window_stack();

  
  /** The size_changed signal is emitted when the pixel width or
   * height of a screen changes.
   *
   * @par Slot Prototype:
   * <tt>void on_my_%size_changed()</tt>
   *
   */

  Glib::SignalProxy0< void > signal_size_changed();

  
  //TODO: Remove no_default_handler when we can break ABI:
  
  /**
   * @par Slot Prototype:
   * <tt>void on_my_%composited_changed()</tt>
   *
   */

  Glib::SignalProxy0< void > signal_composited_changed();

  
  /**
   * @par Slot Prototype:
   * <tt>void on_my_%monitors_changed()</tt>
   *
   */

  Glib::SignalProxy0< void > signal_monitors_changed();

  /** The default font options for the screen.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< Cairo::FontOptions > property_font_options() ;

/** The default font options for the screen.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Cairo::FontOptions > property_font_options() const;

  /** The resolution for fonts on the screen.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< double > property_resolution() ;

/** The resolution for fonts on the screen.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< double > property_resolution() const;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_size_changed().
  virtual void on_size_changed();


};

template <class ValueType>
bool Screen::get_setting(const Glib::ustring& name, ValueType& value) const
{
  Glib::Value<ValueType> glibmmvalue;
  glibmmvalue.init(Glib::Value<ValueType>::value_type());

  gboolean result = gdk_screen_get_setting(const_cast<GdkScreen*>(gobj()), name.c_str(), glibmmvalue.gobj());

  value = glibmmvalue.get();
  return result;
}

} /* namespace Gdk */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gdk::Screen
   */
  Glib::RefPtr<Gdk::Screen> wrap(GdkScreen* object, bool take_copy = false);
}


#endif /* _GDKMM_SCREEN_H */

