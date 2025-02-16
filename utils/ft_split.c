/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:16:27 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/16 17:40:43 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static int	is_sep(char a, char c)
{
	return (a == c);
}

static size_t	word_count(const char *str, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (!is_sep(str[i], c) && (is_sep(str[i + 1], c) || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	*word_alloc(const char *str, char c)
{
	char	*word;
	size_t	i;

	i = 0;
	while (str[i] && !is_sep(str[i], c))
		i++;
	word = malloc((i + 1) * sizeof(char));
	i = 0;
	while (str[i] && !is_sep(str[i], c))
	{
		word[i] = ((char *)str)[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	*free_all(char **sp, int index)
{
	int	i;

	i = 0;
	while (index >= 0)
	{
		free(sp[i]);
		i--;
	}
	free(sp);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**sp;

	if (!s)
		return (NULL);
	sp = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!sp)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && is_sep(*s, c))
			s++;
		if (*s && !is_sep(*s, c))
		{
			sp[i] = word_alloc(s, c);
			if (!sp[i])
				return (free_all(sp, i));
			i++;
			while (*s && !is_sep(*s, c))
				s++;
		}
	}
	sp[i] = NULL;
	return (sp);
}
