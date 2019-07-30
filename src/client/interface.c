/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 00:51:42 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/30 15:39:15 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

t_exit	handle_line_cmd(t_client *client, char *line_cmd)
{
	t_ftp_cmd_info		*cmd_infos;
	char				**args;

	cmd_infos = g_ftp_cmds;
	if (!(args = ft_strsplit(line_cmd, ' ')))
		return (FAILURE);
	while (args && args[0] && cmd_infos->flag != CMD_NULL)
	{
		if (!ft_strcmp(cmd_infos->user_cmd, args[0]))
		{
			if (cmd_infos->client_handler)
				return cmd_infos->client_handler(client, cmd_infos, args);
			return client_cmd_default(client, cmd_infos, args);
		}
		cmd_infos += 1;
	}
	// Print usage ???
	// free args
	return (SUCCESS);
}

/*
 * Parse each line from STDIN and match with the list of
 * known commands g_ftp_cmds
 */

t_exit	start_client_interface(t_client *client)
{
	char		*line_cmd;

	while (!client->exit)
	{
		ft_printf("\033[1;34m<ftp %s>\033[0m ", client->host->h_name);
		if (get_next_line(0, &line_cmd) > 0)
		{
			if (handle_line_cmd(client, line_cmd))
				return (FAILURE);
		}
		// else
		// close socket/connection and quit // Check we don't need to free
		// Handle quit ? ctrl d / c ?
		free(line_cmd);
	}
	return (SUCCESS);
}
