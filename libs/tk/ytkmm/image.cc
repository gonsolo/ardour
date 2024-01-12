// Generated by gmmproc 2.45.3 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gtkmm/image.h>
#include <gtkmm/private/image_p.h>

#include <gtk/gtk.h>

// -*- c++ -*-
/* $Id: image.ccg,v 1.3 2005/07/10 19:24:22 murrayc Exp $ */

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

#include <gtk/gtk.h>
#include <gdkmm/image.h>
#include <gdkmm/bitmap.h>
#include <gdkmm/pixmap.h>

namespace Gtk
{

Image::Image(const Gtk::StockID& stock_id, IconSize size)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::Misc(Glib::ConstructParams(image_class_.init(), "stock",stock_id.get_c_str(),"icon-size",(GtkIconSize) int(size), static_cast<char*>(0)))
{}

Image::Image(const Glib::RefPtr<Gdk::PixbufAnimation>& animation)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::Misc(Glib::ConstructParams(image_class_.init(), "pixbuf-animation",Glib::unwrap(animation), static_cast<char*>(0)))
{}

void Image::get_pixmap(Glib::RefPtr<Gdk::Pixmap>& pixmap, Glib::RefPtr<Gdk::Bitmap>& mask) const
{
  GdkPixmap* pPixmap = 0;
  GdkBitmap* pBitmap = 0;

  gtk_image_get_pixmap(const_cast<GtkImage*>(gobj()), &pPixmap, &pBitmap);

  pixmap = Glib::wrap((GdkPixmapObject*) pPixmap, true);
  mask   = Glib::RefPtr<Gdk::Bitmap>::cast_dynamic(Glib::wrap((GdkPixmapObject*) pBitmap, true));
}

void Image::get_image(Glib::RefPtr<Gdk::Image>& gdk_image, Glib::RefPtr<Gdk::Bitmap>& mask) const
{
  GdkImage* pImage = 0;
  GdkBitmap* pBitmap = 0;

  gtk_image_get_image(const_cast<GtkImage*>(gobj()), &pImage, &pBitmap);

  gdk_image = Glib::wrap(pImage, true);
  mask = Glib::RefPtr<Gdk::Bitmap>::cast_dynamic(Glib::wrap((GdkPixmapObject*) pBitmap, true));
}

void Image::get_stock(Gtk::StockID& stock_id, IconSize& size) const
{
  char* pStockID = 0; // GTK+ iconsistency: although not const, it should not be freed.
  GtkIconSize icon_size = GTK_ICON_SIZE_INVALID;

  gtk_image_get_stock(const_cast<GtkImage*>(gobj()), &pStockID, &icon_size);

  size = IconSize(static_cast<int>(icon_size));
  stock_id = Gtk::StockID(pStockID); // the StockID ctor checks for 0
}

void Image::get_icon_set(IconSet& icon_set, IconSize& size) const
{
  GtkIconSet* pIconSet = 0;
  GtkIconSize icon_size = GTK_ICON_SIZE_INVALID;

  gtk_image_get_icon_set(const_cast<GtkImage*>(gobj()), &pIconSet, &icon_size);

  size = IconSize(static_cast<int>(icon_size));
  icon_set = Glib::wrap(pIconSet, true); //true = take_copy.
}

Glib::ustring Image::get_icon_name() const
{
  const gchar* pchIconName = 0;
  gtk_image_get_icon_name(const_cast<GtkImage*>(gobj()), &pchIconName, 0);
  return Glib::convert_const_gchar_ptr_to_ustring(pchIconName);
}

Glib::RefPtr<Gio::Icon> Image::get_gicon(Gtk::IconSize& icon_size)
{
  GIcon* cicon = 0;
  GtkIconSize cicon_size = GTK_ICON_SIZE_INVALID;
  gtk_image_get_gicon(gobj(), &cicon, &cicon_size);

  icon_size = Gtk::IconSize(cicon_size);
  return Glib::wrap(cicon);
}

Glib::RefPtr<const Gio::Icon> Image::get_gicon(Gtk::IconSize& icon_size) const
{
  Image* nonconstthis = const_cast<Image*>(this);
  return nonconstthis->get_gicon(icon_size);
}


} // namespace Gtk


namespace
{
} // anonymous namespace

// static
GType Glib::Value<Gtk::ImageType>::value_type()
{
  return gtk_image_type_get_type();
}


