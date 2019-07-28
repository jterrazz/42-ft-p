/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 00:46:35 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/28 19:16:18 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_H
# define FT_P_H

# define SERVER_BACKLOG 50

# include <stdlib.h>

# include <netdb.h>
# include <arpa/inet.h>
# include <sys/socket.h>

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef enum	e_exit {
	FAILURE = -1,
	SUCCESS = 0
}				t_exit;

typedef enum	e_bool {
	FALSE = 0,
	TRUE = 1
}				t_bool;

typedef struct	e_server {
	int 			port;
	int 			socket;
}				t_server;

typedef struct	e_client {
	t_bool			exit;
	struct hostent	*host;
	int				port;
	int 			socket;
}				t_client;

t_exit	create_client(t_client *client, char const **argv);
t_exit	connect_client(t_client *client);

int get_tcp_socket(void);
void create_sockaddr(struct sockaddr *sockaddr, int port, struct hostent *host);

#endif
