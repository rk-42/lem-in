/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:36:03 by rakrouna          #+#    #+#             */
/*   Updated: 2019/04/22 16:26:45 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			ft_len(const char *str, char c, int pos)
{
	int				i;

	i = 0;
	if (str[pos] == c)
		pos++;
	while (str[pos] && str[pos] != c)
	{
		i++;
		pos++;
	}
	return (i);
}

static	char		*ft_cpysplit(const char *str, char c, int pos)
{
	char			*split;
	int				j;

	j = 0;
	if (str[pos] == c)
		pos++;
	if (!(split = malloc(sizeof(char) * (ft_len(str, c, pos) + 1))))
		return (NULL);
	while (str[pos] && str[pos] != c)
	{
		split[j] = str[pos];
		j++;
		pos++;
	}
	split[j] = '\0';
	return (split);
}

static	char		**ft_tab(char **tab, const char *str, char c)
{
	int				i;
	int				p;

	i = 0;
	p = 1;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c && ft_len(str, c, i) >= 1)
			p++;
		i++;
	}
	if (!(tab = malloc(sizeof(char*) * p + 1)))
		return (0);
	return (tab);
}

char				**ft_strsplit(char const *str, char c)
{
	char			**tab;
	int				i;
	int				p;

	i = 0;
	p = 0;
	tab = NULL;
	tab = ft_tab(tab, str, c);
	if (!str || !tab)
		return (NULL);
	while (str[i] == c && str[i + 1] == c)
		i++;
	while (str[i])
	{
		if ((str[i] == c || i == 0) &&
				ft_len(str, c, i) >= 1)
		{
			tab[p] = ft_cpysplit(str, c, i);
			p++;
		}
		i++;
	}
	tab[p] = 0;
	return (tab);
}
