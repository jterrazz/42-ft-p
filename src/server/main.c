/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 18:55:41 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/07 08:51:46 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <sys/wait.h>
// #include <signal.h>
// TODO wait4 + signal

#include "../ft_p.h"

static int usage() {
	printf("Usage: ./serveur port\n");
	return (EXIT_FAILURE);
}

int main(int argc, const char **argv)
{
	if (argc != 2)
		return (usage());
	(void)argv;

	while (1) {

	}

	return (EXIT_SUCCESS);
}
