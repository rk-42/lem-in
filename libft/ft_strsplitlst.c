/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:36:03 by rakrouna          #+#    #+#             */
/*   Updated: 2019/04/18 20:00:50 by rakrouna         ###   ########.fr       */
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

static t_list		*ft_getlst(char const *str, char c, t_list *res,
		t_list *new)
{
	int				i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == c || i == 0) && ft_len(str, c, i) >= 1)
		{
			if (!res)
			{
				new = ft_lstnew((char *)ft_cpysplit(str, c, i),
						ft_strlen(ft_cpysplit(str, c, i)));
				res = new;
			}
			else
			{
				new->next = ft_lstnew((char *)ft_cpysplit(str, c, i),
						ft_strlen(ft_cpysplit(str, c, i)));
				new = new->next;
			}
		}
		i++;
	}
	new->next = NULL;
	return (res);
}

t_list				*ft_strsplitlst(char const *str, char c)
{
	t_list			*new;
	t_list			*res;
	int				i;

	i = 0;
	new = NULL;
	res = NULL;
	if (!str)
		return (NULL);
	while (str[i] == c && str[i + 1] == c)
		i++;
	res = ft_getlst(str, c, res, new);
	return (res);
}
