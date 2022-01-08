/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:32:53 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/08 17:17:02 by gclausse         ###   ########.fr       */
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
		child1
	}
	if (pid1 > 0) //parent process
	{
		pid2 = fork();
		if (pid2 == 0) // new child
		{

		}
		else // still parent
		{
			int	wstatus;


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
