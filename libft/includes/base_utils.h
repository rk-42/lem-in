/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 23:36:22 by rakrouna          #+#    #+#             */
/*   Updated: 2020/04/30 23:36:24 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_UTILS_H
# define BASE_UTILS_H

void			set_spaces_base(t_data *data);
void			set_zeros_base(t_data *data, unsigned long nb, int base_len);
unsigned long	cast_base(t_data *data);

#endif
