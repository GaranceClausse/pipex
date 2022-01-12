/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:27:26 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/12 11:45:07 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static int	numlet(const char *str, char c)
{
	int	i;
	int	cpt;

	i = 0;
	cpt = 0;
	if (c == '\0')
		return (ft_strlen(str));
	while (str[i] != c && str[i])
	{
		i++;
		cpt++;
	}
	return (cpt);
}

static int	num_of_word(const char *s, char c)
{
	int		i;
	int		cpt;
	char	*str;

	i = 0;
	cpt = 1;
	if (c == '\0')
		return (0);
	str = ft_strtrim(s, &c);
	if (str)
	{
		while (str[i])
		{
			while (str[i + 1] == c)
				i++;
			if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
				cpt++;
			i++;
		}
		free(str);
		return (cpt);
	}
	else
		return (0);
}

static char	*create_word(const char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (numlet(&s[i], c) + 1));
	if (!str)
		return (NULL);
	while (s[i] != c && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	malloc_pbm(char **cpy, int j)
{
	while(j >= 0)
	{
		free(cpy[j--]);
	}
	free(cpy);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		j;
	char	**cpy;

	cpy = malloc(sizeof(char *) * (num_of_word(s, c) + 1));
	if (!cpy || !s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && j <= num_of_word(s, c))
	{
		if (s[i] != c && s[i])
		{
			cpy[j] = create_word(&s[i], c);
			if (cpy[j] == NULL)
				malloc_pbm(cpy, j);
			else
				j++;
		}
		i = i + (numlet(&s[i], c)) + (s[i] == c);
	}
	if (cpy)
	cpy[j] = NULL;
	return (cpy);
}*/

static int	word_count(char const *s, char c)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			res += 1;
		i++;
	}
	return (res);
}

static char	*tablloc(char const *s, char c, int *i)
{
	char		*res;
	int			j;

	j = *i;
	while (s[j] == c)
		j++;
	*i = j;
	while (s[j] != '\0' && s[j] != c)
		j++;
	res = (char *)malloc((j - *i + 1) * sizeof(char));
	if (!res)
		return (NULL);
	j = 0;
	while (s[*i] != '\0' && s[*i] != c)
	{
		res[j] = s[*i];
		*i += 1;
		j++;
	}
	res[j] = '\0';
	return (res);
}

static void	*free_all(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		mots;
	int		j;
	int		i;
	int		*pi;

	if (!s)
		return (NULL);
	i = 0;
	pi = &i;
	mots = word_count(s, c);
	j = 0;
	res = malloc((mots + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (j < mots)
	{
		res[j] = tablloc(s, c, pi);
		if (!res[j])
			return (free_all(res));
		j++;
	}
	res[mots] = NULL;
	return (res);
}
