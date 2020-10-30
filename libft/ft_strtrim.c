/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 06:36:03 by rakrouna          #+#    #+#             */
/*   Updated: 2019/04/22 16:15:17 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_end(char const *s, int i)
{
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	int			i;
	int			l;
	char		*res;

	i = 0;
	l = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (ft_end(s, i) == 0 && s[i])
	{
		i++;
		l++;
	}
	if (!(res = malloc(sizeof(char) * l + 1)))
		return (NULL);
	i = 0;
	l = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (ft_end(s, i) == 0)
		res[l++] = s[i++];
	res[l] = '\0';
	return (res);
}
