/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:39:53 by hogkim            #+#    #+#             */
/*   Updated: 2022/05/04 19:16:39 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	ft_from_client(int signo, siginfo_t *si, void *context)
{
	static int		i = 0;
	static char		c = 0;
	static pid_t	client_pid = 0;

	client_pid = si->si_pid;
	if (signo == SIGUSR2)
		c |= 1;
	ft_putnbr_fd(i, 1);
	if (++i == 8)
	{
		if (!c)
		{
			kill(client_pid, SIGUSR1);
			return ;
		}
		ft_putchar_fd(c, 1);
		kill(client_pid, SIGUSR2);
		i = 0;
		c = 0;
	}
	else
		c <<= 1;
	(void)context;
}

void	ft_from_client2(int signo)
{
	static int	i = 0;
	static char	c = 0;

	if (signo == SIGUSR2)
		c |= 1;
	if (++i == 8)
	{
		ft_putchar_fd(c, 1);
		i = 0;
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("Server PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
/* 	sa.sa_flags = SA_SIGINFO; */
	sa.sa_sigaction = ft_from_client;
	sa.sa_handler = ft_from_client2;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
/* 	signal(SIGUSR1, ft_from_client2);
	signal(SIGUSR2, ft_from_client2); */
	while (1)
		pause();
	return (0);
}
