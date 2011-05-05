/*
 * Copyright (C) 2011 Igalia S.L.
 * Authors: Mario Sanchez Prada <msanchez@igalia.com>
 *
 * Based on a C# example written in C# by Mike Gorse:
 * http://mgorse.freeshell.org/plug-socket-test.tar.gz
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of version 3 of the GNU General Public
 * License as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 */
#include "ta-socket-accessible-factory.h"

#include "ta-socket-accessible.h"
#include "ta-socket-label.h"

#include <atk/atk.h>
#include <glib.h>

G_DEFINE_TYPE (TaSocketAccessibleFactory, ta_socket_accessible_factory, ATK_TYPE_OBJECT_FACTORY);

static AtkObject *ta_socket_accessible_factory_create_accessible (GObject *obj)
{
  g_return_val_if_fail(G_IS_OBJECT (obj), NULL);

  AtkObject *new = NULL;

  new = ta_socket_accessible_new ();
  atk_object_initialize (new, obj);
  return new;
}

static GType ta_socket_accessible_factory_get_accessible_type (void)
{
  return TA_TYPE_SOCKET_ACCESSIBLE;
}

static void ta_socket_accessible_factory_class_init (TaSocketAccessibleFactoryClass *klass)
{
  GObjectClass *g_object_class = G_OBJECT_CLASS(klass);
  AtkObjectFactoryClass *atk_object_factory_class = NULL;

  atk_object_factory_class = ATK_OBJECT_FACTORY_CLASS (klass);
  atk_object_factory_class->create_accessible = ta_socket_accessible_factory_create_accessible;
  atk_object_factory_class->get_accessible_type = ta_socket_accessible_factory_get_accessible_type;
}

static void ta_socket_accessible_factory_init(TaSocketAccessibleFactory *socket)
{
}

void ta_socket_accessible_factory_initialize (void)
{
  atk_registry_set_factory_type (atk_get_default_registry (),
                                 TA_TYPE_SOCKET_LABEL,
                                 TA_TYPE_SOCKET_ACCESSIBLE_FACTORY);
}
