/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:39:53 by hogkim            #+#    #+#             */
/*   Updated: 2022/05/06 15:05:33 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_from_client(int signo)
{
	static char	c;
	static int	i;

	if (signo == SIGUSR2)
		c |= 1;
	if (++i == 8)
	{
		i = 0;
		ft_printf("%c", c);
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	ft_printf("Server PID : %u\n", getpid());
	signal(SIGUSR1, ft_from_client);
	signal(SIGUSR2, ft_from_client);
	while (1)
		pause();
	return (0);
}
