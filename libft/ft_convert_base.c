/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:31:19 by rakrouna          #+#    #+#             */
/*   Updated: 2019/04/14 21:40:09 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_pos(char c, char *base)
{
	int				i;
	int				j;

	i = 0;
	while (base[i])
	{
		j = i;
		while (base[j])
		{
			if ((base[i] == base[j] && i != j) ||
					base[i] == '-' || base[i] == '+')
				return (-1);
			j++;
		}
		i++;
	}
	i = 0;
	while (base[i] != c && base[i])
		i++;
	if (base[i] == c && base[i])
		return (i);
	return (-1);
}

static char			*ft_putnbr_base(int nbr, int len, char *base_to, int lenb)
{
	int				i;
	char			*r;

	i = 0;
	len = (nbr < 0) ? len + 1 : len;
	if (!(r = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	r[0] = (nbr < 0) ? '-' : r[0];
	nbr = (nbr < 0) ? nbr * -1 : nbr;
	if (nbr == 0)
	{
		r[1] = '\0';
		r[0] = base_to[0];
	}
	else
	{
		i = len - 1;
		while (nbr >= 1)
		{
			r[len] = '\0';
			r[i--] = base_to[nbr % lenb];
			nbr /= lenb;
		}
	}
	return (r);
}

static int			ft_calcule_nbr(char *str, int j, char *base, int lenb)
{
	int				i;
	int				p;
	int				c;
	int				r;
	int				pos;

	r = 0;
	i = 0;
	pos = j;
	while (ft_pos(str[j++], base) != -1)
		i++;
	j = 0;
	while (i >= 0)
	{
		p = j;
		c = 1;
		while (p-- >= 1)
			c *= lenb;
		if (ft_pos(str[pos + i - 1], base) == -1)
			return (r);
		r += ft_pos(str[pos + i - 1], base) * c;
		j++;
		i--;
	}
	return (r);
}

static int			ft_atoi_base(char *str, char *base)
{
	int				i;
	int				s;
	int				lenb;

	i = 0;
	s = 1;
	while (base[i] != '\0')
		i++;
	lenb = i;
	i = 0;
	while (str[i] <= 32 && str[i])
		i++;
	if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	return (ft_calcule_nbr(str, i, base, lenb) * s);
}

char				*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int				nb;
	int				i;
	int				len;
	int				l;

	len = 0;
	i = 0;
	if (ft_pos(base_to[0], base_to) == -1 ||
			ft_pos(base_from[0], base_from) == -1)
		return ("\0");
	nb = ft_atoi_base(nbr, base_from);
	l = (nb < 0) ? (nb * -1) : nb;
	while (base_to[i])
		i++;
	while (l >= 1)
	{
		l /= i;
		len++;
	}
	i = 0;
	while (base_to[i])
		i++;
	return (ft_putnbr_base(nb, len, base_to, i));
}
