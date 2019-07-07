/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 18:55:41 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/07 12:29:28 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <sys/wait.h>
// #include <signal.h>
// TODO wait4 + signal

#include "../ft_p.h"

static int usage(int argc, const char **argv) {
	if (argc > 0)
		printf("Usage: %s port\n", argv[0]);
	return (EXIT_FAILURE);
}

int main(int argc, const char **argv)
{
	if (argc != 2)
		return (usage(argc, argv));

	while (1) {

	}

	return (EXIT_SUCCESS);
}
