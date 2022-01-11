/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_unsgn.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:26:29 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/10 14:36:43 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	putusg(unsigned int nbr, char *base)
{
	int			j;
	long int	nb2;
	int			cpt;

	j = 0;
	cpt = 1;
	if (nbr < 0)
		nb2 = nbr + 2147483648;
	else
		nb2 = nbr;
	if (nb2 < (long)ft_strlen(base))
		ft_putchar_fd(base[nb2], 1);
	else
	{
		cpt += putusg(nb2 / ft_strlen(base), base);
		ft_putchar_fd(base[nb2 % ft_strlen(base)], 1);
	}
	if (nbr < 0)
		cpt -= 2;
	return (cpt);
}
