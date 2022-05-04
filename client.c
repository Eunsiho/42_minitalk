/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:39:48 by hogkim            #+#    #+#             */
/*   Updated: 2022/05/04 19:16:04 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	ft_print_to_server(int to_server)
{
	ft_putstr_fd("To server    : ", 1);
	ft_putnbr_fd(to_server, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_confirmed(int signo)
{
	static int	from_server = 0;

	if (signo == SIGUSR2)
		from_server++;
	if (signo == SIGUSR1)
	{
		ft_putstr_fd("From Server :", 1);
		ft_putnbr_fd(from_server, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}

void	ft_to_server(pid_t server_pid, char *str)
{
	int	i;
	int	j;
	int	to_server;

	to_server = 0;
	i = -1;
	while (str[++i])
	{
		j = 8;
		while (j--)
		{
			if ((str[i] >> j) & 1)
				kill(server_pid, SIGUSR2);
			else
				kill(server_pid, SIGUSR1);
			usleep(1000);
		}
		to_server++;
	}
	i = 8;
	while (i--)
	{
		kill(server_pid, SIGUSR1);
		usleep(1000);
	}
	ft_print_to_server(to_server);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr_fd("arguments are wrong\n", 1);
		return (0);
	}
	signal(SIGUSR1, ft_confirmed);
	signal(SIGUSR2, ft_confirmed);	
	ft_to_server(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
