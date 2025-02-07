// Generated by gmmproc 2.45.3 -- DO NOT MODIFY!


#include <glibmm.h>

#include <ytkmm/paned.h>
#include <ytkmm/private/paned_p.h>


// -*- c++ -*-
/* $Id: paned.ccg,v 1.1 2003/01/21 13:40:33 murrayc Exp $ */

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

void Paned::pack1(Widget& child, AttachOptions options)
{
  const gboolean resize = ((options & EXPAND) != 0);
  const gboolean shrink = ((options & SHRINK) != 0);

  gtk_paned_pack1(gobj(), child.gobj(), resize, shrink);
}

void Paned::pack2(Widget& child, AttachOptions options)
{
  const gboolean resize = ((options & EXPAND) != 0);
  const gboolean shrink = ((options & SHRINK) != 0);

  gtk_paned_pack2(gobj(), child.gobj(), resize, shrink);
}

} // namespace Gtk


namespace
{
} // anonymous namespace


namespace Glib
{

Gtk::Paned* wrap(GtkPaned* object, bool take_copy)
{
  return dynamic_cast<Gtk::Paned *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& Paned_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Paned_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_paned_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void Paned_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* Paned_Class::wrap_new(GObject* o)
{
  return manage(new Paned((GtkPaned*)(o)));

}


/* The implementation: */

Paned::Paned(const Glib::ConstructParams& construct_params)
:
  Gtk::Container(construct_params)
{
  }

Paned::Paned(GtkPaned* castitem)
:
  Gtk::Container((GtkContainer*)(castitem))
{
  }

Paned::~Paned()
{
  destroy_();
}

Paned::CppClassType Paned::paned_class_; // initialize static member

GType Paned::get_type()
{
  return paned_class_.init().get_type();
}


GType Paned::get_base_type()
{
  return gtk_paned_get_type();
}


Paned::Paned()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::Container(Glib::ConstructParams(paned_class_.init()))
{
  

}

void Paned::add1(Widget& child)
{
  gtk_paned_add1(gobj(), (child).gobj());
}

void Paned::add2(Widget& child)
{
  gtk_paned_add2(gobj(), (child).gobj());
}

void Paned::pack1(Widget& child, bool resize, bool shrink)
{
  gtk_paned_pack1(gobj(), (child).gobj(), static_cast<int>(resize), static_cast<int>(shrink));
}

void Paned::pack2(Widget& child, bool resize, bool shrink)
{
  gtk_paned_pack2(gobj(), (child).gobj(), static_cast<int>(resize), static_cast<int>(shrink));
}

int Paned::get_position() const
{
  return gtk_paned_get_position(const_cast<GtkPaned*>(gobj()));
}

void Paned::set_position(int position)
{
  gtk_paned_set_position(gobj(), position);
}

Widget* Paned::get_child1()
{
  return Glib::wrap(gtk_paned_get_child1(gobj()));
}

const Widget* Paned::get_child1() const
{
  return const_cast<Paned*>(this)->get_child1();
}

Widget* Paned::get_child2()
{
  return Glib::wrap(gtk_paned_get_child2(gobj()));
}

const Widget* Paned::get_child2() const
{
  return const_cast<Paned*>(this)->get_child2();
}

Glib::RefPtr<Gdk::Window> Paned::get_handle_window()
{
  Glib::RefPtr<Gdk::Window> retvalue = Glib::wrap((GdkWindowObject*)(gtk_paned_get_handle_window(gobj())));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Gdk::Window> Paned::get_handle_window() const
{
  return const_cast<Paned*>(this)->get_handle_window();
}


Glib::PropertyProxy< int > Paned::property_position() 
{
  return Glib::PropertyProxy< int >(this, "position");
}

Glib::PropertyProxy_ReadOnly< int > Paned::property_position() const
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "position");
}

Glib::PropertyProxy< bool > Paned::property_position_set() 
{
  return Glib::PropertyProxy< bool >(this, "position-set");
}

Glib::PropertyProxy_ReadOnly< bool > Paned::property_position_set() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "position-set");
}

Glib::PropertyProxy_ReadOnly< int > Paned::property_min_position() const
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "min-position");
}

Glib::PropertyProxy_ReadOnly< int > Paned::property_max_position() const
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "max-position");
}


} // namespace Gtk


namespace Glib
{

Gtk::HPaned* wrap(GtkHPaned* object, bool take_copy)
{
  return dynamic_cast<Gtk::HPaned *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& HPaned_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &HPaned_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_hpaned_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void HPaned_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* HPaned_Class::wrap_new(GObject* o)
{
  return manage(new HPaned((GtkHPaned*)(o)));

}


/* The implementation: */

HPaned::HPaned(const Glib::ConstructParams& construct_params)
:
  Gtk::Paned(construct_params)
{
  }

HPaned::HPaned(GtkHPaned* castitem)
:
  Gtk::Paned((GtkPaned*)(castitem))
{
  }

HPaned::~HPaned()
{
  destroy_();
}

HPaned::CppClassType HPaned::hpaned_class_; // initialize static member

GType HPaned::get_type()
{
  return hpaned_class_.init().get_type();
}


GType HPaned::get_base_type()
{
  return gtk_hpaned_get_type();
}

HPaned::HPaned()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::Paned(Glib::ConstructParams(hpaned_class_.init()))
{
  

}


} // namespace Gtk


namespace Glib
{

Gtk::VPaned* wrap(GtkVPaned* object, bool take_copy)
{
  return dynamic_cast<Gtk::VPaned *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& VPaned_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &VPaned_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_vpaned_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void VPaned_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* VPaned_Class::wrap_new(GObject* o)
{
  return manage(new VPaned((GtkVPaned*)(o)));

}


/* The implementation: */

VPaned::VPaned(const Glib::ConstructParams& construct_params)
:
  Gtk::Paned(construct_params)
{
  }

VPaned::VPaned(GtkVPaned* castitem)
:
  Gtk::Paned((GtkPaned*)(castitem))
{
  }

VPaned::~VPaned()
{
  destroy_();
}

VPaned::CppClassType VPaned::vpaned_class_; // initialize static member

GType VPaned::get_type()
{
  return vpaned_class_.init().get_type();
}


GType VPaned::get_base_type()
{
  return gtk_vpaned_get_type();
}

VPaned::VPaned()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::Paned(Glib::ConstructParams(vpaned_class_.init()))
{
  

}


} // namespace Gtk


