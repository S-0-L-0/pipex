/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:47:07 by edforte           #+#    #+#             */
/*   Updated: 2024/09/10 16:50:03 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
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
