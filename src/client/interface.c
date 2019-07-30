/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 00:51:42 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/30 19:21:16 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

// Don't make server stop when receiving bad message

t_exit	handle_line_cmd(t_client *client, char *line_cmd)
{
	char				**args;
	t_ftp_cmd_info		*cmd_infos;
	t_exit				ret;
	t_cmd cmd_req;

	if (!(args = ft_strsplit(line_cmd, ' ')))
		return (FAILURE);
	if ((cmd_infos = get_cmd_infos(*args, CMDNAME_USER)))
	{
		cmd_req.infos = cmd_infos;
		cmd_req.args = args + 1;
		if (cmd_infos->client_handler)
			ret = cmd_infos->client_handler(client, &cmd_req);
		else
			ret = client_cmd_default(client, &cmd_req);
		char *msg = receive_msg(client->socket);
		ft_printf("Response: %s\n", msg);

		// TODO Free message
		// TODO Free args indide
		return (ret);
	}

	// TODO Print usage ?
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
