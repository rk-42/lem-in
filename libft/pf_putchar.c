/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 23:33:53 by rakrouna          #+#    #+#             */
/*   Updated: 2020/04/30 23:33:55 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "includes/put_padding.h"

static void	set_padding(t_data *data, char c)
{
	data->padding.size = 1;
	data->padding.zeros = 0;
	if (!data->left && data->zero)
		data->padding.zeros = data->l_min - data->padding.size;
	data->padding.right_spaces = 0;
	data->padding.left_spaces = 0;
	if (data->left)
		data->padding.right_spaces = data->l_min - data->padding.zeros
			- data->padding.size;
	else
		data->padding.left_spaces = data->l_min - data->padding.zeros
			- data->padding.size;
	if (!c)
		return ;
}

void		pf_putchar(t_data *data)
{
	char	c;

	c = va_arg(data->ap, int);
	set_padding(data, c);
	put_left_spaces(data);
	put_zeros(data);
	fill_buffer(data, &c, 1);
	put_right_spaces(data);
}
