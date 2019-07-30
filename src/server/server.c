/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 23:47:16 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/30 16:06:24 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

// TODO Explain how fork works

t_exit listen_client_cmds(int client_socket)
{
	char *cmd_msg;

	while (TRUE)
	{
		if (!(cmd_msg = receive_msg(client_socket)))
		{
			ft_printf("Error: Received command message fail\n");
			return (EXIT_FAILURE);
		}
		ft_printf("New command: %s\n", cmd_msg);
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
		if (listen_client_cmds(client_socket))
			return (FAILURE);
	}
	return (SUCCESS);
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
