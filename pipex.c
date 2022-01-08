/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:32:53 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/08 18:00:12 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];

	pipe(fd);
	if (pipe(fd) == -1)
		return 1;
	pid1 = fork();
	if (pid1 < 0)
		return 2;
	if (pid1 == 0) //child process
	{
		int	file;
		int	cmd1;

		file = open(argv[1], O_WRONLY, 0777);
		if (file == -1)
			exit (errno);
		cmd1 = dup2(file, 1);
		execve(path, ft_split(argv[2]), env);
	}
	if (pid1 > 0) //parent process
	{
		pid2 = fork();
		if (pid2 == 0) // new child
		{
			int	file2;
			int	cmd2;

			file2 = open(1, O_WRONLY, 0777);
			if (file2 == -1)
				exit (errno);
			cmd2 = dup2(file2, 1);
			execve(path, ft_split(argv[3]), env);
		}
		else // still parent
		{
			int	wstatus;
			int	output;

			output = open(argv[4], O_WRONLY | O_CREATE, 0777);
			if (output == - 1)
			{
				exit (errno);
			}
			waitpid(pid1, &wstatus, NULL);
			waitpid(pid2, &wstatus, NULL);
			if (write(fd[1], &fd[0], sizeof(int)) == -1)
			{
				printf("pbm");
				return 2;
			}
			close(fd[1]);
			close(fd[0]);
		}

	}

}
