/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 20:17:39 by rakrouna          #+#    #+#             */
/*   Updated: 2019/07/06 21:37:53 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdupstr(char *src, char *str, int m)
{
	int		i;
	int		j;
	char	*res;

	i = ft_strlen(src);
	j = -1;
	if (!(res = (char*)realloc(src, sizeof(char) * (ft_strlen(src)
						+ ft_strlen(str) + 1))))
		return (NULL);
	if (str != NULL)
		while (str[++j])
		{
			res[i] = str[j];
			i++;
		}
	res[i] = '\0';
	if (m == 2)
		free(str);
	return (res);
}
