// Generated by gtkmmproc -- DO NOT MODIFY!


#include <glibmm.h>

#include <ztkmm/object.h>
#include <ztkmm/private/object_p.h>

#include <ztk/atk-enum-types.h>

// -*- c++ -*-
/* $Id: object.ccg,v 1.1 2003/01/21 13:37:06 murrayc Exp $ */

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

#include <ztkmm/noopobject.h>
#include <ztkmm/relation.h>
#include <ztkmm/relationset.h>
#include <ztkmm/stateset.h>
#include <ztk/atkobject.h>


namespace Atk
{

/* AtkObject is actually an abstract base class.  So if this wrap_new()
 * function is called, it means that no wrapper exists for the real C object.
 * The problem is that gail (the real accessibility implementation) is
 * currently not wrapped and will probably never be.  Therefore, code like
 * in the following example is doomed to fail:
 *
 * Gtk::Image image ("icon.png");
 * Glib::RefPtr<Atk::Image> accessible = Glib::RefPtr<Atk::Image>::cast_dynamic(image.get_accessible());
 * accessible->set_image_description("my icon");
 *
 * This would segfault, even though the accessible object _does_ implement
 * AtkImage.  But Atk::Image is an interface class that can't be instantiated
 * as is.  It needs an object.
 *
 * The solution is to instantiate a dummy object that implements all of the
 * ATK interfaces.  Fortunately, ATK already provides us with such a thing,
 * AtkNoOpObject.  All widget accessible objects are of this type if the gail
 * module is not loaded (which is the default).
 *
 * So what we do here is abusing Atk::NoOpObject to get around the lack of
 * C++ wrappers for gail.  Instead of instantiating a useless instance of an
 * abstract base class, we just create a Atk::NoOpObject instance which can
 * be casted to any of the Atk interface classes.
 */
Glib::ObjectBase* Object_Class::wrap_new(GObject* object)
{
  return new Atk::NoOpObject((AtkNoOpObject*) object);
}

} // namespace Atk


