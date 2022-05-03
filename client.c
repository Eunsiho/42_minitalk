/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:39:48 by hogkim            #+#    #+#             */
/*   Updated: 2022/05/03 14:49:50 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"
//SIGUSR1 = 0, SIGUSR2 = 1;

void	ft_to_server(pid_t server_pid, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i++])
	{
		j = 8;
		while (--j > -1)
		{
			if((c >> j) | 0)
				kill(server_pid, SIGUSR2);
			else
				kill(server_pid, SIGUSR1);
		}
	}
	i = 8;
	while (--i)
		kill(server_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("arguments are wrong\n");
		return (0);
	}
	ft_client_kill(ft_atoi(argv[1]), argv[2]);
	return (0);
}