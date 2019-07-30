/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 18:27:54 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/30 21:51:54 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

// Format /pwd
// Format relative pwd/etc
// Format /file = send informations of file

t_exit	server_cmd_ls(t_server *server, int client_socket, t_cmd *cmd)
{
	// TODO If arg, search arg
	(void)cmd;
	(void)server;
	DIR *dir;
	struct dirent *dirent;
	if (!(dir = opendir(".")))
		return (FAILURE); // Send Error Msg and quit
	while ((dirent = readdir(dir)))
	{
		dirent->d_name
	}
	cmd->

	send_status(client_socket, 200, "OK");
	return (SUCCESS);
}
