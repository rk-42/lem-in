/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 14:54:24 by rakrouna          #+#    #+#             */
/*   Updated: 2019/05/18 15:27:51 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_get_table(int *pos, int sizev, int sizeh, char **tab)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	if (!(res = malloc(sizeof(char *) * sizev + 1)))
		return (NULL);
	i = 0;
	while (i < sizev)
	{
		j = 0;
		k = pos[1];
		if (!(res[i] = malloc(sizeof(char) * sizeh + 1)))
			return (NULL);
		while (j < sizeh)
		{
			res[i][j] = tab[pos[0]][k];
			k++;
			j++;
		}
		res[i++][j] = '\0';
		pos[0]++;
	}
	res[i] = NULL;
	return (res);
}
