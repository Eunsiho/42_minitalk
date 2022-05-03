/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_per.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 23:58:25 by hogkim            #+#    #+#             */
/*   Updated: 2022/04/06 17:47:22 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_per_print(t_form_tag *ft)
{
	char	*s;
	char	c;
	int		ret;

	c = '%';
	ret = 0;
	if (ft->width > 1)
	{
		s = ft_cmp_width_calloc(ft, 1);
		s = ft_fill_zero_space(s, ft, 1);
		if (ft_strchr(ft->flags, '-'))
		{
			s = ft_bspace(s, ft->width);
			if (s)
				s[0] = c;
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
