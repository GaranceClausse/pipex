/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_unsgn.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:26:29 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/11 13:15:16 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	putusg(unsigned int nbr, char *base)
{
	long int	nb2;
	int			cpt;

	cpt = 1;
	nb2 = nbr;
	if (nb2 < (long)ft_strlen(base))
		ft_putchar_fd(base[nb2], 1);
	else
	{
		cpt += putusg(nb2 / ft_strlen(base), base);
		ft_putchar_fd(base[nb2 % ft_strlen(base)], 1);
	}
	return (cpt);
}
