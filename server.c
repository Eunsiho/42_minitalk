/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:39:53 by hogkim            #+#    #+#             */
/*   Updated: 2022/05/06 13:11:52 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_from_client(int signo, siginfo_t *si, void *context)
{
	static int		i = 0;
	static char		c = 0;

	if (signo == SIGUSR2)
		c |= 1;
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(si->si_pid, SIGUSR1);
			return ;
		}
		ft_printf("%c", c);
		c = 0;
		kill(si->si_pid, SIGUSR2);
	}
	else
		c <<= 1;
	(void)context;
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID : %u\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_from_client;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
