/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 22:18:19 by rakrouna          #+#    #+#             */
/*   Updated: 2020/04/14 21:49:06 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	print_link(t_list *link)
{
	while (link)
	{
		ft_putstr((*((t_room**)(link->obj)))->name);
		if (link->next)
			ft_putstr(", ");
		link = link->next;
	}
	ft_putendl("");
}

void	print_room(t_room *room)
{
	while (room)
	{
		ft_putstr("Name: ");
		ft_putendl(room->name);
		ft_putstr("(start/end): (");
		ft_putnbr(room->start);
		ft_putstr("/");
		ft_putnbr(room->end);
		ft_putendl(")");
		ft_putstr("Coords: (");
		ft_putnbr(room->c.x);
		ft_putstr(", ");
		ft_putnbr(room->c.y);
		ft_putendl(")");
		ft_putstr("Links: ");
		print_link(room->lnks);
		ft_putstr("Flow to: ");
		ft_putstr((room->f_to) ? room->f_to->name : "*");
		ft_putstr("\nFlow from: ");
		ft_putstr((room->f_fm) ? room->f_fm->name : "*");
		ft_putendl("\n");
		room = room->next;
	}
}
