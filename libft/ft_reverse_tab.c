/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 17:47:55 by rakrouna          #+#    #+#             */
/*   Updated: 2019/11/15 21:48:05 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_reverse_tab(char **tab)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	if (!tab || !*tab)
		return (tab);
	while (tab[j])
		j++;
	j--;
	while (i <= j)
	{
		s = tab[j];
		tab[j] = tab[i];
		tab[i] = s;
		j--;
		i++;
	}
	return (tab);
}
