/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:32:53 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/10 12:28:36 by gclausse         ###   ########.fr       */
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

void	cmd1(int *pipefd, int *fd, char **argv, char **env)
{
	char	*path;
	char	**cmd1;
	pid_t	pid1;

	pid1 = fork();
	if (pid1 < 0)
		exit (errno);
	if (pid1 == 0)
	{
		cmd1 = ft_split(argv[2], ' ');
		path = parse_path(get_path(env), cmd1[0]);
		fd[0] = open(argv[1], O_RDONLY, 0644);
		if (fd[0] == -1)
		{
			if (errno == 0)
				write(2, "Error\n", 6);
			else
				perror(argv[1]);
			exit(EXIT_FAILURE);
		}
		close(pipefd[0]);
		dup2(fd[0], STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		execve(path, cmd1, env);
	}
}

void	cmd2(int *pipefd, int *fd, char **argv, char **env)
{
	char	*path2;
	char	**cmd2;
	pid_t	pid2;

	errno = 0;
	pid2 = fork();
	if (pid2 < 0)
		exit (errno);
	if (pid2 == 0)
	{
		cmd2 = ft_split(argv[3], ' ');
		path2 = parse_path(get_path(env), cmd2[0]);
		fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd[1] == -1)
		{
			if (errno == 0)
				write(2, "Error\n", 6);
			else
				perror(argv[4]);
			exit(EXIT_FAILURE);
		}
		close(pipefd[1]);
		dup2(fd[1], STDOUT_FILENO);
		dup2(pipefd[0], STDIN_FILENO);
		execve(path2, cmd2, env);
	}
}

int	main(int argc, char **argv, char **env)
{
	int	wstatus;
	int	pipefd[2];
	int	fd[2];

	if (argc == 5)
	{
		if (pipe(pipefd) == -1)
			exit (errno);
		cmd1(pipefd, fd, argv, env);
		cmd2(pipefd, fd, argv, env);
		close(pipefd[0]);
		close(pipefd[1]);
		waitpid(-1, &wstatus, 0);
		waitpid(-1, &wstatus, 0);
	}
	else
		write (1, "pbm", 3);
	return (0);	
}
