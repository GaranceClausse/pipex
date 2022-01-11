/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:07:12 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/11 18:35:51 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

char	*get_path(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5) != 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

char	*parse_path(char *path, char *cmd)
{
	char	**dir;
	char	*curr;
	int		i;

	i = 0;
	dir = ft_split(path, ':');
	while (dir[i])
	{
		if (cmd[0] == '/')
			curr = ft_strjoin(dir[i], cmd);
		else
			curr = ft_strjoin(ft_strjoin(dir[i], "/"), cmd);
		if (!access(curr, F_OK))
		{
			while (dir[i++])
			{
				free(dir[i]);
			}
			free(dir);
			return (curr);
		}
		i++;
		free(curr);
	}
	free(dir);
	return (NULL);
}
