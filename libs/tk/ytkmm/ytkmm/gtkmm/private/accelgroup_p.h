// -*- c++ -*-
// Generated by gmmproc 2.45.3 -- DO NOT MODIFY!
#ifndef _GTKMM_ACCELGROUP_P_H
#define _GTKMM_ACCELGROUP_P_H


#include <glibmm/private/object_p.h>

#include <glibmm/class.h>

namespace Gtk
{

class AccelGroup_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef AccelGroup CppObjectType;
  typedef GtkAccelGroup BaseObjectType;
  typedef GtkAccelGroupClass BaseClassType;
  typedef Glib::Object_Class CppClassParent;
  typedef GObjectClass BaseClassParent;

  friend class AccelGroup;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static void accel_changed_callback(GtkAccelGroup* self, guint p0, GdkModifierType p1, GClosure* p2);

  //Callbacks (virtual functions):
};


} // namespace Gtk


#endif /* _GTKMM_ACCELGROUP_P_H */

