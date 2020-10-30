/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 22:18:19 by rakrouna          #+#    #+#             */
/*   Updated: 2020/04/14 21:49:06 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"

int		endpoints(t_room *room1)
{
	int	start;
	int	end;

	if (!room1)
		return (0);
	start = 0;
	end = 0;
	while (room1)
	{
		if (room1->start)
			start++;
		if (room1->end)
			end++;
		room1 = room1->next;
	}
	if (start == 1 && end == 1)
		return (1);
	return (ft_puterr("ERROR:Improper number of endpoints", 0));
}
