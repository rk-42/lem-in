/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 22:18:19 by rakrouna          #+#    #+#             */
/*   Updated: 2020/04/14 21:49:06 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FARM_H
# define FARM_H

# include "graph.h"

typedef struct		s_farm
{
	int				ants;
	t_room			*rms;
}					t_farm;

void				destruct_farm(t_farm **farm);
void				init_farm(t_farm **farm);
void				print_farm(t_farm *farm);
int					add_ants(t_farm **farm, int ants);
t_coord				coord(char *x, char *y);

/*
** valid_input
*/

int					is_num(char *str);
int					is_room(t_room **rms, char **rooms, int *io);
int					is_link(t_farm **farm, char *str, int io);
int					repeated_endpoints(int *start, int *end, int io,
										int section);

#endif
