/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:32:53 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/08 20:16:14 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **env)
{
	int		i;

	i = -1;
	while (env[++i])
	{
		if (ft_strnstr(env[i], "PATH", 10000) != 0)
			return (env[i] + 5);
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
			return (curr);
		i++;
	}
	return (NULL);
}

void	cmd1(char **argv, char **env, int *fd)
{
	int		file;
	char	*path;
	char	**cmd1;

	close(fd[0]);
	cmd1 = ft_split(argv[2], ' ');
	path = parse_path(get_path(env), cmd1[0]);
	file = open(argv[1], O_RDONLY, 0777);
	if (file == -1)
		exit (errno);
	dup2(file, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(file);
	execve(path, cmd1, env);
}

void	cmd2(char **argv, char **env, int *fd)
{
	int		file2;
	char	*path2;
	char	**cmd2;

	close(fd[1]);
	cmd2 = ft_split(argv[3], ' ');
	path2 = parse_path(get_path(env), cmd2[0]);
	file2 = open(argv[4], O_WRONLY | O_CREAT, 0777);
	if (file2 == -1)
		exit (errno);
	dup2(file2, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(file2);
	execve(path2, cmd2, env);
}

int	main(int argc, char **argv, char **env)
{
	pid_t	pid1;
	pid_t	pid2;
	int		wstatus;
	int		fd[2];

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			return (1);
		pid1 = fork();
		if (pid1 < 0)
			return (2);
		wstatus = 0;
		if (pid1 == 0) //child process
			cmd1(argv, env, fd);
		if (pid1 > 0) //parent process
		{
			close(fd[1]);
			pid2 = fork();
			if (pid2 == 0) // new child
				cmd2(argv, env, fd);
			else // still parent
			{
				waitpid(pid1, &wstatus, 0);
				waitpid(pid2, &wstatus, 0);
				close(fd[1]);
				close(fd[0]);
			}
		}
	}
}
