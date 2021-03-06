/* dotdir.c - Dot directory management.
   Copyright (C) 2011 Neal H. Walfield <neal@walfield.org>

   Woodchuck is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 3, or (at
   your option) any later version.

   Woodchuck is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see
   <http://www.gnu.org/licenses/>.  */

#include "config.h"

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "dotdir.h"

static char *dotdir;

int
dotdir_init (const char *application)
{
  if (dotdir)
    return 0;

  char *base = NULL;
#ifdef HAVE_MAEMO
  /* Monitor the user's home directory even when run as root.  */
  base = "/home/user";
#else
  base = getenv ("HOME");
#endif

  if (asprintf (&dotdir, "%s/.%s", base, application) < 0)
    return ENOMEM;

  if (mkdir (dotdir, 0750) < 0 && errno != EEXIST)
    return errno;

  return 0;
}

char *
dotdir_filename (const char *subdir, const char *filename)
{
  if (! dotdir)
    /* Not initialized!  */
    {
      assert (! "Call to dotdir_filename, but dotdir_init never called.");
      abort ();
      return NULL;
    }

  char *abs_filename = NULL;
  if (asprintf (&abs_filename, "%s/%s/%s", dotdir, subdir ?: "", filename) < 0)
    return NULL;

  return abs_filename;
}
