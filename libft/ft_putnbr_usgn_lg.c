/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_usgn_lg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:50:10 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/11 13:13:53 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	putul(unsigned long int nbr, char *base)
{
	unsigned long int	nb2;
	int					cpt;

	cpt = 1;
	nb2 = (unsigned long int)nbr;
	if (nb2 < (unsigned long int)ft_strlen(base))
		ft_putchar_fd(base[nb2], 1);
	else
	{
		cpt += putul(nb2 / ft_strlen(base), base);
		ft_putchar_fd(base[nb2 % ft_strlen(base)], 1);
	}
	return (cpt);
}
