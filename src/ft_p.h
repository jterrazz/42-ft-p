#ifndef FT_P_H
#define FT_P_H

#define FAILURE -1
#define SUCCESS 0

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

typedef enum { FALSE, TRUE } t_bool;

struct s_user {
	char *name;
	t_bool logged;
};

struct s_srv_session {
	struct s_user user;
};

struct s_instructions {

};

#endif
