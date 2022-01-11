/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:49:43 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/10 17:55:16 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <libc.h>
#include <errno.h>
#include "libft/libft.h"

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
void	freesplit(char **args);
void	usage(void);
void	terminate(char *m);


#endif
