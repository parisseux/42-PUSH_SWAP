/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:02:13 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/07 17:43:42 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_order(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_size_stack(*stack_a) == 2)
	{
		ft_sa(stack_a);
		(void)stack_b;
	}
	else if (ft_size_stack(*stack_a) == 3)
	{
		ft_order_stack_size_3(stack_a);
		(void)stack_b;
	}
	else if (ft_size_stack(*stack_a) == 4)
		ft_order_stack_size_4(stack_a, stack_b);
	else if (ft_size_stack(*stack_a) >= 5)
		ft_order_big_stack(stack_a, stack_b);
	
}

void	ft_order_stack_size_3(t_stack **head)
{
	int	max_index;

	max_index = ft_find_index_of_max(*head);
	if (max_index == 0)
		ft_ra(head);
	else if (max_index == 1)
		ft_rra(head);
	if (ft_check_stack(head) == 0)
		ft_sa(head);
}

void	ft_order_stack_size_4(t_stack **stack_a, t_stack **stack_b)
{
	int	min_index;

	min_index = ft_find_index_of_min(*stack_a);
	if (min_index == 1)
		ft_sa(stack_a);
	else if (min_index == 2)
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	else if (min_index == 3)
		ft_rra(stack_a);
	if (ft_check_stack(stack_a))
		return ;
	ft_pb(stack_a, stack_b);
	ft_order_stack_size_3(stack_a);
	ft_pa(stack_b, stack_a);
}

void	ft_order_big_stack(t_stack **stack_a, t_stack **stack_b)
{
	ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
	while (ft_size_stack(*stack_a) > 3 && ft_check_stack(stack_a) == 0)
	{
		init_nodes_a(stack_a, stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	ft_order_stack_size_3(stack_a);
	while (*stack_b)
	{
		init_nodes_b(stack_a, stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	ft_index(stack_a);
	ft_min_on_top(stack_a);
}