namespace
{


static void Object_signal_children_changed_callback(AtkObject* self, guint p0,gpointer p1,void* data)
{
  using namespace Atk;
  typedef sigc::slot< void,guint,gpointer > SlotType;

  // Do not try to call a signal on a disassociated wrapper.
  if(Glib::ObjectBase::_get_current_wrapper((GObject*) self))
  {
    #ifdef GLIBMM_EXCEPTIONS_ENABLED
    try
    {
    #endif //GLIBMM_EXCEPTIONS_ENABLED
      if(sigc::slot_base *const slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0, p1);
    #ifdef GLIBMM_EXCEPTIONS_ENABLED
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
    #endif //GLIBMM_EXCEPTIONS_ENABLED
  }
}

static const Glib::SignalProxyInfo Object_signal_children_changed_info =
{
  "children_changed",
  (GCallback) &Object_signal_children_changed_callback,
  (GCallback) &Object_signal_children_changed_callback
};


static void Object_signal_focus_event_callback(AtkObject* self, gboolean p0,void* data)
{
  using namespace Atk;
  typedef sigc::slot< void,bool > SlotType;

  // Do not try to call a signal on a disassociated wrapper.
  if(Glib::ObjectBase::_get_current_wrapper((GObject*) self))
  {
    #ifdef GLIBMM_EXCEPTIONS_ENABLED
    try
    {
    #endif //GLIBMM_EXCEPTIONS_ENABLED
      if(sigc::slot_base *const slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0
);
    #ifdef GLIBMM_EXCEPTIONS_ENABLED
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
    #endif //GLIBMM_EXCEPTIONS_ENABLED
  }
}

static const Glib::SignalProxyInfo Object_signal_focus_event_info =
{
  "focus_event",
  (GCallback) &Object_signal_focus_event_callback,
  (GCallback) &Object_signal_focus_event_callback
};


static void Object_signal_property_change_callback(AtkObject* self, AtkPropertyValues* p0,void* data)
{
  using namespace Atk;
  typedef sigc::slot< void,AtkPropertyValues* > SlotType;

  // Do not try to call a signal on a disassociated wrapper.
  if(Glib::ObjectBase::_get_current_wrapper((GObject*) self))
  {
    #ifdef GLIBMM_EXCEPTIONS_ENABLED
    try
    {
    #endif //GLIBMM_EXCEPTIONS_ENABLED
      if(sigc::slot_base *const slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0);
    #ifdef GLIBMM_EXCEPTIONS_ENABLED
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
    #endif //GLIBMM_EXCEPTIONS_ENABLED
  }
}

static const Glib::SignalProxyInfo Object_signal_property_change_info =
{
  "property_change",
  (GCallback) &Object_signal_property_change_callback,
  (GCallback) &Object_signal_property_change_callback
};


static void Object_signal_state_change_callback(AtkObject* self, const gchar* p0,gboolean p1,void* data)
{
  using namespace Atk;
  typedef sigc::slot< void,const Glib::ustring&,bool > SlotType;

  // Do not try to call a signal on a disassociated wrapper.
  if(Glib::ObjectBase::_get_current_wrapper((GObject*) self))
  {
    #ifdef GLIBMM_EXCEPTIONS_ENABLED
    try
    {
    #endif //GLIBMM_EXCEPTIONS_ENABLED
      if(sigc::slot_base *const slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::convert_const_gchar_ptr_to_ustring(p0)
, p1
);
    #ifdef GLIBMM_EXCEPTIONS_ENABLED
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
    #endif //GLIBMM_EXCEPTIONS_ENABLED
  }
}

static const Glib::SignalProxyInfo Object_signal_state_change_info =
{
  "state_change",
  (GCallback) &Object_signal_state_change_callback,
  (GCallback) &Object_signal_state_change_callback
};


static const Glib::SignalProxyInfo Object_signal_visible_data_changed_info =
{
  "visible_data_changed",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


static void Object_signal_active_descendant_changed_callback(AtkObject* self, gpointer* p0,void* data)
{
  using namespace Atk;
  typedef sigc::slot< void,void** > SlotType;

  // Do not try to call a signal on a disassociated wrapper.
  if(Glib::ObjectBase::_get_current_wrapper((GObject*) self))
  {
    #ifdef GLIBMM_EXCEPTIONS_ENABLED
    try
    {
    #endif //GLIBMM_EXCEPTIONS_ENABLED
      if(sigc::slot_base *const slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0
);
    #ifdef GLIBMM_EXCEPTIONS_ENABLED
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
    #endif //GLIBMM_EXCEPTIONS_ENABLED
  }
}

static const Glib::SignalProxyInfo Object_signal_active_descendant_changed_info =
{
  "active_descendant_changed",
  (GCallback) &Object_signal_active_descendant_changed_callback,
  (GCallback) &Object_signal_active_descendant_changed_callback
};


} // anonymous namespace

// static
GType Glib::Value<Atk::Role>::value_type()
{
  return atk_role_get_type();
}


namespace Glib
{

Glib::RefPtr<Atk::Object> wrap(AtkObject* object, bool take_copy)
{
  return Glib::RefPtr<Atk::Object>( dynamic_cast<Atk::Object*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Atk
{


/* The *_Class implementation: */

const Glib::Class& Object_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Object_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(atk_object_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void Object_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


  klass->children_changed = &children_changed_callback;
  klass->focus_event = &focus_event_callback;
  klass->property_change = &property_change_callback;
  klass->state_change = &state_change_callback;
  klass->visible_data_changed = &visible_data_changed_callback;
  klass->active_descendant_changed = &active_descendant_changed_callback;
}


void Object_Class::children_changed_callback(AtkObject* self, guint p0, gpointer p1)
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
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
      #endif //GLIBMM_EXCEPTIONS_ENABLED
        // Call the virtual member method, which derived classes might override.
        obj->on_children_changed(p0, p1);
        return;
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
      #endif //GLIBMM_EXCEPTIONS_ENABLED
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->children_changed)
    (*base->children_changed)(self, p0, p1);
}
void Object_Class::focus_event_callback(AtkObject* self, gboolean p0)
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
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
      #endif //GLIBMM_EXCEPTIONS_ENABLED
        // Call the virtual member method, which derived classes might override.
        obj->on_focus_event(p0
);
        return;
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
      #endif //GLIBMM_EXCEPTIONS_ENABLED
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->focus_event)
    (*base->focus_event)(self, p0);
}
void Object_Class::property_change_callback(AtkObject* self, AtkPropertyValues* p0)
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
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
      #endif //GLIBMM_EXCEPTIONS_ENABLED
        // Call the virtual member method, which derived classes might override.
        obj->on_property_change(p0);
        return;
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
      #endif //GLIBMM_EXCEPTIONS_ENABLED
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->property_change)
    (*base->property_change)(self, p0);
}
void Object_Class::state_change_callback(AtkObject* self, const gchar* p0, gboolean p1)
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
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
      #endif //GLIBMM_EXCEPTIONS_ENABLED
        // Call the virtual member method, which derived classes might override.
        obj->on_state_change(Glib::convert_const_gchar_ptr_to_ustring(p0)
, p1
);
        return;
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
      #endif //GLIBMM_EXCEPTIONS_ENABLED
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->state_change)
    (*base->state_change)(self, p0, p1);
}
void Object_Class::visible_data_changed_callback(AtkObject* self)
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
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
      #endif //GLIBMM_EXCEPTIONS_ENABLED
        // Call the virtual member method, which derived classes might override.
        obj->on_visible_data_changed();
        return;
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
      #endif //GLIBMM_EXCEPTIONS_ENABLED
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->visible_data_changed)
    (*base->visible_data_changed)(self);
}
void Object_Class::active_descendant_changed_callback(AtkObject* self, gpointer* p0)
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
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
      #endif //GLIBMM_EXCEPTIONS_ENABLED
        // Call the virtual member method, which derived classes might override.
        obj->on_active_descendant_changed(p0
);
        return;
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
      #endif //GLIBMM_EXCEPTIONS_ENABLED
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->active_descendant_changed)
    (*base->active_descendant_changed)(self, p0);
}


