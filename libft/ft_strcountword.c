/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcountchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 21:36:03 by rakrouna          #+#    #+#             */
/*   Updated: 2019/11/10 20:13:59 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcountword(char *str, char c)
{
	int		i;
	int		r;

	if (!str)
		return (0);
	i = -1;
	r = 0;
	while (str[++i])
		if (i > 0 && str[i - 1] == c && str[i] != c)
			r++;
	return (r);
}
