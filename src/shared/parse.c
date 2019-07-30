/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:28:18 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/30 19:28:26 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

t_cmd *cmd_parse(char *cmd_msg)
{
	char **args;
	t_cmd *req;

	if (!(args = ft_strsplit(cmd_msg, ' ')))
		return (NULL);
	if (!*args) {
		free(args);
		return (NULL);
	}
	if (!(req = malloc(sizeof(req))))
		return (NULL);
	if (!(req->infos = get_cmd_infos(args[0], CMDNAME_NETWORK))) // Return error messages to client
		return (NULL);
	if (args[0] && args[1])
		req->args = &(args[1]);
	else
		req->args = NULL;
	free(*args);
	free(args);
	return (req);
}
