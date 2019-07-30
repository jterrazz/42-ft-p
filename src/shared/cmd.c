/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 00:29:21 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/29 01:13:50 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_p.h"

t_ftp_cmd_info g_ftp_cmds[] = {
	{ "ls", "LIST", CMD_LS, &client_cmd_ls },
//	{ "cd", CMD_CD },
//	{ "get", CMD_GET },
//	{ "put", CMD_PUT },
//	{ "pwd",CMD_PWD },
//	{ "quit", CMD_QUIT },
	{ "", "", CMD_NULL, NULL }
};
