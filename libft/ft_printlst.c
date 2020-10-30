/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:39:44 by rakrouna          #+#    #+#             */
/*   Updated: 2019/04/18 19:20:05 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printlst(t_list *begin)
{
	t_list	*tmp;

	if (!begin)
		return ;
	tmp = begin;
	while (tmp)
	{
		ft_putendl((const char *)tmp->obj);
		tmp = tmp->next;
	}
}
