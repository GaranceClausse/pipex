/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:49:43 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/11 18:18:04 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include "libft/libft.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define INFILE 0
# define OUTFILE 1

char	*get_path(char **env);
char	*parse_path(char *path, char *cmd);
void	cmd1(int *pipefd, int *fd, char **argv, char **env);
void	cmd2(int *pipefd, int *fd, char **argv, char **env);
void	cmd_not_found(char **cmd);
void	freetab(char **args);
void	usage(void);
void	terminate(char *m);
void	freeall(char **cmd, char *path, char *tab);

#endif
