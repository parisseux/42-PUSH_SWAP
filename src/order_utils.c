/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:45:56 by pchatagn          #+#    #+#             */
/*   Updated: 2024/11/30 18:00:15 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_nodes_a(t_stack **stack_a, t_stack **stack_b)
{
	ft_index(stack_a);
	ft_index(stack_b);
	ft_target_b(stack_a, stack_b);
	ft_cost_analysis_a(stack_a, stack_b);
	ft_find_cheapest(stack_a);
}

void	ft_index(t_stack **stack)
{
	int		i;
	int		median;
	t_stack	*temp;

	if (!(*stack) || !stack)
		return ;
	i = 0;
	median = ft_size_stack(*stack) / 2;
	temp = *stack;
	while (temp)
	{
		temp->index = i;
		if (i < median)
			temp->above_median = 1;
		else
			temp->above_median = 0;
		i++;
		temp = temp->next;
	}
}

void	ft_target_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*t_b;
	t_stack	*t_a;
	t_stack	*target_node;
	long	diff;

	t_a = *stack_a;
	while (t_a)
	{
		t_b = *stack_b;
		target_node = NULL;
		diff = __LONG_MAX__;
		while (t_b)
		{
			if (t_b->data < t_a->data && diff > (t_a->data - t_b->data))
			{
				target_node = t_b;
				diff = t_a->data - target_node->data;
			}
			t_b = t_b->next;
		}
		if (!target_node)
			target_node = ft_find_max(*stack_b);
		t_a->target_node = target_node;
		t_a = t_a->next;
	}
}

void	ft_cost_analysis_a(t_stack **stack_a, t_stack **stack_b)
{
	int		cost;
	t_stack	*ta;

	ta = *stack_a;
	while (ta != NULL)
	{
		cost = 0;
		if (ta->above_median == 1 && ta->target_node->above_median == 1)
		{
			if (ta->target_node->index < ta->index)
				cost = ta->index;
			else
				cost = ta->target_node->index;
		}
		else if (ta->above_median == 0 && ta->target_node->above_median == 0)
		{
			if (ta->target_node->index < ta->index)
				cost = ft_size_stack(*stack_a) - ta->index;
			else
				cost = ft_size_stack(*stack_b) - ta->target_node->index;
		}
		else if (ta->above_median == 1 && ta->target_node->above_median == 0)
			cost = ta->index + ft_size_stack(*stack_b) - ta->target_node->index;
		else if (ta->above_median == 0 && ta->target_node->above_median == 1)
			cost = ta->target_node->index + ft_size_stack(*stack_a) - ta->index;
		ta->push_cost = cost;
		ta = ta->next;
	}
}

void	ft_find_cheapest(t_stack **stack)
{
	int		temp_cheapest_value;
	t_stack	*temp_cheapest_node;
	t_stack	*temp;

	if (!(*stack))
		return ;
	temp = *stack;
	while (temp)
	{
		temp->cheapest = 0;
		temp = temp->next;
	}
	temp = *stack;
	temp_cheapest_value = temp->push_cost;
	temp_cheapest_node = temp;
	while (temp)
	{
		if (temp->push_cost < temp_cheapest_value)
		{
			temp_cheapest_node = temp;
			temp_cheapest_value = temp->push_cost;
		}
		temp = temp->next;
	}
	temp_cheapest_node->cheapest = 1;
}
