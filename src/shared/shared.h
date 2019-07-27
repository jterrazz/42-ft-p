#ifndef SHARED_H
#define SHARED_H

#define FAILURE -1
#define SUCCESS 0

#define PROT_TCP "tcp"

#include <stdlib.h> // For exit ?
#include <stdio.h> // For ?
#include <sys/socket.h> //  For sockaddr_in sockaddr_in6
#include <netdb.h> // For gethostbyname, getprotobyname

#include "libft.h"
#include "get_next_line.h"

typedef enum { FALSE, TRUE } t_bool;

typedef struct protoent t_protoent;
typedef struct sockaddr_in t_sockaddr_in;
typedef struct sockaddr_in6 t_sockaddr_in6; // Remove if not using ipv6

struct s_instructions {

};

#endif
