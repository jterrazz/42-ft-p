/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:42:28 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/30 15:57:00 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void	*receive_msg(int socket)
{
	size_t	ret;
	size_t 	eol;
	char	buffer[MSG_BUFFER];
	char 	*data;
	char	*new;
	size_t	total_size;

	total_size = 0;
	data = NULL;
	while (TRUE)
	{
		if ((ret = recv(socket, buffer, MSG_BUFFER, 0)) > 0)
		{
			eol = ft_strstr(buffer, CLRF_STR) - buffer;
			ret = eol ? eol - 1 : ret;
			if (!(new = malloc(ret + total_size + 1)))
				return (NULL);
			ft_memmove(new, data, total_size);
			ft_memmove(new + total_size, buffer, ret);
			free(data);
			data = new;
			total_size += ret;
			data[total_size] = 0;
			if (eol)
				return (data);
		}
		else
			return (NULL);
	}
}
