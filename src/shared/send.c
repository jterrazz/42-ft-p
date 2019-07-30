/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:59:49 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/30 14:20:24 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

t_exit send_cmd(int socket, t_ftp_cmd_req *cmd_req)
{
	char *cmd_str;

	if (!(cmd_str = cmd_stringify(cmd_req)))
		return (FAILURE);
	if (send(socket, cmd_str, ft_strlen(cmd_str), 0) < 0)
		return (FAILURE);
	free(cmd_str);
	return (SUCCESS);
}
