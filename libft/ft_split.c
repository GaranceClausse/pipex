/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:27:26 by gclausse          #+#    #+#             */
/*   Updated: 2021/11/30 16:39:35 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static void	**malloc_pbm(char *cpy)
{
	free(cpy);
	return (NULL);
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
				while (j >= 0)
					malloc_pbm(cpy[j--]);
			else
				j++;
		}
		i = i + (numlet(&s[i], c)) + (s[i] == c);
	}
	cpy[j] = NULL;
	return (cpy);
}
