// Generated by gmmproc 2.45.3 -- DO NOT MODIFY!


#include <glibmm.h>

#include <ytkmm/invisible.h>
#include <ytkmm/private/invisible_p.h>


// -*- c++ -*-
/* $Id: invisible.ccg,v 1.1 2003/01/21 13:40:27 murrayc Exp $ */

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

namespace Gtk
{


}


namespace
{
} // anonymous namespace


namespace Glib
{

Gtk::Invisible* wrap(GtkInvisible* object, bool take_copy)
{
  return dynamic_cast<Gtk::Invisible *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& Invisible_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Invisible_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_invisible_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void Invisible_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* Invisible_Class::wrap_new(GObject* o)
{
  return manage(new Invisible((GtkInvisible*)(o)));

}


/* The implementation: */

Invisible::Invisible(const Glib::ConstructParams& construct_params)
:
  Gtk::Widget(construct_params)
{
  }

Invisible::Invisible(GtkInvisible* castitem)
:
  Gtk::Widget((GtkWidget*)(castitem))
{
  }

Invisible::~Invisible()
{
  destroy_();
}

Invisible::CppClassType Invisible::invisible_class_; // initialize static member

GType Invisible::get_type()
{
  return invisible_class_.init().get_type();
}


GType Invisible::get_base_type()
{
  return gtk_invisible_get_type();
}


Invisible::Invisible()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::Widget(Glib::ConstructParams(invisible_class_.init()))
{
  

}

Invisible::Invisible(const Glib::RefPtr<Gdk::Screen>& screen)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::Widget(Glib::ConstructParams(invisible_class_.init(), "screen", Glib::unwrap(screen), static_cast<char*>(0)))
{
  

}

Glib::RefPtr<Gdk::Screen> Invisible::get_screen()
{
  Glib::RefPtr<Gdk::Screen> retvalue = Glib::wrap(gtk_invisible_get_screen(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Gdk::Screen> Invisible::get_screen() const
{
  return const_cast<Invisible*>(this)->get_screen();
}

void Invisible::set_screen(const Glib::RefPtr<Gdk::Screen>& screen)
{
  gtk_invisible_set_screen(gobj(), Glib::unwrap(screen));
}


} // namespace Gtk


