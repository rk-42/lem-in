/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupplus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 15:56:35 by rakrouna          #+#    #+#             */
/*   Updated: 2019/06/22 16:20:40 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdupplus(char *src, char c)
{
	int		i;
	char	*res;

	i = 0;
	if (src != NULL)
		while (src[i])
			i++;
	if (!(res = (char*)realloc(src, sizeof(char) * (i + 2))))
		return (NULL);
	res[i++] = c;
	res[i] = '\0';
	return (res);
}
