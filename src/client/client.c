/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 17:25:20 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/28 21:49:37 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_p.h"

// Try if using ipv6 is retro compatible w ipv4
t_exit	connect_client(t_client *client)
{
	struct sockaddr sock_addr;

	if ((client->socket = get_tcp_socket()) == FAILURE)
		return (FAILURE);
	create_sockaddr(&sock_addr, client->port, client->host);

	if (connect(client->socket, &sock_addr, sizeof(struct sockaddr_in)))
	{
		ft_printf("Error: Connection to server failed\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

t_exit	create_client(t_client *client, char const **argv)
{
	ft_bzero(client, sizeof(client));
	if (!(client->host = gethostbyname(argv[1]))) // TODO Can use IPV6 here
	{
		ft_printf("Error: Host is not valid\n");
		return (FAILURE);
	}
	client->port = ft_atoi(argv[2]); // TODO Understand how htons deduct the byte order, probably because intel is little endian so it knows
	return (SUCCESS);
}
