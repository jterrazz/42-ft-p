/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 00:59:03 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/30 16:04:43 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static int usage(char const *exec)
{
	ft_printf("Usage: %s port\n", exec);
	return (EXIT_FAILURE);
}

// TODO Check admin is not required for XXX ports, put values on readme
// TODO Check the good port is listening with cmd, put in README too
// TODO Detect disconnect on both siedes ???
// TODO Close the socket at the end

int main(int argc, char const *argv[])
{
	t_server server;

	if (argc != 2)
		return usage(argv[0]);
	server.port = ft_atoi(argv[1]);
	if (start_server(&server) || accept_connections(&server))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