namespace Glib
{

Gtk::Image* wrap(GtkImage* object, bool take_copy)
{
  return dynamic_cast<Gtk::Image *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& Image_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Image_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_image_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void Image_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* Image_Class::wrap_new(GObject* o)
{
  return manage(new Image((GtkImage*)(o)));

}


/* The implementation: */

Image::Image(const Glib::ConstructParams& construct_params)
:
  Gtk::Misc(construct_params)
{
  }

Image::Image(GtkImage* castitem)
:
  Gtk::Misc((GtkMisc*)(castitem))
{
  }

Image::~Image()
{
  destroy_();
}

Image::CppClassType Image::image_class_; // initialize static member

GType Image::get_type()
{
  return image_class_.init().get_type();
}


GType Image::get_base_type()
{
  return gtk_image_get_type();
}


Image::Image()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::Misc(Glib::ConstructParams(image_class_.init()))
{
  

}

Image::Image(const Glib::RefPtr<Gdk::Pixmap>& pixmap, const Glib::RefPtr<Gdk::Bitmap>& mask)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::Misc(Glib::ConstructParams(image_class_.init(), "pixmap", Glib::unwrap(pixmap), "mask", Glib::unwrap(mask), static_cast<char*>(0)))
{
  

}

Image::Image(const Glib::RefPtr<Gdk::Image>& image, const Glib::RefPtr<Gdk::Bitmap>& mask)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::Misc(Glib::ConstructParams(image_class_.init(), "image", Glib::unwrap(image), "mask", Glib::unwrap(mask), static_cast<char*>(0)))
{
  

}

Image::Image(const std::string& file)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::Misc(Glib::ConstructParams(image_class_.init(), "file", file.c_str(), static_cast<char*>(0)))
{
  

}

Image::Image(const Glib::RefPtr<Gdk::Pixbuf>& pixbuf)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::Misc(Glib::ConstructParams(image_class_.init(), "pixbuf", Glib::unwrap(pixbuf), static_cast<char*>(0)))
{
  

}

Image::Image(const IconSet& icon_set, IconSize icon_size)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::Misc(Glib::ConstructParams(image_class_.init(), "icon_set", const_cast<GtkIconSet*>((icon_set).gobj()), "icon_size", static_cast<GtkIconSize>(int(icon_size)), static_cast<char*>(0)))
{
  

}

Image::Image(IconSet& icon_set, IconSize icon_size)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::Misc(Glib::ConstructParams(image_class_.init(), "icon_set", (icon_set).gobj(), "icon_size", static_cast<GtkIconSize>(int(icon_size)), static_cast<char*>(0)))
{
  

}

void Image::set(const Glib::RefPtr<Gdk::Pixmap>& pixmap, const Glib::RefPtr<Gdk::Bitmap>& mask)
{
  gtk_image_set_from_pixmap(gobj(), Glib::unwrap(pixmap), Glib::unwrap(mask));
}

void Image::set(const Glib::RefPtr<Gdk::Image>& gdk_image, const Glib::RefPtr<Gdk::Bitmap>& mask)
{
  gtk_image_set_from_image(gobj(), Glib::unwrap(gdk_image), Glib::unwrap(mask));
}

void Image::set(const std::string& filename)
{
  gtk_image_set_from_file(gobj(), filename.c_str());
}

void Image::set(const Glib::RefPtr<Gdk::Pixbuf>& pixbuf)
{
  gtk_image_set_from_pixbuf(gobj(), Glib::unwrap(pixbuf));
}

void Image::set(const Gtk::StockID& stock_id, IconSize size)
{
  gtk_image_set_from_stock(gobj(), (stock_id).get_c_str(), static_cast<GtkIconSize>(int(size)));
}

#ifndef GTKMM_DISABLE_DEPRECATED
G_GNUC_BEGIN_IGNORE_DEPRECATIONS
void Image::set(IconSet& icon_set, IconSize size)
{
  gtk_image_set_from_icon_set(gobj(), (icon_set).gobj(), static_cast<GtkIconSize>(int(size)));
}
G_GNUC_END_IGNORE_DEPRECATIONS
#endif // GTKMM_DISABLE_DEPRECATED

void Image::set(const IconSet& icon_set, IconSize size)
{
  gtk_image_set_from_icon_set(gobj(), const_cast<GtkIconSet*>((icon_set).gobj()), static_cast<GtkIconSize>(int(size)));
}

void Image::set(const Glib::RefPtr<Gdk::PixbufAnimation>& animation)
{
  gtk_image_set_from_animation(gobj(), Glib::unwrap(animation));
}

void Image::set(const Glib::RefPtr<const Gio::Icon>& icon, IconSize size)
{
  gtk_image_set_from_gicon(gobj(), const_cast<GIcon*>(Glib::unwrap<Gio::Icon>(icon)), static_cast<GtkIconSize>(int(size)));
}

void Image::set_from_icon_name(const Glib::ustring& icon_name, IconSize size)
{
  gtk_image_set_from_icon_name(gobj(), icon_name.c_str(), static_cast<GtkIconSize>(int(size)));
}

void Image::clear()
{
  gtk_image_clear(gobj());
}

ImageType Image::get_storage_type() const
{
  return ((ImageType)(gtk_image_get_storage_type(const_cast<GtkImage*>(gobj()))));
}

Glib::RefPtr<Gdk::Pixbuf> Image::get_pixbuf()
{
  Glib::RefPtr<Gdk::Pixbuf> retvalue = Glib::wrap(gtk_image_get_pixbuf(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Gdk::Pixbuf> Image::get_pixbuf() const
{
  return const_cast<Image*>(this)->get_pixbuf();
}

Glib::RefPtr<Gdk::PixbufAnimation> Image::get_animation()
{
  Glib::RefPtr<Gdk::PixbufAnimation> retvalue = Glib::wrap(gtk_image_get_animation(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Gdk::PixbufAnimation> Image::get_animation() const
{
  return const_cast<Image*>(this)->get_animation();
}

int Image::get_pixel_size() const
{
  return gtk_image_get_pixel_size(const_cast<GtkImage*>(gobj()));
}

void Image::set_pixel_size(int pixel_size)
{
  gtk_image_set_pixel_size(gobj(), pixel_size);
}


Glib::PropertyProxy< Glib::RefPtr<Gdk::Pixbuf> > Image::property_pixbuf() 
{
  return Glib::PropertyProxy< Glib::RefPtr<Gdk::Pixbuf> >(this, "pixbuf");
}

Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Pixbuf> > Image::property_pixbuf() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Pixbuf> >(this, "pixbuf");
}

Glib::PropertyProxy< Glib::RefPtr<Gdk::Pixmap> > Image::property_pixmap() 
{
  return Glib::PropertyProxy< Glib::RefPtr<Gdk::Pixmap> >(this, "pixmap");
}

Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Pixmap> > Image::property_pixmap() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Pixmap> >(this, "pixmap");
}

Glib::PropertyProxy< Glib::RefPtr<Gdk::Image> > Image::property_image() 
{
  return Glib::PropertyProxy< Glib::RefPtr<Gdk::Image> >(this, "image");
}

Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Image> > Image::property_image() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Image> >(this, "image");
}

Glib::PropertyProxy< Glib::RefPtr<Gdk::Pixmap> > Image::property_mask() 
{
  return Glib::PropertyProxy< Glib::RefPtr<Gdk::Pixmap> >(this, "mask");
}

Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Pixmap> > Image::property_mask() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Pixmap> >(this, "mask");
}

Glib::PropertyProxy< Glib::ustring > Image::property_file() 
{
  return Glib::PropertyProxy< Glib::ustring >(this, "file");
}

Glib::PropertyProxy_ReadOnly< Glib::ustring > Image::property_file() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "file");
}

Glib::PropertyProxy< Glib::ustring > Image::property_stock() 
{
  return Glib::PropertyProxy< Glib::ustring >(this, "stock");
}

Glib::PropertyProxy_ReadOnly< Glib::ustring > Image::property_stock() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "stock");
}

