#ifndef SHARED_H
# define SHARED_H

# define FAILURE -1
# define SUCCESS 0

#include <stdlib.h>
#include <stdio.h>

#include <sys/socket.h>
#include <netdb.h>

#include "libft.h"
#include "get_next_line.h"

typedef enum	e_bool {
	FALSE,
	TRUE
}				t_bool;

typedef struct protoent t_protoent;
typedef struct sockaddr_in t_sockaddr_in;
typedef struct sockaddr_in6 t_sockaddr_in6; // TODO Remove if not using ipv6

#endif
