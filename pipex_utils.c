/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:10:15 by edforte           #+#    #+#             */
/*   Updated: 2024/08/30 18:57:53 by edforte          ###   ########.fr       */
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
		return (end_program(errno));
	if (access(av[4], F_OK) == 0)
	{
		if (access(av[4], R_OK | W_OK) == -1)
			return (end_program(errno));
	}
	return (0);
}

int	end_program(int errno)
{
	ft_printf("Error\n %s\n", strerror(errno));
	return (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*strres;
	int		i;
	int		j;
	int		len_max;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	len_max = ((ft_strlen(s1) + ft_strlen(s2)) + 1);
	strres = (char *) malloc(len_max * sizeof(char));
	if (!strres)
		return (NULL);
	while (s1[i])
	{
		strres[i] = s1[i];
		i ++;
	}
	while (s2[j])
		strres[i++] = s2[j++];
	strres[i] = '\0';
	free((char *)s1);
	return (strres);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while ((a[i] || b[i]) && i < n)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i ++;
	}
	return (0);
}

char	*ft_strdup_mod(const char *s1)
{
	char	*s2;
	size_t	i;

	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!s2)
		return (0);
	s2[0] = '/'; 
	i = 1;
	while (s1[i])
	{
		s2[i] = s1[i];
		i ++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s2)
		return (0);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i ++;
	}
	s2[i] = '\0';
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
