/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 22:18:19 by rakrouna          #+#    #+#             */
/*   Updated: 2019/04/14 21:49:06 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_countchr(const char *s, int c)
{
	int i;
	int q;

	i = 0;
	q = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			q++;
		i++;
	}
	return (q);
}