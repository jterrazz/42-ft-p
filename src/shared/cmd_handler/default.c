/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 01:11:50 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/30 19:05:05 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

t_exit	client_cmd_default(t_client *client, t_cmd *cmd_req)
{
	if (send_cmd(client->socket, cmd_req))
		return (FAILURE);
	return (SUCCESS);
}
