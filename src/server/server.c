/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 23:47:16 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/30 20:10:30 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

// TODO Explain how fork works

static t_exit receive_client_cmds(t_server *server, int client_socket)
{
	char *cmd_msg;
	t_cmd *cmd;

	while (TRUE)
	{
		if (!(cmd_msg = receive_msg(client_socket)))
		{
			ft_printf("Error: Received command message fail\n");
			return (EXIT_FAILURE);
		}
		ft_printf("<cleeeeeee> CMD: %s:\n", cmd_msg); // Maybe hide
		// Exit cmd
		if (!(cmd = cmd_parse(cmd_msg)))
			return (FAILURE); // Return null of return status code
		if (cmd->infos->server_handler)
			cmd->infos->server_handler(server, client_socket, cmd);
		else
			send_status(client_socket, 551, "Requested action aborted. Command type unknown.\n");
//		free req
		// free args
	}
	return (SUCCESS);
}

/*
 *	Waits for new connections on the main socket. When a new client connects,
 *	we assign him a dedicated socket.
 *	The process is then forked to allow other clients to access the main socket.
 *	The accept method is blocking until a client is added to the socket queue.
 */

t_exit accept_connections(t_server *server)
{
	struct sockaddr_in	client_addr; // Use ipv4 or no
	socklen_t			client_addr_len;
	int					client_socket;

	while (TRUE)
	{
		client_addr_len = sizeof(client_addr);
		// Need fork here I think
		if ((client_socket = accept(server->socket, (struct sockaddr *)&client_addr, &client_addr_len)) < 0)
		{
			ft_printf("Error: Accepting new connection failed\n");
			return (FAILURE);
		}
		ft_printf("\033[1;34mNew client connected\033[0m\n");
		if (receive_client_cmds(server, client_socket))
			return (FAILURE);
	}
}

/*
 * Start the server in 3 steps:
 * - Create a socket
 * - Bind it to any IP addresses
 * - Start listening for new connections, and place them on a queue
 */

t_exit	start_server(t_server *server)
{
	struct sockaddr sock_addr;

	if ((server->socket = get_tcp_socket()) == FAILURE)
		return (FAILURE);
	create_sockaddr(&sock_addr, server->port,  NULL);
	if (bind(server->socket, &sock_addr, sizeof(struct sockaddr_in))) // Will need to replace if ipv6
	{
		ft_printf("Error: Binding socket failed\n");
		return (FAILURE);
	}
	if (listen(server->socket, SERVER_BACKLOG))
	{
		ft_printf("Error: Listening failed\n");
		return (FAILURE);
	}
	ft_printf("Server is listening on port: %d\n", server->port); // TODO Complete
	return (SUCCESS);
}
