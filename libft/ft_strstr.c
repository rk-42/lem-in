/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 23:52:29 by rakrouna          #+#    #+#             */
/*   Updated: 2019/04/18 15:24:26 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	k;
	int		last;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	last = 0;
	while (last == 0 && haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			k = i;
			j = 0;
			last = 1;
			while (needle[j])
				if (haystack[k++] != needle[j++])
					last = 0;
			if (last)
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
