// Generated by gmmproc 2.45.3 -- DO NOT MODIFY!


#include <glibmm.h>

#include <ytkmm/accellabel.h>
#include <ytkmm/private/accellabel_p.h>


// -*- c++ -*-
/* $Id: accellabel.ccg,v 1.2 2003/05/10 07:16:52 murrayc Exp $ */

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

#include <ytk/ytk.h>
#include <glibmm/wrap.h>

namespace Gtk
{

AccelLabel::AccelLabel(const Glib::ustring& label, bool mnemonic)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::Label(Glib::ConstructParams(accellabel_class_.init()))
{
  if(mnemonic)
    set_text_with_mnemonic(label);
  else
    set_text(label);
}

void AccelLabel::unset_accel_widget()
{
  //Not documented, at the moment, but this is what the source does:
  gtk_accel_label_set_accel_widget(gobj(), 0);
}

} // namespace Gtk


namespace
{
} // anonymous namespace


namespace Glib
{

Gtk::AccelLabel* wrap(GtkAccelLabel* object, bool take_copy)
{
  return dynamic_cast<Gtk::AccelLabel *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& AccelLabel_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &AccelLabel_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_accel_label_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void AccelLabel_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* AccelLabel_Class::wrap_new(GObject* o)
{
  return manage(new AccelLabel((GtkAccelLabel*)(o)));

}


/* The implementation: */

AccelLabel::AccelLabel(const Glib::ConstructParams& construct_params)
:
  Gtk::Label(construct_params)
{
  }

AccelLabel::AccelLabel(GtkAccelLabel* castitem)
:
  Gtk::Label((GtkLabel*)(castitem))
{
  }

AccelLabel::~AccelLabel()
{
  destroy_();
}

AccelLabel::CppClassType AccelLabel::accellabel_class_; // initialize static member

GType AccelLabel::get_type()
{
  return accellabel_class_.init().get_type();
}


GType AccelLabel::get_base_type()
{
  return gtk_accel_label_get_type();
}


AccelLabel::AccelLabel()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::Label(Glib::ConstructParams(accellabel_class_.init()))
{
  

}

void AccelLabel::set_accel_widget(const Widget& accel_widget)
{
  gtk_accel_label_set_accel_widget(gobj(), const_cast<GtkWidget*>((accel_widget).gobj()));
}

Widget* AccelLabel::get_accel_widget()
{
  return Glib::wrap(gtk_accel_label_get_accel_widget(gobj()));
}

const Widget* AccelLabel::get_accel_widget() const
{
  return const_cast<AccelLabel*>(this)->get_accel_widget();
}

guint AccelLabel::get_accel_width() const
{
  return gtk_accel_label_get_accel_width(const_cast<GtkAccelLabel*>(gobj()));
}

bool AccelLabel::refetch()
{
  return gtk_accel_label_refetch(gobj());
}


Glib::PropertyProxy< Gtk::Widget* > AccelLabel::property_accel_widget() 
{
  return Glib::PropertyProxy< Gtk::Widget* >(this, "accel-widget");
}

Glib::PropertyProxy_ReadOnly< Gtk::Widget* > AccelLabel::property_accel_widget() const
{
  return Glib::PropertyProxy_ReadOnly< Gtk::Widget* >(this, "accel-widget");
}


} // namespace Gtk


