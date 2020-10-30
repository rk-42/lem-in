/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:02:55 by rakrouna          #+#    #+#             */
/*   Updated: 2019/04/18 20:32:34 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_len(unsigned int nb)
{
	int				i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb >= 1)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static char			*ft_tab(unsigned int nb, int s)
{
	int				i;
	char			*tab;

	i = ft_len(nb);
	if (!(tab = (char*)malloc(sizeof(char) * (i + 1 + s))))
		return (NULL);
	if (nb == 0)
	{
		tab[0] = '0';
		tab[1] = '\0';
	}
	else if (s == 1)
		tab[0] = '-';
	return (tab);
}

char				*ft_itoa(int n)
{
	unsigned int	nb;
	int				s;
	int				i;
	char			*res;

	s = 0;
	nb = n;
	if (n < 0)
	{
		nb = -n;
		s = 1;
	}
	i = ft_len(nb) + s;
	res = ft_tab(nb, s);
	if (res == NULL)
		return (NULL);
	if (res[0] == '0')
		return (res);
	res[i--] = '\0';
	while (i >= 0 && res[i] != '-')
	{
		res[i--] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (res);
}
