/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:23:07 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/10 14:02:55 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_pa_bonus(t_stack_b **src, t_stack_b **dst)
{
	if (!src || !(*src))
		return ;
	ft_create_or_add_front_bonus(dst, (*src)->data);
	ft_delete_first_node_bonus(src);
}

void	ft_pb_bonus(t_stack_b **src, t_stack_b **dst)
{
	if (!src || !(*src))
		return ;
	ft_create_or_add_front_bonus(dst, (*src)->data);
	ft_delete_first_node_bonus(src);
}
