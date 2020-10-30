/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strduptab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 20:17:39 by rakrouna          #+#    #+#             */
/*   Updated: 2019/07/06 21:37:53 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strduptab(char **tab)
{
	int		i;
	char	**res;

	i = -1;
	if (!(res = malloc(sizeof(char*) * ft_tablen(tab) + 1)))
		return (NULL);
	while (tab[++i])
		res[i] = ft_strdup(tab[i]);
	res[i] = NULL;
	return (res);
}
