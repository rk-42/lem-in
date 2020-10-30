/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 23:31:49 by rakrouna          #+#    #+#             */
/*   Updated: 2020/04/30 23:31:54 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "includes/put_padding.h"

static void		set_padding(t_data *data)
{
	data->padding.zeros = 0;
	if (!data->left && data->zero)
		data->padding.zeros = data->l_min - 1;
	if (data->padding.zeros < 0)
		data->padding.zeros = 0;
	data->padding.right_spaces = 0;
	data->padding.left_spaces = 0;
	if (data->left)
		data->padding.right_spaces = data->l_min - data->padding.zeros - 1;
	else
		data->padding.left_spaces = data->l_min - data->padding.zeros - 1;
}

void			pf_putpercent(t_data *data)
{
	set_padding(data);
	put_left_spaces(data);
	put_zeros(data);
	fill_buffer(data, "%", 1);
	put_right_spaces(data);
}

int				pf_atoi(const char *str)
{
	int	res;
	int	i;
	int	neg;

	res = 0;
	i = 0;
	neg = 1;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		res = 10 * res + (str[i] - 48);
		i++;
	}
	return (neg * res);
}

void			fill_buffer(t_data *data, const char *s, unsigned int size)
{
	unsigned	int	i;
	ssize_t			r;

	i = 0;
	if (data->ret != -1)
		data->ret += size;
	if (data->i + size > 2147483647)
		data->ret = -1;
	if (data->i + size >= BUFF_SIZE)
	{
		r = write(data->fd, data->buffer, data->i);
		data->i = 0;
	}
	if (size < BUFF_SIZE)
	{
		while (i < size)
		{
			data->buffer[data->i] = s[i];
			i++;
			data->i++;
		}
	}
	else
		r = write(data->fd, s, size);
	(r == 0) ? r = 1 : r;
}

int				ft_dprintf(int fd, const char *restrict format, ...)
{
	t_data	data;
	ssize_t	r;

	if (!format)
		return (-1);
	init_data(&data, fd);
	va_start(data.ap, format);
	parse_format(format, &data);
	r = write(fd, data.buffer, data.i);
	va_end(data.ap);
	if (r || !r)
		return (data.ret);
	return (data.ret);
}
