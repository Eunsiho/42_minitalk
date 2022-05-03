/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:48:30 by hogkim            #+#    #+#             */
/*   Updated: 2022/04/06 17:33:10 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_di_itoa(int n)
{
	char	*s;

	if (n == -2147483648)
	{
		s = ft_strdup("2147483648");
	}
	else
		s = ft_itoa(n);
	return (s);
}

int	ft_di_plus_flag(char *s)
{
	int	ret;

	ret = 0;
	ft_putchar_fd('+', 1);
	ret++;
	ret += ft_putstr(s, 1);
	ft_free(s);
	return (ret);
}

int	ft_di_print2(t_form_tag *ft, char *s, int sign)
{
	int	ret;

	if (!s)
		return (-1);
	ret = 0;
	if (ft_strchr(ft->flags, '+') && sign == 1)
	{
		ret = ft_di_plus_flag(s);
		return (ret);
	}
	if (ft_strchr(ft->flags, ' ') && ft->width <= ft_strlen(s) - 1 && sign == 1)
	{
		ft_putchar_fd(' ', 1);
		ret = 1;
		ret += ft_putstr(s, 1);
		ft_free(s);
		return (ret);
	}
	ret = ft_putstr(s, 1);
	ft_free(s);
	return (ret);
}

int	ft_di_print(t_form_tag *ft, va_list ap)
{
	char	*temp;
	char	*s;
	int		nb;
	int		sign;

	nb = va_arg(ap, int);
	sign = 1;
	if (nb < 0)
	{
		nb = -nb;
		sign = -1;
	}
	temp = ft_di_itoa(nb);
	temp = ft_di_precision(temp, ft, sign);
	if (ft->if_precision && ft->precision == 0 && !temp)
	{
		ft_free(temp);
		temp = ft_strdup("");
	}
	s = ft_di_width(temp, ft);
	s = ft_di_sign(s, temp, ft, sign);
	nb = ft_di_print2(ft, s, sign);
	return (nb);
}
