/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 00:59:03 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/28 21:36:44 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_p.h"

static int usage(char const *exec)
{
	ft_printf("Usage: %s port\n", exec);
	return (EXIT_FAILURE);
}

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
	ft_printf("Server is listening on ZZZZZZZZ"); // TODO Complete
	return (SUCCESS);
}

/*
 * Creates a socket, bind it to the port in arg. Then listening for connections.
 */

// Check admin is not required for XXX ports, put values on readme
int main(int argc, char const *argv[])
{
	t_server server;
	int connection_fd;
	struct sockaddr_in client_addr; // Use ipv4 or no
	socklen_t client_addr_len;

	if (argc != 2)
		return usage(argv[0]);
	// TODO Check the good port is listening with cmd, put in README too
	server.port = ft_atoi(argv[1]);
	if (start_server(&server)) // secure
		return (EXIT_FAILURE);
	while (TRUE)
	{
		client_addr_len = sizeof(client_addr);
		if ((connection_fd = accept(server.socket, (struct sockaddr *)&client_addr, &client_addr_len)) < 0)
		{
			ft_printf("Error: Accepting new connection failed\n");
			return (EXIT_FAILURE);
		}
		ft_printf("New connection\n");
	}

	return (EXIT_SUCCESS);
}
