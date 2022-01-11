/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_usgn_lg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:50:10 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/10 14:36:55 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	putul(unsigned long int nbr, char *base)
{
	int					j;
	unsigned long int	nb2;
	int					cpt;

	j = 0;
	cpt = 1;
	if (nbr < 0)
		nb2 = nbr + 2147483648;
	else
		nb2 = (unsigned long int)nbr;
	if (nb2 < (unsigned long int)ft_strlen(base))
		ft_putchar_fd(base[nb2], 1);
	else
	{
		cpt += putul(nb2 / ft_strlen(base), base);
		ft_putchar_fd(base[nb2 % ft_strlen(base)], 1);
	}
	if (nbr < 0)
		cpt -= 2;
	return (cpt);
}
