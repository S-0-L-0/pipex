/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:10:15 by edforte           #+#    #+#             */
/*   Updated: 2024/09/10 16:49:27 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	input_check(int ac, char **av)
{
	if (ac != 5)
	{
		perror("invalid number of parameters.");
		return(1);
	}
	if (access(av[1], F_OK | R_OK) == -1)
	{
		return (end_program(errno));
	}
	if (access(av[4], F_OK) == 0)
	{
		if (access(av[4], R_OK | W_OK) == -1)
			return (end_program(errno));
	}
	return (0);
}

int	end_program(int err_code)
{
	ft_printf("Error: %s\n", strerror(err_code));
	return (1);
}

char	*slash_adder(char *s1)
{
	char	*s2;
	char	*slash;
	
	slash = ft_strdup("/");
	s2 = ft_strjoin(slash, s1);
	return (s2);
}

void	free_matrix(char **matrix)
{
	int	rows;

	rows = 0;
	while (matrix[rows])
	{
		free(matrix[rows]);
		rows ++;
	}
	free(matrix);
}
