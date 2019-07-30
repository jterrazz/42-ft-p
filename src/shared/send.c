/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:59:49 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/30 19:05:05 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

t_exit send_status(int socket, int code, char *msg)
{
	char		*status_str;
	t_status	status;

	status.code = code;
	status.message = msg;
	if (!(status_str = status_stringify(&status)))
		return (FAILURE);
	if (send(socket, status_str, ft_strlen(status_str), 0) < 0)
		return (FAILURE);
	free(status_str);
	return (SUCCESS);
}

t_exit send_cmd(int socket, t_cmd *cmd_req)
{
	char *cmd_str;

	if (!(cmd_str = cmd_stringify(cmd_req)))
		return (FAILURE);
	if (send(socket, cmd_str, ft_strlen(cmd_str), 0) < 0)
		return (FAILURE);
	free(cmd_str);
	return (SUCCESS);
}
