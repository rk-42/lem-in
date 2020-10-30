/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 00:02:21 by rakrouna          #+#    #+#             */
/*   Updated: 2019/04/22 16:34:05 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void							*ft_memcpy(void *restrict dst,
		const void *restrict src, size_t n)
{
	unsigned char				*ptr1;
	const unsigned char			*ptr2;

	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	while (n-- > 0)
		*(ptr1++) = *(ptr2++);
	return (dst);
}
