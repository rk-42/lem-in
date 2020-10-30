/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_bulle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:49:12 by rakrouna          #+#    #+#             */
/*   Updated: 2019/06/25 18:55:29 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_tri_bulle(char **tab)
{
	int			i;
	int			s;
	char		*cp;

	s = 1;
	while (s == 1)
	{
		s = 0;
		i = -1;
		while (tab[++i + 1])
			if (ft_strcmp((const char*)tab[i], (const char*)tab[i + 1]) > 0)
			{
				cp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = cp;
				s = 1;
			}
	}
}
