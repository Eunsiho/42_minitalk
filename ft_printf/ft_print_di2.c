/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:48:30 by hogkim            #+#    #+#             */
/*   Updated: 2022/04/06 17:32:49 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_di_sign_minus(char *s, char *temp, size_t len, t_form_tag *ft)
{
	if (ft_strchr(ft->flags, '-'))
		ft_strncpy(s, temp, ft_strlen(temp));
	else
		ft_strncpy(&s[len - ft_strlen(temp)], temp, ft_strlen(temp));
}

void	ft_di_sign_zero(char *s, char *temp, size_t len)
{
	s[0] = ' ';
	s[len - ft_strlen(temp) - 1] = '-';
}

char	*ft_di_sign(char *s, char *temp, t_form_tag *ft, int sign)
{
	size_t	len;
	size_t	temp_len;

	if (!s)
		return (NULL);
	temp_len = ft_strlen(temp);
	len = ft->width;
	if (len < temp_len)
		len = temp_len;
	if (sign == -1)
	{
		s[0] = '-';
		if (ft_strchr(ft->flags, '-'))
			ft_strncpy(&s[0], temp, temp_len);
		else
		{
			ft_strncpy(&s[len - temp_len + 1], temp + 1, temp_len - 1);
			if (!ft_strchr(ft->flags, '0') && len > temp_len)
				ft_di_sign_zero(s, temp, len);
		}
	}
	else
		ft_di_sign_minus(s, temp, len, ft);
	free(temp);
	return (s);
}

char	*ft_di_width(char *temp, t_form_tag *ft)
{
	char	*s;
	int		len;

	if (!temp)
		return (NULL);
	len = ft_strlen(temp);
	if (ft->width > len)
		len = ft->width;
	s = ft_calloc(len + 1, sizeof(char));
	s = ft_fill_zero_space(s, ft, len);
	if (ft_strchr(ft->flags, '-'))
		ft_bspace(s, ft_strlen(s));
	return (s);
}

char	*ft_di_precision(char *temp, t_form_tag *ft, int sign)
{
	char	*s;
	int		len;

	if (!temp)
		return (NULL);
	len = ft_strlen(temp);
	if (ft->precision > len)
		len = ft->precision;
	if (sign == -1)
	{
		s = ft_calloc(len + 2, sizeof(char));
		s = ft_bzero_ascii(s, len + 1);
		s[0] = '-';
		ft_strlcpy(&s[1 + len - ft_strlen(temp)], temp, ft_strlen(temp) + 1);
	}
	else
	{
		s = ft_calloc(len + 1, sizeof(char));
		s = ft_bzero_ascii(s, len);
		ft_strlcpy(&s[len - ft_strlen(temp)], temp, ft_strlen(temp) + 1);
	}
	free(temp);
	return (s);
}
