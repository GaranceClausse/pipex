/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:32:53 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/10 18:15:57 by gclausse         ###   ########.fr       */
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

void	usage(void)
{
	write(2, "usage: ./pipex [file1] [cmd1] [cmd2] [file2]\n", 45);
	exit(EXIT_FAILURE);
}

void	terminate(char *m)
{
	int errsv;

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
	freesplit(cmd);
	exit(127);
}

void	freesplit(char **args)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (args[size])
		size++;
	while (i < size)
		free(args[i++]);
	free(args);
}

void	cmd1(int *pipefd, int *fd, char **argv, char **env)
{
	char	*path;
	char	**cmd1;
	pid_t	pid1;

	pid1 = fork();
	if (pid1 < 0)
		terminate("fork");
	if (pid1 == 0)
	{
		cmd1 = ft_split(argv[2], ' ');
		path = parse_path(get_path(env), cmd1[0]);
		fd[0] = open(argv[1], O_RDONLY);
		if (fd[0] < 0)
			terminate(argv[1]);
		close(pipefd[0]);
		dup2(fd[0], STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		if (!(cmd1[0] && path))
			cmd_not_found(cmd1);
		else		
		{
			execve(path, cmd1, env);
			freesplit(cmd1);
		}
	}
}

void	cmd2(int *pipefd, int *fd, char **argv, char **env)
{
	char	*path2;
	char	**cmd2;
	pid_t	pid2;

	pid2 = fork();
	if (pid2 < 0)
		terminate("fork");
	if (pid2 == 0)
	{
		cmd2 = ft_split(argv[3], ' ');
		path2 = parse_path(get_path(env), cmd2[0]);
		fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd[1] < 0)
			terminate(argv[4]);
		close(pipefd[1]);
		dup2(fd[1], STDOUT_FILENO);
		dup2(pipefd[0], STDIN_FILENO);
		if (!(cmd2[0] && path2))
			cmd_not_found(cmd2);
		else
		{
			execve(path2, cmd2, env);
			freesplit(cmd2);
		}
	}
}

int	main(int argc, char **argv, char **env)
{
	int	pipefd[2];
	int	fd[2];
	int	wstatus;

	errno = 0;
	if (argc != 5)
		usage();
	if (pipe(pipefd) < 0)
			terminate(NULL);
	cmd1(pipefd, fd, argv, env);
	cmd2(pipefd, fd, argv, env);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(-1, &wstatus, 0);
	waitpid(-1, &wstatus, 0);
	return (WEXITSTATUS(wstatus));	
}
