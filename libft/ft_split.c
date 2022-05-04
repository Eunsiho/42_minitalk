/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:12:14 by hogkim            #+#    #+#             */
/*   Updated: 2022/01/08 13:21:16 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**words_clear(char **words)
{
	size_t	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
	return (NULL);
}

size_t	word_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] && s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

char	**words_dup(char const *s, char c, char **words)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (s[i] && j < word_count(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		len = 0;
		while (s[i] && s[i] != c)
		{
			len++;
			i++;
		}
		words[j] = (char *)malloc(sizeof(char) * (len + 1));
		if (!words[j])
		{
			words_clear(words);
			return (NULL);
		}
		ft_strlcpy(words[j++], s + (i - len), len + 1);
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	count;

	if (!s)
		return (NULL);
	count = word_count(s, c);
	words = (char **)malloc(sizeof(char *) * (count + 1));
	if (!words)
		return (NULL);
	words = words_dup(s, c, words);
	if (!words)
		return (NULL);
	words[count] = NULL;
	return (words);
}
