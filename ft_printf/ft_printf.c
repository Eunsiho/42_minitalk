/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 03:48:06 by hogkim            #+#    #+#             */
/*   Updated: 2022/04/07 13:52:02 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_form(t_form_tag *ft, va_list ap)
{
	int	ret;

	ret = 0;
	if (ft->type == 'c')
		ret = ft_c_print(ft, ap);
	else if (ft->type == 's')
		ret = ft_s_print(ft, ap);
	else if (ft->type == 'p')
		ret = ft_p_print(ft, ap);
	else if (ft->type == 'd' || ft->type == 'i')
		ret = ft_di_print(ft, ap);
	else if (ft->type == 'u')
		ret = ft_u_print(ft, ap);
	else if (ft->type == 'x' || ft->type == 'X')
		ret = ft_x_print(ft, ap);
	else if (ft->type == '%')
		ret = ft_per_print(ft);
	return (ret);
}

void	ft_return_ret(t_form_tag *ft, va_list ap, int *ret)
{
	int	temp;

	temp = ft_print_form(ft, ap);
	if (temp == -1)
		*ret = -2;
	else
		*ret += temp;
}

size_t	ft_parsing(const char *str, size_t i, va_list ap, int *ret)
{
	t_form_tag	*ft;

	ft = ft_malloc_ft();
	if (!ft)
		return (0);
	while (str[++i])
	{
		i = ft_flag(str, i, ft);
		i = ft_width(str, i, ft);
		if (str[i] == '.')
			i = ft_precision(str, i, ft);
		if (ft->width == -1 || ft->precision == -1)
			return (0);
		if (ft_is_type(str[i]))
		{
			ft->type = str[i];
			break ;
		}
		i++;
	}
	ft_return_ret(ft, ap, ret);
	i++;
	ft_free(ft->flags);
	ft_free(ft);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	i;
	int		*p;
	int		ret;

	va_start(ap, str);
	ret = 0;
	p = &ret;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i = ft_parsing(str, i, ap, p);
			if (!i)
				return (-1);
		}
		else
		{
			ft_putchar_fd(str[i++], 1);
			ret++;
		}
	}
	va_end(ap);
	return (ret);
}
