/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 22:32:23 by rakrouna          #+#    #+#             */
/*   Updated: 2019/04/21 23:15:02 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s, size_t n)
{
	char	*blank;

	if (!(blank = ft_strnew(n)))
		return (NULL);
	ft_strncpy(blank, s, n);
	return (blank);
}
