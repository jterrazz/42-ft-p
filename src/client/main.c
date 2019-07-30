/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 00:50:30 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/30 14:15:31 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static int usage(char const *exec)
{
	ft_printf("Usage: %s server port\n", exec);
	return (EXIT_FAILURE);
}

/*
 * Initialise the client data with args (address, port).
 * A socket is created. Once the socket connects to the host,
 * it parses and handles commands from STDIN.
 */

int	main(int argc, char const *argv[])
{
	t_client	client;

	if (argc != 3)
		return usage(argv[0]);
	if (create_client(&client, argv[1], argv[2]) || start_client(&client) || start_client_interface(&client))
		return (FAILURE);
	return (EXIT_SUCCESS);
}
