/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 05:40:01 by rakrouna          #+#    #+#             */
/*   Updated: 2019/04/22 16:18:39 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	s;

	if (s1 && s2)
		s = (size_t)(ft_strlen((char*)s1) + ft_strlen((char*)s2));
	else if (s1)
		s = (size_t)(ft_strlen((char*)s1));
	else if (s2)
		s = (size_t)(ft_strlen((char*)s2));
	else
		return (NULL);
	if (!(res = ft_memalloc(s)))
		return (NULL);
	if (s1)
		res = ft_strcpy(res, (char*)s1);
	else
		res = ft_strcpy(res, (char*)s2);
	if (s1 && s2)
		res = ft_strcat(res, (char*)s2);
	return (res);
}
