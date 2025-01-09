/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:17:26 by pchatagn          #+#    #+#             */
/*   Updated: 2025/01/09 14:41:27 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	rotate_node_and_t_node(t_stack **s_a, t_stack **s_b, t_stack *node, t_inst **inst)
{
	while (*s_a != node && *s_b != node->target_node)
		ft_rr(s_a, s_b, inst);
	ft_index(s_a);
	ft_index(s_b);
}

void	rev_rotate_node_and_t_node(t_stack **s_a, t_stack **s_b, t_stack *node,  t_inst **inst)
{
	while (*s_a != node && *s_b != node->target_node)
		ft_rrr(s_a, s_b, inst);
	ft_index(s_a);
	ft_index(s_b);
}

void	move_a_to_b(t_stack **stack_a, t_stack **stack_b, t_inst **inst)
{
	t_stack	*cheapest_node;
	t_stack	*temp;

	if (!stack_a || !(*stack_a))
		return ;
	temp = *stack_a;
	cheapest_node = NULL;
	while (temp->cheapest == 0)
		temp = temp->next;
	cheapest_node = temp;
	if (cheapest_node->above_median == 1
		&& cheapest_node->target_node->above_median == 1)
		rotate_node_and_t_node(stack_a, stack_b, cheapest_node, inst);
	if (cheapest_node->above_median == 0
		&& cheapest_node->target_node->above_median == 0)
		rev_rotate_node_and_t_node(stack_a, stack_b, cheapest_node, inst);
	ft_node_at_the_top_stack_a(stack_a, cheapest_node, inst);
	ft_node_at_the_top_stack_b(stack_b, cheapest_node->target_node, inst);
	ft_pb(stack_a, stack_b, inst);
}

void	ft_node_at_the_top_stack_a(t_stack **stack, t_stack *node,  t_inst **inst)
{
	int	nbr_of_operation;

	if (node == *stack)
		return ;
	if (node->above_median == 1)
	{
		nbr_of_operation = node->index;
		while (nbr_of_operation > 0)
		{
			ft_ra(stack, inst);
			nbr_of_operation--;
		}
	}
	else if (node->above_median == 0)
	{
		nbr_of_operation = ft_size_stack(*stack) - node->index;
		while (nbr_of_operation > 0)
		{
			ft_rra(stack, inst);
			nbr_of_operation--;
		}
	}
}

void	ft_node_at_the_top_stack_b(t_stack **stack, t_stack *node,  t_inst **inst)
{
	int	nbr_of_operation;

	if (node == *stack)
		return ;
	if (node->above_median == 1)
	{
		nbr_of_operation = node->index;
		while (nbr_of_operation > 0)
		{
			ft_rb(stack, inst);
			nbr_of_operation--;
		}
	}
	else if (node->above_median == 0)
	{
		nbr_of_operation = ft_size_stack(*stack) - node->index;
		while (nbr_of_operation > 0)
		{
			ft_rrb(stack, inst);
			nbr_of_operation--;
		}
	}
}
