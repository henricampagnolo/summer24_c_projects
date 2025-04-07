/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:31:33 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/18 22:53:10 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static void	fill_word(char *destc, char const *scur, char c, int *current_pos)
{
	while (*scur != c)
	{
		destc[*current_pos] = *scur;
		scur++;
		*current_pos += 1;
	}
	destc[*current_pos] = 0;
	*current_pos += 1;
}

static void	fill_array(char **dest, char const *s, char c, int words)
{
	int		i;
	int		word;
	int		pos;
	int		size;
	char	*start_char;

	start_char = (char *) dest + (words + 1) * sizeof(char *);
	i = 0;
	word = 0;
	pos = 0;
	while (s[i] != 0)
	{
		if (s[i] != c)
		{
			dest[word] = start_char + pos;
			word++;
			size = -pos;
			fill_word(start_char, s + i, c, &pos);
			size += pos;
			i += size;
		}
		else
			i++;
	}
	dest[word] = 0;
}

static char	**get_size_and_words(char const *s, char c, int *ws, int *sz)
{
	int		i;
	int		was_in_word;
	char	**dest;

	i = 0;
	*ws = 0;
	*sz = 0;
	was_in_word = 0;
	while (s[i] != 0)
	{
		if ((s[i] == c) && was_in_word == 1)
			was_in_word = 0;
		if ((s[i] != c) && was_in_word == 0)
			*ws += 1;
		if ((s[i] != c))
		{
			was_in_word = 1;
			*sz += 1;
		}
		i++;
	}
	dest = malloc(sizeof(char *) * (*ws + 1) + sizeof(char) * (*sz + *ws));
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	int		size;
	char	**dest;

	dest = get_size_and_words(s, c, &words, &size);
	if (dest == 0)
		return (0);
	fill_array(dest, s, c, words);
	return (dest);
}
*/

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	size_t	word_len;
	int		i;

	lst = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!s || !lst)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			lst[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	lst[i] = NULL;
	return (lst);
}
