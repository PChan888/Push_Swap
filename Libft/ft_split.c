/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 22:02:19 by kaichan           #+#    #+#             */
/*   Updated: 2025/09/26 01:27:09 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// counts how many words are in the string
static int	word_count(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

// word_in figures out the input for the substr
// where the start of the string is
// and whats the length of the the string
// then also iterates through the index of the words which is the wordex
static void	word_in(char **worddex, const char *s, char c)
{
	const char	*wordstart;
	int			wordlen;

	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			wordstart = s;
			wordlen = 0;
			while (*s && *s != c)
			{
				wordlen++;
				s++;
			}
			*worddex = ft_substr(wordstart, 0, wordlen);
			worddex++;
		}
	}
	*worddex = NULL;
}

// ft_split seperates the string at the points of the where char c is shown
char	**ft_split(const char *s, char c)
{
	char	**new;
	int		size;

	if (!s)
		return (NULL);
	size = word_count (s, c);
	new = malloc((size + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	word_in (new, s, c);
	return (new);
}

// static char	*ft_substr(const char *s, int start, int end)
// {
// 	char	*word;
// 	int		i;
//
// 	i = 0;
// 	word = (char *)malloc(sizeof(char) * (end - start + 1));
// 	if (!word)
// 		return (NULL);
// 	while (start < end)
// 		word[i++] = s[start++];
// 	word[i] = '\0';
// 	return (word);
// }