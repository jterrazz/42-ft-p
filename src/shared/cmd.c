/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 00:29:21 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/30 18:27:50 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

t_ftp_cmd_info g_ftp_cmds[] = {
	{ "ls", "LIST", CMD_LS, NULL, &server_cmd_ls },
	{ "cd", "CWD", CMD_CD, NULL, NULL },
//	{ "get", CMD_GET },
//	{ "put", CMD_PUT },
//	{ "pwd",CMD_PWD },
	{ "quit", "QUIT", CMD_QUIT, NULL, NULL },
	{ "", "", CMD_NULL, NULL, NULL }
};

t_ftp_cmd_info	*get_cmd_infos(char *cmdname, t_cmdname_type type)
{
	t_ftp_cmd_info		*cmd_infos;

	cmd_infos = g_ftp_cmds;
	while (cmdname && cmd_infos->flag != CMD_NULL)
	{
		if ((type == CMDNAME_USER && !ft_strcmp(cmd_infos->user_cmd, cmdname))
			|| (type == CMDNAME_NETWORK && !ft_strcmp(cmd_infos->network_cmd, cmdname)))
			return (cmd_infos);
		cmd_infos += 1;
	}
	return (NULL);
}
