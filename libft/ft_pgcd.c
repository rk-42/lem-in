/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pgcd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 18:15:51 by rakrouna          #+#    #+#             */
/*   Updated: 2019/04/14 21:46:35 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pgcd(int a, int b)
{
	int	r;

	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return (a);
}