/* The implementation: */

AtkObject* Object::gobj_copy()
{
  reference();
  return gobj();
}

Object::Object(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

Object::Object(AtkObject* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


Object::~Object()
{}


Object::CppClassType Object::object_class_; // initialize static member

GType Object::get_type()
{
  return object_class_.init().get_type();
}


GType Object::get_base_type()
{
  return atk_object_get_type();
}


Glib::ustring Object::get_name() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(atk_object_get_name(const_cast<AtkObject*>(gobj())));
}

Glib::ustring Object::get_description() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(atk_object_get_description(const_cast<AtkObject*>(gobj())));
}

Glib::RefPtr<Atk::Object> Object::get_parent()
{
  Glib::RefPtr<Atk::Object> retvalue = Glib::wrap(atk_object_get_parent(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

int Object::get_n_accessible_children() const
{
  return atk_object_get_n_accessible_children(const_cast<AtkObject*>(gobj()));
}

Glib::RefPtr<Atk::Object> Object::get_accessible_child(int i)
{
  return Glib::wrap(atk_object_ref_accessible_child(gobj(), i));
}

Glib::RefPtr<RelationSet> Object::get_relation_set()
{
  Glib::RefPtr<RelationSet> retvalue = Glib::wrap(atk_object_ref_relation_set(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Role Object::get_role() const
{
  return ((Role)(atk_object_get_role(const_cast<AtkObject*>(gobj()))));
}

Glib::RefPtr<StateSet> Object::get_state_set()
{
  return Glib::wrap(atk_object_ref_state_set(gobj()));
}

int Object::get_index_in_parent()
{
  return atk_object_get_index_in_parent(gobj());
}

void Object::set_name(const Glib::ustring& name)
{
  atk_object_set_name(gobj(), name.c_str());
}

void Object::set_description(const Glib::ustring& description)
{
  atk_object_set_description(gobj(), description.c_str());
}

void Object::set_parent(const Glib::RefPtr<Atk::Object>& parent)
{
  atk_object_set_parent(gobj(), Glib::unwrap(parent));
}

void Object::set_role(Role role)
{
  atk_object_set_role(gobj(), ((AtkRole)(role)));
}

void Object::notify_state_change(State state, bool value)
{
  atk_object_notify_state_change(gobj(), state, static_cast<int>(value));
}

bool Object::add_relationship(RelationType relationship, const Glib::RefPtr<Object>& target)
{
  return atk_object_add_relationship(gobj(), ((AtkRelationType)(relationship)), Glib::unwrap(target));
}

bool Object::remove_relationship(RelationType relationship, const Glib::RefPtr<Object>& target)
{
  return atk_object_remove_relationship(gobj(), ((AtkRelationType)(relationship)), Glib::unwrap(target));
}


Glib::SignalProxy2< void,guint,gpointer > Object::signal_children_changed()
{
  return Glib::SignalProxy2< void,guint,gpointer >(this, &Object_signal_children_changed_info);
}


Glib::SignalProxy1< void,bool > Object::signal_focus_event()
{
  return Glib::SignalProxy1< void,bool >(this, &Object_signal_focus_event_info);
}


Glib::SignalProxy1< void,AtkPropertyValues* > Object::signal_property_change()
{
  return Glib::SignalProxy1< void,AtkPropertyValues* >(this, &Object_signal_property_change_info);
}


Glib::SignalProxy2< void,const Glib::ustring&,bool > Object::signal_state_change()
{
  return Glib::SignalProxy2< void,const Glib::ustring&,bool >(this, &Object_signal_state_change_info);
}


Glib::SignalProxy0< void > Object::signal_visible_data_changed()
{
  return Glib::SignalProxy0< void >(this, &Object_signal_visible_data_changed_info);
}


Glib::SignalProxy1< void,void** > Object::signal_active_descendant_changed()
{
  return Glib::SignalProxy1< void,void** >(this, &Object_signal_active_descendant_changed_info);
}


#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< Glib::ustring > Object::property_accessible_name() 
{
  return Glib::PropertyProxy< Glib::ustring >(this, "accessible-name");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< Glib::ustring > Object::property_accessible_name() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "accessible-name");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< Glib::ustring > Object::property_accessible_description() 
{
  return Glib::PropertyProxy< Glib::ustring >(this, "accessible-description");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< Glib::ustring > Object::property_accessible_description() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "accessible-description");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< Glib::RefPtr<Atk::Object> > Object::property_accessible_parent() 
{
  return Glib::PropertyProxy< Glib::RefPtr<Atk::Object> >(this, "accessible-parent");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Atk::Object> > Object::property_accessible_parent() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Atk::Object> >(this, "accessible-parent");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< double > Object::property_accessible_value() 
{
  return Glib::PropertyProxy< double >(this, "accessible-value");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< double > Object::property_accessible_value() const
{
  return Glib::PropertyProxy_ReadOnly< double >(this, "accessible-value");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< int > Object::property_accessible_role() 
{
  return Glib::PropertyProxy< int >(this, "accessible-role");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< int > Object::property_accessible_role() const
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "accessible-role");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< int > Object::property_accessible_component_layer() const
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "accessible-component-layer");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< int > Object::property_accessible_component_mdi_zorder() const
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "accessible-component-mdi-zorder");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< Glib::ustring > Object::property_accessible_table_caption() 
{
  return Glib::PropertyProxy< Glib::ustring >(this, "accessible-table-caption");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< Glib::ustring > Object::property_accessible_table_caption() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "accessible-table-caption");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< Glib::ustring > Object::property_accessible_table_column_description() 
{
  return Glib::PropertyProxy< Glib::ustring >(this, "accessible-table-column-description");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< Glib::ustring > Object::property_accessible_table_column_description() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "accessible-table-column-description");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< Glib::RefPtr<Atk::Object> > Object::property_accessible_table_column_header() 
{
  return Glib::PropertyProxy< Glib::RefPtr<Atk::Object> >(this, "accessible-table-column-header");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Atk::Object> > Object::property_accessible_table_column_header() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Atk::Object> >(this, "accessible-table-column-header");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< Glib::ustring > Object::property_accessible_table_row_description() 
{
  return Glib::PropertyProxy< Glib::ustring >(this, "accessible-table-row-description");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< Glib::ustring > Object::property_accessible_table_row_description() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "accessible-table-row-description");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< Glib::RefPtr<Atk::Object> > Object::property_accessible_table_row_header() 
{
  return Glib::PropertyProxy< Glib::RefPtr<Atk::Object> >(this, "accessible-table-row-header");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Atk::Object> > Object::property_accessible_table_row_header() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Atk::Object> >(this, "accessible-table-row-header");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< Glib::RefPtr<Atk::Object> > Object::property_accessible_table_summary() 
{
  return Glib::PropertyProxy< Glib::RefPtr<Atk::Object> >(this, "accessible-table-summary");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Atk::Object> > Object::property_accessible_table_summary() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Atk::Object> >(this, "accessible-table-summary");
}
#endif //GLIBMM_PROPERTIES_ENABLED


void Atk::Object::on_children_changed(guint change_index, gpointer changed_child)
{
  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->children_changed)
    (*base->children_changed)(gobj(),change_index,changed_child);
}
void Atk::Object::on_focus_event(bool focus_in)
{
  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->focus_event)
    (*base->focus_event)(gobj(),static_cast<int>(focus_in));
}
void Atk::Object::on_property_change(AtkPropertyValues* values)
{
  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->property_change)
    (*base->property_change)(gobj(),values);
}
void Atk::Object::on_state_change(const Glib::ustring& name, bool state_set)
{
  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->state_change)
    (*base->state_change)(gobj(),name.c_str(),static_cast<int>(state_set));
}
void Atk::Object::on_visible_data_changed()
{
  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->visible_data_changed)
    (*base->visible_data_changed)(gobj());
}
void Atk::Object::on_active_descendant_changed(void** child)
{
  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->active_descendant_changed)
    (*base->active_descendant_changed)(gobj(),child);
}


} // namespace Atk


