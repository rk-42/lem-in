/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:04:10 by rakrouna          #+#    #+#             */
/*   Updated: 2019/04/18 14:05:56 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew2(void *content, size_t content_size)
{
	t_list *new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	else
	{
		if (content)
		{
			new->obj = content;
			new->dim = content_size;
		}
		else
		{
			new->obj = NULL;
			new->dim = 0;
		}
		new->next = NULL;
	}
	return (new);
}
