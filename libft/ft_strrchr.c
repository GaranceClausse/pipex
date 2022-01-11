/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:06:31 by gclausse          #+#    #+#             */
/*   Updated: 2021/11/25 18:16:31 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	x;
	char	*str;

	i = ft_strlen(s);
	str = (char *)s;
	x = (char)c;
	while (i > 0 && str[i] != x)
		i--;
	if (i == 0 && str[i] != x)
		return (NULL);
	else
		return (&str[i]);
}
