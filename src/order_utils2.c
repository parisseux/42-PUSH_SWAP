/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:17:26 by pchatagn          #+#    #+#             */
/*   Updated: 2024/11/30 18:09:59 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_node_and_t_node(t_stack **s_a, t_stack **s_b, t_stack *node)
{
	while (*s_a != node && *s_b != node->target_node)
		ft_rr(s_a, s_b);
	ft_index(s_a);
	ft_index(s_b);
}

void	rev_rotate_node_and_t_node(t_stack **s_a, t_stack **s_b, t_stack *node)
{
	while (*s_a != node && *s_b != node->target_node)
		ft_rrr(s_a, s_b);
	ft_index(s_a);
	ft_index(s_b);
}

void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;
	t_stack	*temp;

	if (!stack_a || !(*stack_a))
		return ;
	temp = *stack_a;
	cheapest_node = NULL;
	while (temp->cheapest == 0)
		temp = temp ->next;
	cheapest_node = temp;
	if (cheapest_node->above_median == 1
		&& cheapest_node->target_node->above_median == 1)
		rotate_node_and_t_node(stack_a, stack_b, cheapest_node);
	if (cheapest_node->above_median == 0
		&& cheapest_node->target_node->above_median == 0)
		rev_rotate_node_and_t_node(stack_a, stack_b, cheapest_node);
	ft_node_at_the_top_stack_a(stack_a, cheapest_node);
	ft_node_at_the_top_stack_b(stack_b, cheapest_node->target_node);
	ft_pb(stack_a, stack_b);
}

void	ft_node_at_the_top_stack_a(t_stack **stack, t_stack *node)
{
	int	nbr_of_operation;

	if (node == *stack)
		return ;
	if (node->above_median == 1)
	{
		nbr_of_operation = node->index;
		while (nbr_of_operation > 0)
		{
			ft_ra(stack);
			nbr_of_operation--;
		}
	}
	else if (node->above_median == 0)
	{
		nbr_of_operation = ft_size_stack(*stack) - node->index;
		while (nbr_of_operation > 0)
		{
			ft_rra(stack);
			nbr_of_operation--;
		}
	}
}

void	ft_node_at_the_top_stack_b(t_stack **stack, t_stack *node)
{
	int	nbr_of_operation;

	if (node == *stack)
		return ;
	if (node->above_median == 1)
	{
		nbr_of_operation = node->index;
		while (nbr_of_operation > 0)
		{
			ft_rb(stack);
			nbr_of_operation--;
		}
	}
	else if (node->above_median == 0)
	{
		nbr_of_operation = ft_size_stack(*stack) - node->index;
		while (nbr_of_operation > 0)
		{
			ft_rrb(stack);
			nbr_of_operation--;
		}
	}
}
