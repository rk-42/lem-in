/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 22:18:19 by rakrouna          #+#    #+#             */
/*   Updated: 2020/04/14 21:49:06 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"

int		room_in(t_bfs **p, t_room **room)
{
	t_bfs **aux;

	aux = p;
	while (*aux)
	{
		if ((*aux)->room == room)
			return (1);
		aux = &(*aux)->next;
	}
	return (0);
}

void	print_bfs(t_bfs *p)
{
	while (p && (*(p->room))->end != 1)
		p = p->next;
	if (p)
	{
		ft_putstr("BFS: ");
		while (p)
		{
			ft_putstr((*(p->room))->name);
			if (p->prev)
				ft_putstr(", ");
			p = p->prev;
		}
		ft_putendl("");
	}
}

int		flow_to(t_room **from, t_room **to)
{
	if ((*from)->start == 1)
		return ((*to)->f_fm == *from);
	return ((*from)->f_to == *to);
}

int		bfs(t_bfs **p, t_bfs **current)
{
	t_list	*link;
	t_room	**room;
	int		undo;

	if ((!*current || !*(*current)->room) || !(*(*current)->room)->lnks)
		return (0);
	undo = 0;
	if ((*current)->prev && (*(*current)->room)->f_to &&
		*(*current)->prev->room != (*(*current)->room)->f_to)
		undo = 1;
	link = (*(*current)->room)->lnks;
	while (link)
	{
		room = ((t_room**)(link->obj));
		if (!room_in(p, room) && !flow_to((*current)->room, room) &&
			(!undo || (undo && *room == (*(*current)->room)->f_fm)))
			insert_bfs(p, room, *current);
		if (!flow_to((*current)->room, room) && (*room)->end == 1)
			return (1);
		link = link->next;
	}
	return (bfs(p, &(*current)->next));
}
