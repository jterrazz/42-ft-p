/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 01:11:50 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/30 13:49:06 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_p.h"

t_exit	send_cmd(int socket, t_ftp_cmd_data *cmd_data)
{
	char *cmd_str;

	if (!(cmd_str = cmd_stringify(cmd_data)))
		return (FAILURE);
	if (send(socket, cmd_str, ft_strlen(cmd_str), 0) < 0)
		return (FAILURE);
	free(cmd_str);
	return (SUCCESS);
}

t_exit	client_cmd_ls(t_client *client, t_ftp_cmd_info *cmd, char **args)
{
	t_ftp_cmd_data cmd_data;

	cmd_data.cmd = cmd;
	cmd_data.args = args + 1;
	if (send_cmd(client->socket, &cmd_data))
		return (FAILURE);
	return (SUCCESS);
}
