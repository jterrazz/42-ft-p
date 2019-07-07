/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 08:51:49 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/07 12:29:48 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_p.h"

static int usage(int argc, const char **argv) {
	if (argc > 0)
		printf("Usage: %s server port\n", argv[0]);
	return (EXIT_FAILURE);
}

int main(int argc, const char **argv)
{
	if (argc != 3)
		return (usage(argc, argv));

	while (1) {

	}

	return (EXIT_SUCCESS);
}
