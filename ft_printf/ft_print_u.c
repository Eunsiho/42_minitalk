/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:48:30 by hogkim            #+#    #+#             */
/*   Updated: 2022/04/06 17:50:25 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	nb_len_u(long long int nb)
{
	size_t	len;

	len = 0;
	if (nb <= 0)
	{
		len = 1;
		nb *= -1;
	}
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa_u(unsigned int n)
{
	char			*str;
	size_t			i;
	long long int	nb;

	nb = (long long int)n;
	str = (char *)malloc(sizeof(char) * (nb_len_u(nb) + 1));
	if (!str)
		return (NULL);
	i = nb_len_u(nb);
	str[i] = 0;
	i--;
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[i] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
	return (str);
}

int	ft_u_print(t_form_tag *ft, va_list ap)
{
	char			*temp;
	char			*s;
	unsigned int	nb;
	int				sign;

	nb = va_arg(ap, unsigned int);
	sign = 1;
	temp = ft_itoa_u(nb);
	temp = ft_di_precision(temp, ft, sign);
	if (ft->precision == 0 && !temp)
	{
		ft_free(temp);
		temp = ft_strdup("");
	}
	s = ft_di_width(temp, ft);
	s = ft_di_sign(s, temp, ft, sign);
	nb = ft_putstr(s, 1);
	ft_free(s);
	return (nb);
}
