/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:51:30 by gclausse          #+#    #+#             */
/*   Updated: 2021/11/30 15:53:43 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*csrc;
	char	*move;

	i = 0;
	csrc = (char *)src;
	move = (char *)dst;
	if (!dst && !src)
		return (NULL);
	if (src == dst)
		return (dst);
	if (src < dst && dst < src + len)
	{
		while (len--)
			move[len] = csrc[len];
	}
	else
	{
		while (i < len)
		{
			move[i] = csrc[i];
			i++;
		}
	}
	return (move);
}
