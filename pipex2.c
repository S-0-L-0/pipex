/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:50:50 by edforte           #+#    #+#             */
/*   Updated: 2024/09/10 17:04:45 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **env, char *cmd)
{
	int		lines;
	char	*path;
	char	**all_path;

	lines = 0;
	cmd = slash_adder(cmd);
	while (ft_strncmp(env[lines], "PATH=", 5) != 0)
		lines ++;
	all_path = ft_split(env[lines] + 5, ':');
	lines = 0;
	while (all_path[lines])
	{
		all_path[lines] = ft_strjoin(all_path[lines], cmd);
		if (access(all_path[lines], F_OK | X_OK) == 0)
		{
			path = ft_strdup(all_path[lines]);
			free_matrix(all_path);
			free(cmd);
			return(path);
		}
		lines ++;
	}
	free(cmd);
	free_matrix(all_path);
	return (NULL);
}

void	cmd_exe(char *path, char *flag, char **env)
{
	
}