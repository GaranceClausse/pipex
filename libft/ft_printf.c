/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:54:32 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/10 14:37:30 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

static int	ft_putstr(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
	if (s == NULL)
	{
		write(fd, "(null)", 6);
		i += 6;
	}
	return (i);
}

static int	func_printf(const char *str, int j, va_list *arg)
{
	int	i;

	i = 0;
	if (str[i + 1] == 'c')
		j = j + ft_putchar(va_arg(*arg, int), 1);
	else if (str[i + 1] == 's')
		j = j + ft_putstr(va_arg(*arg, char *), 1);
	else if (str[i + 1] == 'p')
	{
		ft_putstr("0x", 1);
		j += 2 + putul(va_arg(*arg, unsigned long int), "0123456789abcdef");
	}
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		j = j + ft_putnbr_base(va_arg(*arg, int), "0123456789");
	else if (str[i + 1] == 'u')
		j = j + putusg(va_arg(*arg, unsigned int), "0123456789");
	else if (str[i + 1] == 'x')
		j = j + putusg(va_arg(*arg, unsigned int), "0123456789abcdef");
	else if (str[i + 1] == 'X')
		j = j + putusg(va_arg(*arg, unsigned int), "0123456789ABCDEF");
	else if (str[i + 1] == '%')
		j = j + ft_putchar('%', 1);
	return (j);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		j;
	va_list	vl;

	va_start(vl, str);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] != '%' && str[i])
		{
			ft_putchar_fd(str[i], 1);
			i++;
			j++;
		}
		if (str[i] == '%')
		{
			j = func_printf(&str[i], j, &vl);
			i++;
		}
		if (str[i])
			i++;
	}
	va_end(vl);
	return (j);
}
