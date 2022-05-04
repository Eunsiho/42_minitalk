/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:37:04 by hogkim            #+#    #+#             */
/*   Updated: 2022/04/07 13:50:25 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_flag_minus(char *s, t_form_tag *ft, char *temp)
{
	if (!s)
		return (NULL);
	if (ft_strchr(ft->flags, '-'))
	{
		s = ft_bspace(s, ft->width);
		ft_strncpy(s, temp, ft_strlen(temp));
	}
	else if (ft->width < ft_strlen(temp))
		ft_strncpy(s, temp, ft_strlen(temp));
	else
		ft_strncpy(&s[ft->width - ft_strlen(temp)], temp, ft_strlen(temp));
	return (s);
}

char	*ft_fill_zero_space(char *s, t_form_tag *ft, size_t len)
{
	size_t	n;

	if (!s)
		return (NULL);
	n = ft->width;
	if (n < len)
		n = len;
	if (ft_strchr(ft->flags, '0'))
		s = ft_bzero_ascii(s, n);
	else
		s = ft_bspace(s, n);
	return (s);
}

char	*ft_cmp_width_calloc(t_form_tag *ft, int len)
{
	char	*s;

	if (ft->width > len)
		s = ft_calloc(ft->width + 1, sizeof(char));
	else
		s = ft_calloc(len + 1, sizeof(char));
	if (!s)
		return (NULL);
	return (s);
}

void	ft_free(void *s)
{
	if (s)
		free(s);
}
