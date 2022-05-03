/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:47:14 by hogkim            #+#    #+#             */
/*   Updated: 2022/04/07 13:26:07 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_form_tag	*ft_malloc_ft(void)
{
	t_form_tag	*new;

	new = (t_form_tag *)malloc(sizeof(t_form_tag));
	if (!new)
		return (NULL);
	new->flags = ft_calloc(7 + 1, sizeof(char));
	if (!(new->flags))
	{
		free(new);
		return (NULL);
	}
	new->width = 0;
	new->precision = 0;
	new->if_precision = 0;
	new->type = 0;
	new->ret = 0;
	return (new);
}

int	ft_putstr(char *s, int fd)
{
	int	ret;

	ret = ft_strlen(s);
	if (!s)
		return (-1);
	write(fd, s, ft_strlen(s));
	return (ret);
}

char	*ft_strncpy(char *dst, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char	*ft_strndup(char *s, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[n] = 0;
	return (str);
}

int	ft_malatoi(const char *str, size_t count)
{	
	char	*width;
	int		n;

	if (count == 0)
		return (0);
	width = (char *)malloc(sizeof(char) * (count + 1));
	if (!width)
		return (-1);
	ft_strlcpy(width, str, count + 1);
	n = ft_atoi(width);
	free(width);
	return (n);
}
