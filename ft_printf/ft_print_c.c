/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:48:26 by hogkim            #+#    #+#             */
/*   Updated: 2022/04/06 17:28:23 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_c_minus(t_form_tag *ft, char *s, char c, int ret)
{
	char	*temp;

	if (!s)
		return (-1);
	ft_free(s);
	ft_putchar_fd(c, 1);
	ret++;
	temp = ft_calloc(ft->width, sizeof(char));
	if (!temp)
		return (-1);
	temp = ft_bspace(temp, ft->width - 1);
	ret += ft_putstr(temp, 1);
	ft_free(temp);
	return (ret);
}

int	ft_c_print(t_form_tag *ft, va_list ap)
{
	char	*s;
	char	c;
	int		ret;

	c = va_arg(ap, int);
	ret = 0;
	if (ft->width > 1)
	{
		s = ft_cmp_width_calloc(ft, 1);
		s = ft_fill_zero_space(s, ft, 1);
		if (ft_strchr(ft->flags, '-'))
		{
			ret = ft_c_minus(ft, s, c, ret);
			return (ret);
		}
		else
			s[ft->width - 1] = c;
		ret = ft_putstr(s, 1);
		ft_free(s);
		return (ret);
	}
	ft_putchar_fd(c, 1);
	ret++;
	return (ret);
}