Glib::PropertyProxy< Gtk::IconSet > Image::property_icon_set() 
{
  return Glib::PropertyProxy< Gtk::IconSet >(this, "icon-set");
}

Glib::PropertyProxy_ReadOnly< Gtk::IconSet > Image::property_icon_set() const
{
  return Glib::PropertyProxy_ReadOnly< Gtk::IconSet >(this, "icon-set");
}

Glib::PropertyProxy< int > Image::property_icon_size() 
{
  return Glib::PropertyProxy< int >(this, "icon-size");
}

Glib::PropertyProxy_ReadOnly< int > Image::property_icon_size() const
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "icon-size");
}

Glib::PropertyProxy< int > Image::property_pixel_size() 
{
  return Glib::PropertyProxy< int >(this, "pixel-size");
}

Glib::PropertyProxy_ReadOnly< int > Image::property_pixel_size() const
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "pixel-size");
}

Glib::PropertyProxy< Glib::RefPtr<Gdk::PixbufAnimation> > Image::property_pixbuf_animation() 
{
  return Glib::PropertyProxy< Glib::RefPtr<Gdk::PixbufAnimation> >(this, "pixbuf-animation");
}

Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::PixbufAnimation> > Image::property_pixbuf_animation() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::PixbufAnimation> >(this, "pixbuf-animation");
}

Glib::PropertyProxy< Glib::ustring > Image::property_icon_name() 
{
  return Glib::PropertyProxy< Glib::ustring >(this, "icon-name");
}

Glib::PropertyProxy_ReadOnly< Glib::ustring > Image::property_icon_name() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "icon-name");
}

Glib::PropertyProxy_ReadOnly< ImageType > Image::property_storage_type() const
{
  return Glib::PropertyProxy_ReadOnly< ImageType >(this, "storage-type");
}

Glib::PropertyProxy< Glib::RefPtr<Gio::Icon> > Image::property_gicon() 
{
  return Glib::PropertyProxy< Glib::RefPtr<Gio::Icon> >(this, "gicon");
}

Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::Icon> > Image::property_gicon() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::Icon> >(this, "gicon");
}


} // namespace Gtk


