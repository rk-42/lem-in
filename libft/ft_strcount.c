/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcountchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 21:36:03 by rakrouna          #+#    #+#             */
/*   Updated: 2019/11/15 21:48:32 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcount(char *str, char c)
{
	int		i;
	int		r;

	if (!str)
		return (0);
	i = -1;
	r = 0;
	if (!str)
		return (0);
	if (str[0] != c)
		r = 1;
	while (str[i + 1] && str[++i] == c)
		i++;
	while (str[i])
	{
		if (str[i - 1] && str[i - 1] == c && str[i] != c)
			r++;
		i++;
	}
	return (r);
}
