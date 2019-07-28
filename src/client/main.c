/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 00:50:30 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/28 18:19:36 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_p.h"

static int usage(char const *exec)
{
	ft_printf("Usage: %s server port\n", exec);
	return (EXIT_FAILURE);
}

t_exit	handle_cmd(t_client *client, char *cmd)
{
	(void)client;
	(void)cmd;
	return (SUCCESS);
}

/*
 * Initialise the client data with args (address, port).
 * A socket is created. Once the socket connects to the host,
 * it parses and handles commands from STDIN.
 */

int	main(int argc, char const *argv[])
{
	t_client	client;
	char		*line;

	if (argc != 3)
		return usage(argv[0]);
	if (create_client(&client, argv) || connect_client(&client))
		return (FAILURE);
	while (!client.exit)
	{
		ft_printf("<ftp> ");
		if (get_next_line(0, &line) > 0) {
			// Handle quit ? ctrl d ?
			// Close socket on exit
			if (handle_cmd(&client, line))
				return (FAILURE);
		}
		free(line);
	}
	return (EXIT_SUCCESS);
}
