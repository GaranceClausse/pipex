/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:32:53 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/17 16:29:00 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"	
#include "libft/libft.h"

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
			freeall(cmd1, path, argv[1]);
		close(pipefd[0]);
		dup2(fd[0], STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		if (!(cmd1[0] && path))
			freeall(cmd1, path, NULL);
		else
		{
			execve(path, cmd1, env);
			freeall(cmd1, path, "can't execute");
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
	waitpid(0, NULL, 0);
	if (pid2 > 0)
	{
		cmd2 = ft_split(argv[3], ' ');
		path2 = parse_path(get_path(env), cmd2[0]);
		fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd[1] < 0)
			freeall(cmd2, path2, argv[4]);
		close(pipefd[1]);
		dup2(fd[1], STDOUT_FILENO);
		dup2(pipefd[0], STDIN_FILENO);
		if (!(cmd2[0] && path2))
			freeall(cmd2, path2, NULL);
		else
			execve(path2, cmd2, env);
		freeall(cmd2, path2, "can't execute");
	}
}

int	main(int argc, char **argv, char **env)
{
	int	pipefd[2];
	int	fd[2];
	int	wstatus;

	errno = 0;
	if (argc != 5 || argv[3][0] == '\0' || argv[2][0] == '\0')
		usage();
	if (pipe(pipefd) < 0)
		terminate(NULL);
	cmd1(pipefd, fd, argv, env);
	cmd2(pipefd, fd, argv, env);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(-1, &wstatus, 0);
	return (WEXITSTATUS(wstatus));
}
