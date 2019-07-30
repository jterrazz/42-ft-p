/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 23:47:16 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/28 23:47:16 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_p.h"

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
