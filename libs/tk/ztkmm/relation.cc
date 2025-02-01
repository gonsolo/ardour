// Generated by gtkmmproc -- DO NOT MODIFY!


#include <glibmm.h>

#include <ztkmm/relation.h>
#include <ztkmm/private/relation_p.h>

#include <ztk/atk-enum-types.h>

// -*- c++ -*-
/* $Id: relation.ccg,v 1.2 2003/09/30 14:28:09 murrayc Exp $ */

/* Copyright 1998-2002 The gtkmm Development Team
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

#include <ztkmm/object.h>
#include <ztk/atkobject.h>
#include <ztk/atkrelation.h>


namespace Atk
{

//TODO: Implement this with the new GValue array thingy. See bug #74246.
Relation::Relation(const Glib::ArrayHandle< Glib::RefPtr<Atk::Object> >& targets,
                   RelationType relationship)
:
  Glib::Object((GObject*) atk_relation_new(const_cast<AtkObject**>(targets.data()), targets.size(),
                                           (AtkRelationType) relationship))
{}

Glib::ArrayHandle< Glib::RefPtr<Atk::Object> > Relation::get_target()
{
  GPtrArray *const parray = atk_relation_get_target(gobj());

  return Glib::ArrayHandle< Glib::RefPtr<Atk::Object> >
      (reinterpret_cast<AtkObject**>(parray->pdata), parray->len, Glib::OWNERSHIP_NONE);
}

Glib::ArrayHandle< Glib::RefPtr<const Atk::Object> > Relation::get_target() const
{
  GPtrArray *const parray = atk_relation_get_target(const_cast<AtkRelation*>(gobj()));

  return Glib::ArrayHandle< Glib::RefPtr<const Atk::Object> >
      (reinterpret_cast<AtkObject**>(parray->pdata), parray->len, Glib::OWNERSHIP_NONE);
}

} // namespace Atk


namespace
{
} // anonymous namespace

// static
GType Glib::Value<Atk::RelationType>::value_type()
{
  return atk_relation_type_get_type();
}


namespace Glib
{

Glib::RefPtr<Atk::Relation> wrap(AtkRelation* object, bool take_copy)
{
  return Glib::RefPtr<Atk::Relation>( dynamic_cast<Atk::Relation*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Atk
{


/* The *_Class implementation: */

const Glib::Class& Relation_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Relation_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(atk_relation_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void Relation_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* Relation_Class::wrap_new(GObject* object)
{
  return new Relation((AtkRelation*)object);
}


/* The implementation: */

AtkRelation* Relation::gobj_copy()
{
  reference();
  return gobj();
}

Relation::Relation(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

Relation::Relation(AtkRelation* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


Relation::~Relation()
{}


Relation::CppClassType Relation::relation_class_; // initialize static member

GType Relation::get_type()
{
  return relation_class_.init().get_type();
}


GType Relation::get_base_type()
{
  return atk_relation_get_type();
}


Glib::RefPtr<Relation> Relation::create(const Glib::ArrayHandle< Glib::RefPtr<Atk::Object> >& targets, RelationType relationship)
{
  return Glib::RefPtr<Relation>( new Relation(targets, relationship) );
}

RelationType Relation::get_relation_type() const
{
  return ((RelationType)(atk_relation_get_relation_type(const_cast<AtkRelation*>(gobj()))));
}

void Relation::add_target(const Glib::RefPtr<Atk::Object>& target)
{
  atk_relation_add_target(gobj(), Glib::unwrap(target));
}


} // namespace Atk


