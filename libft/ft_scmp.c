/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 22:18:19 by rakrouna          #+#    #+#             */
/*   Updated: 2019/04/14 21:49:06 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_scmp(const char *s, const char *s1, const char *s2)
{
	return (ft_strcmp(s, s1) == 0 || ft_strcmp(s, s2) == 0);
}
