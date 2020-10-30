/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rech_dichotomique.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 13:37:33 by rakrouna          #+#    #+#             */
/*   Updated: 2019/04/14 21:49:34 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_len_tab(char **tab)
{
	int			i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int				ft_rech_dichotomique(char *s, char **tab)
{
	int			d;
	int			f;
	int			mid;

	d = 0;
	f = ft_len_tab(tab) - 1;
	mid = 0;
	while (d <= f && (ft_strcmp(s, tab[mid]) != 0))
	{
		mid = (d + f) / 2;
		if (ft_strcmp(s, tab[mid]) < 0)
			f = mid - 1;
		else
			d = mid + 1;
	}
	if (ft_strcmp(s, tab[mid]) == 0)
		return (mid);
	return (-1);
}
