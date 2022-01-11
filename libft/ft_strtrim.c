/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:26:05 by gclausse          #+#    #+#             */
/*   Updated: 2021/11/30 16:26:20 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_ocurence(char *str, char c)
{
	int	i;

	i = 0;
	if (c)
	{
		if (str[0] == '\0')
			return (0);
		while (str[i])
		{
			if (str[i] == c)
				return (1);
			i++;
		}
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;
	char	*sep;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	str = (char *)s1;
	sep = (char *)set;
	while (find_ocurence(sep, str[i]) == 1 && str[i])
		i++;
	while (find_ocurence(sep, str[j - 1]) == 1 && j > i)
		j--;
	return (ft_substr(str, i, (j - i)));
}
