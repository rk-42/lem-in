/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 22:18:19 by rakrouna          #+#    #+#             */
/*   Updated: 2020/04/14 21:49:06 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

int		is_name(t_room *room1, char *name)
{
	while (room1)
	{
		if (room1 && room1->name && ft_strcmp(room1->name, name) == 0)
			return (1);
		room1 = room1->next;
	}
	return (0);
}

int		is_coords(t_room *room1, char *x, char *y)
{
	while (room1)
	{
		if (room1 && (room1->c.x == ft_atoi(x) && room1->c.y == ft_atoi(y)))
			return (1);
		room1 = room1->next;
	}
	return (0);
}

t_room	**find_name(t_room **room1, char *name)
{
	t_room **room;

	room = room1;
	while (*room)
	{
		if (*room && (*room)->name && ft_strcmp((*room)->name, name) == 0)
			return (room);
		room = &(*room)->next;
	}
	return (NULL);
}

t_room	**find_start(t_room **room1)
{
	t_room **room;

	room = room1;
	while (*room)
	{
		if (*room && (*room)->start == 1)
			return (room);
		room = &(*room)->next;
	}
	return (NULL);
}

t_room	**find_end(t_room **room1)
{
	t_room **room;

	room = room1;
	while (*room)
	{
		if (*room && (*room)->end == 1)
			return (room);
		room = &(*room)->next;
	}
	return (NULL);
}
