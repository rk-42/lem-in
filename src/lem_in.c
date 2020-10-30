/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <rakrouna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 22:18:19 by rakrouna          #+#    #+#             */
/*   Updated: 2020/10/09 13:25:36 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_cmd(char *cmd, int section, t_farm **farm, int *io)
{
	char	**rooms;
	int		aux;

	if (cmd[0] && cmd[0] == '#' && !ft_scmp(cmd, "##end", "##start"))
		return (section);
	if ((*io < 0 && section == 0) && is_num(cmd))
		return (add_ants(farm, ft_atoi(cmd)));
	else if (section == 0)
		section = 1;
	if (section == 1)
	{
		if (!(rooms = ft_strsplit(cmd, ' ')))
			section = 2;
		if (!(aux = is_room(&(*farm)->rms, rooms, io)))
			section = 2;
		section = (aux < 0) ? -1 : section;
		free_split(rooms);
	}
	if (section == 2)
	{
		if (!is_link(farm, cmd, *io))
			section = -1;
	}
	*io = -1;
	return (section);
}

int		fill_farm(t_farm **farm, int section, int io)
{
	char		*line;
	static char	*pitcher;
	int			start;
	int			end;

	pitcher = NULL;
	start = 0;
	end = 0;
	while (section >= 0 && get_next_line2(0, &line, &pitcher) == 1)
	{
		if (io < 0 && ft_strcmp(line, "##start") == 0)
			io = 0;
		else if (io < 0 && ft_strcmp(line, "##end") == 0)
			io = 1;
		else
			section = is_cmd(line, section, farm, &io);
		if (ft_scmp(line, "##end", "##start"))
			section = repeated_endpoints(&start, &end, io, section);
		(section >= 0) ? ft_putendl(line) : 0;
		ft_memdel((void**)&line);
	}
	(section < 0) ? free(pitcher) : 0;
	(line) ? free(line) : 0;
	return (1);
}

void	ft_usage(void)
{
	ft_printf("USAGE: ./lem-in [--d] [--dp] < map\n\n");
	ft_printf("--d:\t\tNumber of lines\n\n");
	ft_printf("--dp:\t\tNodes information and flow\n");
	exit(0);
}

int		main(int ac, char **av)
{
	t_farm	*farm;
	int		debug;
	int		ants;

	if (ac == 1 || (ac == 2 && ft_scmp(av[1], "--d", "--dp")))
	{
		debug = (ac == 2) ? 1 : 0;
		debug = (ac == 2 && !ft_strcmp(av[1], "--dp")) ? 2 : debug;
		init_farm(&farm);
		fill_farm(&farm, 0, -1);
		if (!farm->rms)
		{
			free(farm);
			return (ft_puterr("ERROR:There are no rooms", 1));
		}
		ants = farm->ants;
		ft_putendl("");
		solve(&farm, debug);
		farm->ants = ants;
		(debug == 2) ? print_farm(farm) : 0;
		destruct_farm(&farm);
	}
	else
		ft_usage();
	return (0);
}
