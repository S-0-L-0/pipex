/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:23:07 by edforte           #+#    #+#             */
/*   Updated: 2024/09/08 13:28:11 by edforte          ###   ########.fr       */
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
			return (end_program(errno));
	}
	waitpid(pid, NULL, 0);
	if (parent_process(av, fd, env) != 0)
			return (end_program(errno));
	return (0);
}

int	child_process(char **av, int *fd, char **env)
{
	int	file1;
	char	*path;
	char	*cmd;
	int	test = 0;

	file1 = open(av[1], O_RDONLY);
	if (file1 == -1)
		return(1);
	dup2(STDOUT_FILENO, fd[1]);
	dup2(STDIN_FILENO, file1);
	close(fd[0]);
	cmd = ft_strdup_mod(av[2]);
	path = find_path(env, cmd);
	free (cmd);
	if (path == NULL)
	{
		free(path);
		return (1);
	}
	printf("%s\n", path);
	free(path);
	
}

int	parent_process(char **av, int *fd, char **env)
{
}

char	*find_path(char **env, char *cmd)
{
	int		lines;
	char	*path;
	char	**all_path;

	lines = 0;
	while (ft_strncmp(env[lines], "PATH=", 5) != 0)
	{
		lines ++;
	}
	all_path = ft_split(env[lines] + 5, ':');
	lines = 0;
	while (all_path[lines])
	{
		all_path[lines] = ft_strjoin(all_path[lines], cmd);
		if (access(all_path[lines], F_OK | X_OK) == 0)
		{
			path = ft_strdup(all_path[lines]);
			free_matrix(all_path);
			return(path);
		}
		lines ++;
	}
	free_matrix(all_path);
	return (NULL);
}
