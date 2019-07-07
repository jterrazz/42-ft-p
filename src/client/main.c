/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 08:51:49 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/07 08:52:27 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_p.h"

static int usage() {
	printf("Usage: ./client server port\n");
	return (EXIT_FAILURE);
}

int main(int argc, const char **argv)
{
	if (argc != 3)
		return (usage());
	(void)argv;

	while (1) {

	}

	return (EXIT_SUCCESS);
}
