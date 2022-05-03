/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:48:35 by hogkim            #+#    #+#             */
/*   Updated: 2022/04/06 17:44:49 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_p_flags(char *s, char *temp, char *flags, size_t width)
{
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(temp);
	if (ft_strchr(flags, '-') && ft_strchr(flags, '0'))
		s = ft_bspace(s, width);
	if (ft_strchr(flags, '-') || ft_strchr(flags, '0') || width < len + 2)
	{
		s[0] = '0';
		s[1] = 'x';
		ft_strncpy(&s[2], temp, len);
		ft_free(temp);
		return (s);
	}
	else
	{
		s[width - len - 2] = '0';
		s[width - len - 1] = 'x';
	}
	ft_strncpy(&s[width - len], temp, len);
	free(temp);
	return (s);
}

int	ft_p_print(t_form_tag *ft, va_list ap)
{
	char					*s;
	char					*temp;
	unsigned long long int	nb;
	int						ret;

	ret = 0;
	s = NULL;
	temp = va_arg(ap, void *);
	nb = (unsigned long long int)temp;
	if (!temp)
		temp = ft_strdup("0");
	else
		temp = ft_itoa_base(nb, "0123456789abcdef");
	if (!temp && ft->if_precision && ft->precision == 0)
		*s = 0;
	s = ft_cmp_width_calloc(ft, ft_strlen(temp) + 2);
	s = ft_fill_zero_space(s, ft, ft_strlen(temp));
	s = ft_p_flags(s, temp, ft->flags, ft->width);
	ret = ft_putstr(s, 1);
	ft_free(s);
	return (ret);
}
