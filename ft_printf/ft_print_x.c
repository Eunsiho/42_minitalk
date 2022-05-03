/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:48:41 by hogkim            #+#    #+#             */
/*   Updated: 2022/04/06 17:53:53 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_x_precision(char *temp, t_form_tag *ft)
{
	char	*s;
	int		len;

	if (ft->if_precision)
	{
		len = ft_strlen(temp);
		if (ft->precision > len)
			len = ft->precision;
		s = ft_calloc(len + 1, sizeof(char));
		if (!s)
		{
			ft_free(temp);
			return (NULL);
		}
		s = ft_bzero_ascii(s, len);
		ft_strlcpy(&s[len - ft_strlen(temp)], temp, ft_strlen(temp) + 1);
		ft_free(temp);
		return (s);
	}
	return (temp);
}

int	ft_x_sharp(char *s, int nb, t_form_tag *ft)
{
	if (!s)
		return (-1);
	nb = 0;
	if (ft->type == 'x')
		ft_putstr("0x", 1);
	else
		ft_putstr("0X", 1);
	nb += 2;
	nb += ft_putstr(s, 1);
	ft_free(s);
	return (nb);
}

char	*ft_x_flags(char *s, char *temp, t_form_tag *ft)
{
	int		len;

	if (!s)
	{
		ft_free(temp);
		return (NULL);
	}
	len = ft_strlen(temp);
	if (ft_strchr(ft->flags, '-') && ft_strchr(ft->flags, '0'))
		s = ft_bspace(s, ft->width);
	if (ft_strchr(ft->flags, '-') || ft->width < len)
	{
		ft_strncpy(s, temp, len);
		ft_free(temp);
		return (s);
	}
	ft_strncpy(&s[ft->width - len], temp, len);
	ft_free(temp);
	return (s);
}

char	*ft_x_if_upper(t_form_tag *ft, unsigned int nb)
{
	char	*s;

	if (ft->type == 'X')
		s = ft_itoa_base(nb, "0123456789ABCDEF");
	else
		s = ft_itoa_base(nb, "0123456789abcdef");
	return (s);
}

int	ft_x_print(t_form_tag *ft, va_list ap)
{
	char			*s;
	char			*temp;
	unsigned int	nb;

	s = NULL;
	temp = va_arg(ap, void *);
	nb = (unsigned int)temp;
	if (!nb)
		temp = ft_strdup("0");
	else
		temp = ft_x_if_upper(ft, nb);
	if (!temp && ft->if_precision && ft->precision == 0)
		*s = 0;
	temp = ft_x_precision(temp, ft);
	s = ft_cmp_width_calloc(ft, ft_strlen(temp));
	s = ft_fill_zero_space(s, ft, ft_strlen(temp));
	s = ft_x_flags(s, temp, ft);
	if (ft_strchr(ft->flags, '#') && nb)
	{
		nb = ft_x_sharp(s, nb, ft);
		return (nb);
	}
	nb = ft_putstr(s, 1);
	ft_free(s);
	return (nb);
}
