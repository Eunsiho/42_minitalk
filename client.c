/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:39:48 by hogkim            #+#    #+#             */
/*   Updated: 2022/05/04 22:24:58 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_confirmed(int signo)
{
	static int	from_server = 0;

	if (signo == SIGUSR2)
		from_server++;
	if (signo == SIGUSR1)
	{
		ft_printf("From Server : %d\n", from_server);
		exit(0);
	}
}

void	ft_to_server(pid_t server_pid, char *str)
{
	int		j;
	char	c;

	while (*str)
	{
		j = 8;
		c = *str++;
		while (j--)
		{
			if ((c >> j) & 1)
				kill(server_pid, SIGUSR2);
			else
				kill(server_pid, SIGUSR1);
			usleep(80);
		}
	}
	j = 8;
	while (j--)
	{
		kill(server_pid, SIGUSR1);
		usleep(80);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr_fd("arguments are wrong\n", 1);
		return (0);
	}
	ft_printf("To Server   : %d\n", ft_strlen(argv[2]));
	signal(SIGUSR1, ft_confirmed);
	signal(SIGUSR2, ft_confirmed);
	ft_to_server(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
