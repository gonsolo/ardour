// Generated by gmmproc 2.45.3 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gtkmm/radiomenuitem.h>
#include <gtkmm/private/radiomenuitem_p.h>


// -*- c++ -*-
/* $Id: radiomenuitem.ccg,v 1.2 2003/10/28 17:12:27 murrayc Exp $ */

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

#include <gtkmm/misc.h>
#include <gtkmm/label.h>
#include <gtk/gtk.h>

typedef Gtk::RadioMenuItem::Group Group; //So that the generate get_group return type is parsed.

namespace Gtk
{

RadioMenuItem::RadioMenuItem(Group& groupx)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::CheckMenuItem(Glib::ConstructParams(radiomenuitem_class_.init()))
{
  groupx.add(*this);
}

RadioMenuItem::RadioMenuItem(Group& groupx, const Glib::ustring &label, bool mnemonic)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::CheckMenuItem(Glib::ConstructParams(radiomenuitem_class_.init()))
{
  groupx.add(*this);
  add_accel_label(label, mnemonic);
}

void RadioMenuItem::set_group(Group& group)
{
  gtk_radio_menu_item_set_group(gobj(), group.group_);

   //The group will be updated, ready for use with the next radiomenuitem:
  group = get_group();
}

void RadioMenuItem::reset_group()
{
  gtk_radio_menu_item_set_group(gobj(), 0);
}


} // namespace Gtk


namespace
{


static const Glib::SignalProxyInfo RadioMenuItem_signal_group_changed_info =
{
  "group_changed",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


namespace Glib
{

Gtk::RadioMenuItem* wrap(GtkRadioMenuItem* object, bool take_copy)
{
  return dynamic_cast<Gtk::RadioMenuItem *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& RadioMenuItem_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &RadioMenuItem_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_radio_menu_item_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void RadioMenuItem_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


  klass->group_changed = &group_changed_callback;
}


void RadioMenuItem_Class::group_changed_callback(GtkRadioMenuItem* self)
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
        obj->on_group_changed();
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
  if(base && base->group_changed)
    (*base->group_changed)(self);
}


Glib::ObjectBase* RadioMenuItem_Class::wrap_new(GObject* o)
{
  return manage(new RadioMenuItem((GtkRadioMenuItem*)(o)));

}


/* The implementation: */

RadioMenuItem::RadioMenuItem(const Glib::ConstructParams& construct_params)
:
  Gtk::CheckMenuItem(construct_params)
{
  }

RadioMenuItem::RadioMenuItem(GtkRadioMenuItem* castitem)
:
  Gtk::CheckMenuItem((GtkCheckMenuItem*)(castitem))
{
  }

RadioMenuItem::~RadioMenuItem()
{
  destroy_();
}

RadioMenuItem::CppClassType RadioMenuItem::radiomenuitem_class_; // initialize static member

GType RadioMenuItem::get_type()
{
  return radiomenuitem_class_.init().get_type();
}


GType RadioMenuItem::get_base_type()
{
  return gtk_radio_menu_item_get_type();
}


Group RadioMenuItem::get_group()
{
  return Group(gtk_radio_menu_item_get_group(gobj()));
}


Glib::SignalProxy0< void > RadioMenuItem::signal_group_changed()
{
  return Glib::SignalProxy0< void >(this, &RadioMenuItem_signal_group_changed_info);
}


void Gtk::RadioMenuItem::on_group_changed()
{
  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->group_changed)
    (*base->group_changed)(gobj());
}


} // namespace Gtk


