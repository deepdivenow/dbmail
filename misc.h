/* $Id$ 
 * (c) 2000-2001 IC&S, The Netherlands */

#ifndef MISC_H_
#define MISC_H_
#include <grp.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include "dbmysql.h"
#include "debug.h"
#include "list.h"

int drop_priviledges (char *newuser, char *newgroup);

#endif
