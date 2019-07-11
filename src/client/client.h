#ifndef CLIENT_H
#define CLIENT_H

#include "../shared/shared.h"

typedef struct hostent t_hostend;

typedef struct s_srv_session {
	t_hostend *host;
	int port;
} t_srv_session;

#endif
