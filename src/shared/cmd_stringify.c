/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 10:33:44 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/30 14:33:23 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
 * Build the str: command followed by arguments.
 * It terminates the string with CRLF (Telnet convention).
 */

char *cmd_stringify(t_ftp_cmd_req *cmd_data)
{
	char **args;
	char *cmd_str;
	char *tmp;

	if (!(cmd_str = ft_strdup(cmd_data->cmd->cmd)))
		return (NULL);
	args = cmd_data->args;
	while (args && *args)
	{
		if (!(tmp = ft_strjoin_free(cmd_str, " ", TRUE, FALSE)))
			return (NULL);
		if (!(cmd_str = ft_strjoin_free(tmp, *args, TRUE, FALSE)))
			return (NULL);
		args += 1;
	}
	if (!(cmd_str = ft_strjoin_free(cmd_str, CLRF_STR, TRUE, FALSE)))
		return (NULL);

	return (cmd_str);
}
