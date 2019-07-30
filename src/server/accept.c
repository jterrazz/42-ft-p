/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 00:05:31 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/29 00:06:06 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_p.h"

// TODO Explain how fork works
t_exit accept_connections(t_server *server)
{
	int connection_fd;
	struct sockaddr_in client_addr; // Use ipv4 or no
	socklen_t client_addr_len;

	while (TRUE)
	{
		client_addr_len = sizeof(client_addr);
		if ((connection_fd = accept(server->socket, (struct sockaddr *)&client_addr, &client_addr_len)) < 0)
		{
			ft_printf("Error: Accepting new connection failed\n");
			return (EXIT_FAILURE);
		}
		ft_printf("New connection\n");
	}
	return (SUCCESS);
}
