/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:49:44 by hogkim            #+#    #+#             */
/*   Updated: 2022/04/06 18:05:28 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_is_flag(char c)
{
	size_t	i;
	char	*flags;

	flags = "-+0 #";
	i = 0;
	while (flags[i])
	{
		if (flags[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_is_type(char c)
{
	size_t	i;
	char	*types;

	types = "cspdiuxX%";
	i = 0;
	while (types[i])
	{
		if (types[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_precision(const char *str, size_t i, t_form_tag *ft)
{
	size_t	count;

	i++;
	ft->if_precision = 1;
	count = 0;
	while (ft_isdigit(str[i]))
	{
		count++;
		i++;
	}
	ft->precision = ft_malatoi(&str[i - count], count);
	return (i);
}

size_t	ft_width(const char *str, size_t i, t_form_tag *ft)
{
	size_t	count;

	count = 0;
	while (ft_isdigit(str[i]))
	{
		count++;
		i++;
	}
	ft->width = ft_malatoi(&str[i - count], count);
	return (i);
}

size_t	ft_flag(const char *str, size_t i, t_form_tag *ft)
{
	size_t	flag_i;

	flag_i = 0;
	while (ft_is_flag(str[i]))
	{
		if (!ft_strchr(ft->flags, str[i]))
		{
			ft->flags[flag_i] = str[i];
			flag_i++;
			i++;
		}
		else
			i++;
	}
	return (i);
}
