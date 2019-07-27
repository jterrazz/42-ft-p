/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 08:51:49 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/16 11:24:49 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./client.h"

static int usage(int argc, const char **argv)
{
	if (argc > 0)
		printf("Usage: %s server port\n", argv[0]);
	return (EXIT_FAILURE);
}

// TODO Free it
static void *create_sockaddr_in(uint32_t port, char *addr, int addr_len) {
	t_sockaddr_in *sockaddr;

	if (!(sockaddr = malloc(sizeof(t_sockaddr_in *))))
		return NULL;
	sockaddr->sin_family = AF_INET;

	// htons ?
	sockaddr->sin_port = port;

	// Check why memcpy works in ipv4
	ft_memcpy(&sockaddr->sin_addr, addr, addr_len);
	// sin_family; /* famille d'ad
}

// TODO Use v2 for IPV6
static void init_session(t_srv_session *session, const char **argv)
{
	t_protoent *proto;
	int sock;

	if (!(session->host = gethostbyname(argv[1])))
		exit_putstr("Host error\n", 1);
	session->port = ft_atoi(argv[2]);
	if (!(proto = getprotobyname(PROT_TCP)))
		exit_putstr("Protocol error\n", 1);

	// Replace by IPV6 here
	if ((sock = socket(PF_INET, SOCK_STREAM, proto->p_proto)) == -1)
		exit_putstr("Socket endpoint creation failed\n", 1);

	create_sockaddr_in();

	// Connect to ipv6 or ipv4 here (bind for server)
	// connect()
}

int main(int argc, const char **argv)
{
	t_srv_session session;

	if (argc != 3)
		return (usage(argc, argv));

	init_session(&session, argv);
	while (1) {

	}

	return (EXIT_SUCCESS);
}
