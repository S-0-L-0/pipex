/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:23:07 by edforte           #+#    #+#             */
/*   Updated: 2024/09/10 18:31:36 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (input_check(ac, av) != 0)
	{
		return (1);
	}
	if (pipe(fd) != 0)
		return (end_program(errno));
	pid = fork();
	if (pid == -1)
		return (end_program(errno));
	else if (pid == 0)
	{
		if (child_process(av, fd, env) != 0)
		{
			return (end_program(errno));
		}
	}
	waitpid(pid, NULL, 0);
	if (parent_process(av, fd, env) != 0)
			return (end_program(errno));
	return (0);
}

int	child_process(char **av, int *fd, char **env)
{
	int		file;
	char	*path;
	char	**cmd;

	file = open(av[1], O_RDONLY);
	if (file == -1)
		return(1);
	dup2(fd[1], STDOUT_FILENO);
	dup2(file, STDIN_FILENO);
	close(fd[0]);
	cmd = ft_split(av[2], ' ');
	path = find_path(env, cmd[0]);
	if (path == NULL)
	{
		free(path);
		return (1);
	}
	execve(path, cmd, env);
	free(path);
	free_matrix(cmd);
	return(1);
}

int	parent_process(char **av, int *fd, char **env)
{
	int		file;
	char	*path;
	char	**cmd;

	file = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file == -1)
		return(1);
	dup2(fd[0], STDIN_FILENO);
	dup2(file, STDOUT_FILENO);
	close(fd[1]);
	cmd = ft_split(av[3], ' ');
	path = find_path(env, cmd[0]);
	if (path == NULL)
	{
		free(path);
		return (1);
	}
	execve(path, cmd, env);
	free(path);
	free_matrix(cmd);
	return(1);
}
