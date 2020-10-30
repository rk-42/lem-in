/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceeds_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 22:18:19 by rakrouna          #+#    #+#             */
/*   Updated: 2019/04/14 21:49:06 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		exceeds_int(char *nb)
{
	int i;
	int pos;

	if (ft_strcmp(nb, "-") == 0)
		return (0);
	pos = (nb[0] != '-');
	if ((int)ft_strlen(nb) < 11 - pos)
		return (0);
	if ((int)ft_strlen(nb) > 11 - pos)
		return (1);
	if (nb[1 - pos] < 50)
		return (0);
	if (nb[1 - pos] > 50)
		return (1);
	if (nb[2 - pos])
	{
		i = ft_atoi(&nb[2 - pos]);
		if (i > 147483648 - pos)
			return (1);
	}
	return (0);
}
