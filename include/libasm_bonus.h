/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudouy <acoudouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:28:31 by acoudouy          #+#    #+#             */
/*   Updated: 2020/02/19 14:34:06 by acoudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_BONUS_H
# define LIBASM_BONUS_H

typedef struct			s_list
{
	void				*data;
	struct s_list		*next;
}						t_list;

int						ft_list_size(t_list *begin);
void					ft_list_push_front(t_list **begin_list, void *data);

#endif
