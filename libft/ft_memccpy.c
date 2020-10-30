/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:22:36 by rakrouna          #+#    #+#             */
/*   Updated: 2019/04/22 15:36:24 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *restrict dst, const void *restrict src,
									int c, size_t size)
{
	unsigned char	*ptr_d;
	unsigned char	*ptr_s;
	size_t			i;

	i = 0;
	ptr_d = (unsigned char *)dst;
	ptr_s = (unsigned char *)src;
	while (i < size)
	{
		ptr_d[i] = ptr_s[i];
		if (ptr_d[i] == (unsigned char)c)
			return ((void*)(dst + i + 1));
		i++;
	}
	return (NULL);
}
