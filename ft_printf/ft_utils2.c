/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:00:37 by hogkim            #+#    #+#             */
/*   Updated: 2022/04/06 17:45:58 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_bzero_ascii(void *s, size_t n)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*((unsigned char *)s + i) = '0';
		i++;
	}
	return (s);
}

char	*ft_bspace(void *s, size_t n)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*((unsigned char *)s + i) = ' ';
		i++;
	}
	return (s);
}

size_t	ft_itoa_base_count(unsigned long long nb, size_t base_nb)
{
	size_t	i;

	i = 0;
	while (nb > 0)
	{
		nb = nb / base_nb;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(unsigned long long nb, char *base)
{
	unsigned long long	base_nb;
	size_t				i;
	size_t				count;
	char				*s;

	base_nb = ft_strlen(base);
	count = ft_itoa_base_count(nb, base_nb);
	s = ft_calloc(count + 1, sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	count--;
	while (nb > 0)
	{
		s[count] = base[nb % base_nb];
		nb = nb / base_nb;
		count--;
		i++;
	}
	return (s);
}
