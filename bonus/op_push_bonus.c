/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:23:07 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/09 13:58:34 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_pa_bonus(t_stack **src, t_stack **dst)
{
	if (!src || !(*src))
		return ;
	ft_create_or_add_front_bonus(dst, (*src)->data);
	ft_delete_first_node_bonus(src);
}

void	ft_pb_bonus(t_stack **src, t_stack **dst)
{
	if (!src || !(*src))
		return ;
	ft_create_or_add_front_bonus(dst, (*src)->data);
	ft_delete_first_node_bonus(src);
}
