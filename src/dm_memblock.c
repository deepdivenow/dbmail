 /*
 Copyright (C) 1999-2004 IC & S  dbmail@ic-s.nl
 Copyright (c) 2004-2010 NFG Net Facilities Group BV support@nfg.nl

 This program is free software; you can redistribute it and/or 
 modify it under the terms of the GNU General Public License 
 as published by the Free Software Foundation; either 
 version 2 of the License, or (at your option) any later 
 version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

/*
 * dm_memblock.c
 *
 * implementations of functions declared in dm_memblock.h
 */

#include <glib.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include "dm_memblock.h"

#define T Mem_T

#define NEW(x) x = g_malloc0( sizeof(*x) )

#define min(x,y) ((x)<=(y)?(x):(y))

struct T {
	GByteArray *data;
	guint pos;
};

/*
 * mopen()
 *
 * opens a mem-structure
 */
T Mem_open()
{
	T M;
	NEW(M);
	M->data = g_byte_array_new();
	return M;
}


/*
 * mclose()
 *
 * closes a mem structure
 *
 */
void Mem_close(T *M)
{
	T m = *M;
	assert(M && m);

	g_byte_array_free(m->data, TRUE);
	*M = NULL;

	return;
}


/*
 * mwrite()
 *
 * writes size bytes of data to the memory associated with m
 */
int Mem_write(T M, const void *data, int size)
{
	
	M->data = g_byte_array_append(M->data, (const guint8 *)data, (guint)size);
	return size;
}

/*
 * mread()
 *
 * reads up to size bytes from m into data
 *
 * returns the number of bytes actually read
 */
int Mem_read(T M, void *data, int size)
{
	assert(M);
	memmove(data, M->data->data+M->pos, min((int)M->data->len, size));
	return (int)min((int)M->data->len, size);
	
}


/*
 * mseek()
 *
 * moves the current pos in m offset bytes according to whence:
 * SEEK_SET seek from the beginning
 * SEEK_CUR seek from the current pos
 * SEEK_END seek from the end
 *
 * returns 0 on succes, -1 on error
 */
int Mem_seek(T M, long offset, int whence)
{
	assert(M);
	guint maxpos = M->data->len-1;
	long left;

	switch (whence) {
	case SEEK_SET:
		M->pos = 0;
		if (offset <= 0) return 0;
		return Mem_seek(M, offset, SEEK_CUR);

	case SEEK_CUR:
		if (offset == 0) return 0;

		if (offset > 0) {
			left = maxpos - M->pos;
			if (offset >= left) {
				M->pos = maxpos;
				return 0;
			} else {
				M->pos += offset;
				return 0;
			}
		} else {
			/* offset < 0, walk backwards */
			left = -M->pos;

			if (offset <= left) {
				M->pos = 0;
				return 0;
			} else {
				M->pos += offset;	/* remember: offset<0 */
				return 0;
			}
		}

	case SEEK_END:
		M->pos = maxpos;
		if (offset >= 0) return 0;
		return Mem_seek(M, offset, SEEK_CUR);

	default:
		return -1;
	}

	return 0;
}


/*
 * mrewind()
 *
 * equivalent to mseek(m, 0, SEEK_SET)
 */
void Mem_rewind(T M)
{
	Mem_seek(M, 0, SEEK_SET);
}


