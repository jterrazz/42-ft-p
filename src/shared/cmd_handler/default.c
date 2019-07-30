/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 01:11:50 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/30 14:22:10 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

t_exit	client_cmd_default(t_client *client, t_ftp_cmd_info *cmd, char **args)
{
	t_ftp_cmd_req cmd_req;

	cmd_req.cmd = cmd;
	cmd_req.args = args + 1;
	if (send_cmd(client->socket, &cmd_req))
		return (FAILURE);
	return (SUCCESS);
}
