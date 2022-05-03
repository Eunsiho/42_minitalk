/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:48:38 by hogkim            #+#    #+#             */
/*   Updated: 2022/04/06 17:47:33 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_s_print2(char *s, char *temp, t_form_tag *ft, int ret)
{
	s = ft_cmp_width_calloc(ft, ft_strlen(temp));
	s = ft_fill_zero_space(s, ft, ft_strlen(temp));
	s = ft_flag_minus(s, ft, temp);
	ret = ft_putstr(s, 1);
	ft_free(s);
	return (ret);
}

int	ft_s_print(t_form_tag *ft, va_list ap)
{
	char	*temp;
	char	*s;
	int		ret;
	int		i;

	i = 0;
	s = NULL;
	temp = va_arg(ap, char *);
	ret = 0;
	if (!temp)
	{
		ret = ft_putstr("(null)", 1);
		return (ret);
	}
	if (ft->if_precision && ft->precision < ft_strlen(temp))
	{
		temp = ft_strndup(temp, ft->precision);
		i = 1;
	}
	ret = ft_s_print2(s, temp, ft, ret);
	if (i)
		ft_free(temp);
	return (ret);
}
