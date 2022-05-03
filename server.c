/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:39:53 by hogkim            #+#    #+#             */
/*   Updated: 2022/05/03 14:49:51 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"
//SIGUSR1 = 0, SIGUSR2 = 1

int	ft_from_client(int signum, siginfo_t *si, void *ptr)
{
	
	(void)ptr;
}

int	main(void)
{
	struct sigaction sa;

	ft_printf("Server PID : %u\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaciton = ;
	while (1)
	{
		signal(S)
	}
}