/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 23:52:29 by rakrouna          #+#    #+#             */
/*   Updated: 2019/04/18 15:20:01 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	int		last;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	last = 1;
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		if (haystack[i] == needle[0])
		{
			k = i;
			last = 1;
			while (haystack[k] && needle[j] && j < len && k < len)
				if (haystack[k++] != needle[j++])
					last = 0;
			if (last && !needle[j])
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
