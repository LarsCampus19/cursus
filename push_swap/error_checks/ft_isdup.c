/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:39:37 by lpeeters          #+#    #+#             */
/*   Updated: 2023/03/17 05:14:26 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*compares two strings*/

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

/*checks for duplicates*/

int	ft_isdup(int ac, char **av)
{
	size_t	l;
	size_t	k;
	size_t	j;

	l = ac;
	k = 1;
	while (k < l)
	{
		j = k + 1;
		while (j < l)
		{
			if (!ft_strcmp(av[k], av[j]))
				return (1);
			j++;
		}
		k++;
	}
	return (0);
}
