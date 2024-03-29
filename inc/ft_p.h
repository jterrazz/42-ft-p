/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 00:46:35 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/30 20:10:30 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_H
# define FT_P_H

# define CLRF_STR "\x0D\x0A"

# define SERVER_BACKLOG 50
# define MSG_BUFFER 64

# include <stdlib.h>

# include <netdb.h>
# include <arpa/inet.h>
# include <sys/socket.h>
# include <dirent.h>

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

/*
 * FTP structures
 */

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

// It's probably not useful
typedef enum	e_ftp_cmd {
	CMD_NULL,
	CMD_LS,
	CMD_CD,
	CMD_GET,
	CMD_PUT,
	CMD_PWD,
	CMD_QUIT
}				t_ftp_cmd;

typedef enum	e_cmdname_type {
	CMDNAME_USER,
	CMDNAME_NETWORK
}				t_cmdname_type;

typedef struct	e_cmd {
	struct s_ftp_cmd_info	*infos;
	char					**args;
}				t_cmd;

typedef struct	e_status {
	int		code;
	char 	*message;
}				t_status;

typedef struct	s_ftp_cmd_info {
	char		user_cmd[10];
	char 		network_cmd[10];
	t_ftp_cmd	flag;
	t_exit		(*client_handler)(t_client *client, t_cmd *req);
	t_exit		(*server_handler)(t_server *server, int client_socket, t_cmd *req);
}				t_ftp_cmd_info;

/*
 * Globals
 */

extern t_ftp_cmd_info g_ftp_cmds[];

/*
 * Client methods
 */

t_exit	create_client(t_client *client, char const *hostname, char const *port_str);
t_exit	start_client(t_client *client);
t_exit	start_client_interface(t_client *client);


/*
 * Server methods
 */

t_exit	start_server(t_server *server);
t_exit	accept_connections(t_server *server);

/*
 * Command methods
 */

t_ftp_cmd_info	*get_cmd_infos(char *cmd_name, t_cmdname_type type);

t_exit	client_cmd_default(t_client *client, t_cmd *cmd_req);
t_exit	server_cmd_ls(t_server *server, int client_socket, t_cmd *req);

/*
 * Parse / stringify
 */

char *status_stringify(t_status *status);
char *cmd_stringify(t_cmd *cmd_data);
t_cmd *cmd_parse(char *cmd_msg);

/*
 * Network methods
 */

int		get_tcp_socket(void);
void	create_sockaddr(struct sockaddr *sockaddr, int port, struct hostent *host);
void	*receive_msg(int socket);
t_exit	send_status(int socket, int code, char *msg);
t_exit	send_cmd(int socket, t_cmd *cmd_req);

/*
 * Utils
 */

char *ft_strjoin_free(char *str1, char *str2, t_bool free1, t_bool free2);

#endif
