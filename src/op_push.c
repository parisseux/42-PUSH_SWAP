/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:23:07 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/09 14:58:48 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack **src, t_stack **dst, t_inst **inst)
{
	if (!src || !(*src))
		return ;
	ft_create_or_add_front(dst, (*src)->data);
	ft_delete_first_node(src);
	ft_add_instruction(inst, "pa");
}

void	ft_pb(t_stack **src, t_stack **dst, t_inst **inst)
{
	if (!src || !(*src))
		return ;
	ft_create_or_add_front(dst, (*src)->data);
	ft_delete_first_node(src);
	ft_add_instruction(inst, "pb");
}
