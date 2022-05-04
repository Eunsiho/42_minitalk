/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:39:53 by hogkim            #+#    #+#             */
/*   Updated: 2022/05/04 14:27:33 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	ft_from_client(int signo)
{
	static int	i = 0;
	static char	c = 0;

	if (signo == SIGUSR2)
		ft_putchar_fd('1', 1);
	if (signo == SIGUSR1)
		ft_putchar_fd('0', 1);
	i = 0;
	if (signo == SIGUSR2)
		c |= 1;
	if (++i == 8)
	{
		i = 0;
		ft_putchar_fd(c, 1);
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	ft_putstr_fd("Server PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, ft_from_client);
	signal(SIGUSR2, ft_from_client);
	while (1)
		pause();
	return (0);
}