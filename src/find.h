/*
 * This file is part of the fdupves package
 * Copyright (C) <2008> Alf
 *
 * Contact: Alf <naihe2010@126.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */
/* @CFILE ifind.h
 *
 *  Author: Alf <naihe2010@126.com>
 */

#ifndef _FDUPVES_FIND_H_
#define _FDUPVES_FIND_H_

#include <glib.h>

typedef enum
{
  FD_SAME_IMAGE,
  FD_SAME_VIDEO_HEAD,
  FD_SAME_VIDEO_TAIL,
  FD_SAME_AUDIO_HEAD,
  FD_SAME_AUDIO_TAIL,
  FD_SAME_EBOOK,
} same_type;

typedef struct
{
  long total;
  long now;
  const gchar *doing;
  gboolean found;
  same_type type;
  char *afile;
  char *bfile;
} find_step;

typedef gboolean (*find_step_cb) (const find_step *, gpointer);

int find_ebooks (GPtrArray *, find_step_cb, gpointer);

#endif
