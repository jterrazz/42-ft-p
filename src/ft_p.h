/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 00:46:35 by jterrazz          #+#    #+#             */
/*   Updated: 2019/07/28 00:46:36 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_H
# define FT_P_H

# define FAILURE -1
# define SUCCESS 0

# include <stdlib.h>
# include <stdio.h>

# include <sys/socket.h>
# include <netdb.h>

# include "libft.h"
# include "get_next_line.h"

typedef enum	e_bool {
	FALSE,
	TRUE
}				t_bool;

typedef

typedef struct protoent			t_protoent;
typedef struct sockaddr_in		t_sockaddr_in;
typedef struct sockaddr_in6		t_sockaddr_in6; // TODO Remove if not using ipv6

#endif
