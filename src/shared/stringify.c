/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 10:33:44 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/30 19:51:11 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

char *status_stringify(t_status *status)
{
	char *tmp;

	if (!(tmp = ft_strjoin_free(ft_itoa(status->code), status->message, TRUE, FALSE)))
		return (NULL);
	if (!(tmp = ft_strjoin_free(tmp, " ", TRUE, FALSE)))
		return (NULL);
	return (ft_strjoin_free(tmp, CLRF_STR, TRUE, FALSE));
}

/*
 * Build the str: command followed by arguments.
 * It terminates the string with CRLF (Telnet convention).
 */

char *cmd_stringify(t_cmd *cmd_data)
{
	char **args;
	char *cmd_str;
	char *tmp;

	if (!(cmd_str = ft_strdup(cmd_data->infos->network_cmd)))
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
