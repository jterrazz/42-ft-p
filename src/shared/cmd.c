/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 00:29:21 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/30 14:24:00 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

t_ftp_cmd_info g_ftp_cmds[] = {
	{ "ls", "LIST", CMD_LS, NULL },
	{ "cd", "CWD", CMD_CD, NULL },
//	{ "get", CMD_GET },
//	{ "put", CMD_PUT },
//	{ "pwd",CMD_PWD },
	{ "quit", "QUIT", CMD_QUIT, NULL },
	{ "", "", CMD_NULL, NULL }
};