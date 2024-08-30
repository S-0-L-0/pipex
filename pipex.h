/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:38:41 by edforte           #+#    #+#             */
/*   Updated: 2024/08/30 18:58:06 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/types.h>
# include <errno.h>
# include "ft_printf/ft_printf.h"

int		input_check(int ac, char **av);
int		end_program(int errno);
int		child_process(char **av, int *fd, char** env);
int		parent_process(char **av, int *fd, char **env);
char	*ft_strjoin(char *s1, char *s2);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*find_path(char **env, char *cmd);
char	*ft_strdup(const char *s1);
char	*ft_strdup_mod(const char *s1);
void	free_matrix(char **matrix);


#endif