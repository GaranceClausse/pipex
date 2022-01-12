/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pbm_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:06:27 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/12 19:54:01 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

void	usage(void)
{
	write(2, "usage: ./pipex [file1] [cmd1] [cmd2] [file2]\n", 45);
	exit(EXIT_FAILURE);
}

void	terminate(char *m)
{
	int	errsv;

	errsv = errno;
	if (errno == 0)
		write(2, m, ft_strlen(m));
	else
		ft_printf("zsh: %s: %s\n", strerror(errsv), m);
	exit(EXIT_FAILURE);
}

void	cmd_not_found(char **cmd)
{
	write(2, "zsh: ", 6);
	write(2, "command not found : ", 20);
	write(2, cmd[0], ft_strlen(cmd[0]));
	write(2, "\n", 1);
	freetab(cmd);
	exit(127);
}

void	freetab(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

void	freeall(char **cmd, char *path, char *tab)
{
	if (tab)
	{
		freetab(cmd);
		free(path);
		terminate(tab);
	}
	else
	{
		free(path);
		cmd_not_found(cmd);
	}
}
