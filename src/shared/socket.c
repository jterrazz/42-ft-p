/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 19:10:50 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/30 14:13:40 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int get_tcp_socket(void)
{
	struct protoent	*prot;
	int sock;

	if (!(prot = getprotobyname("tcp")))
	{
		ft_printf("Error: Protocol failed\n");
		return (FAILURE);
	}
	// TODO Use IPV6 with the 4 next lines (sockeraddr_in6)
	if ((sock = socket(PF_INET, SOCK_STREAM, prot->p_proto)) < 0)
	{
		ft_printf("Error: Socket creation failed\n");
		return (FAILURE);
	}
	return (sock);
}

void create_sockaddr(struct sockaddr *sockaddr, int port, struct hostent *host)
{
	// IPV6
	((struct sockaddr_in *)sockaddr)->sin_family = AF_INET;
	((struct sockaddr_in *)sockaddr)->sin_len = sizeof(struct sockaddr_in);
	((struct sockaddr_in *)sockaddr)->sin_port = htons(port);
	if (host)
		ft_memcpy(&((struct sockaddr_in *)sockaddr)->sin_addr, host->h_addr_list[0], host->h_length);
	else
		((struct sockaddr_in *)sockaddr)->sin_addr.s_addr = INADDR_ANY;
}
