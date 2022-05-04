/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:39:48 by hogkim            #+#    #+#             */
/*   Updated: 2022/05/04 14:05:39 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	ft_to_server(pid_t server_pid, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 8;
		while (j--) 
		{
			if((str[i] >> j) & 1)
			{
				kill(server_pid, SIGUSR2);
				usleep(100);
			}
			else
			{
				kill(server_pid, SIGUSR1);
				usleep(100);
			}
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr_fd("arguments are wrong\n", 1);
		return (0);
	}
	ft_to_server(ft_atoi(argv[1]), argv[2]);
	return (0);
}