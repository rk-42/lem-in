/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   facteursp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 11:14:01 by rakrouna          #+#    #+#             */
/*   Updated: 2019/04/14 21:40:22 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_facteursp(int nb)
{
	int		i;

	i = 2;
	ft_putnbr(nb);
	ft_putchar('=');
	while (ft_is_prime(nb) == 0)
	{
		while (nb % i == 0 && ft_is_prime(i))
		{
			ft_putnbr(i);
			ft_putchar('x');
			nb /= i;
		}
		i++;
	}
	ft_putnbr(nb);
}
