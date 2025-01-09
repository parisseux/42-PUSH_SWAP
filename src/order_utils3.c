/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:51:15 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/09 14:41:30 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	init_nodes_b(t_stack **stack_a, t_stack **stack_b)
{
	ft_index(stack_a);
	ft_index(stack_b);
	ft_target_a(stack_a, stack_b);
	ft_cost_analysis_b(stack_a, stack_b);
	ft_find_cheapest(stack_b);
}

void	move_b_to_a(t_stack **stack_a, t_stack **stack_b,  t_inst **inst)
{
	t_stack	*cheapest_node;
	t_stack	*temp;

	if (!stack_b || !(*stack_b))
		return ;
	temp = *stack_b;
	cheapest_node = NULL;
	while (temp->cheapest == 0)
		temp = temp ->next;
	cheapest_node = temp;
	if (cheapest_node->above_median == 1
		&& cheapest_node->target_node->above_median == 1)
		rotate_node_and_t_node(stack_b, stack_a, cheapest_node, inst);
	if (cheapest_node->above_median == 0
		&& cheapest_node->target_node->above_median == 0)
		rev_rotate_node_and_t_node(stack_b, stack_a, cheapest_node, inst);
	ft_node_at_the_top_stack_a(stack_a, cheapest_node->target_node, inst);
	ft_node_at_the_top_stack_b(stack_b, cheapest_node, inst);
	ft_pa(stack_b, stack_a, inst);
}

void	ft_target_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*t_b;
	t_stack	*t_a;
	t_stack	*target_node;
	long	diff;

	t_b = *stack_b;
	while (t_b)
	{
		t_a = *stack_a;
		target_node = NULL;
		diff = __LONG_MAX__;
		while (t_a)
		{
			if (t_a->data > t_b->data && diff > (t_a->data - t_b->data))
			{
				target_node = t_a;
				diff = t_a->data - t_b->data;
			}
			t_a = t_a->next;
		}
		if (!target_node)
			target_node = ft_find_min(*stack_a);
		t_b->target_node = target_node;
		t_b = t_b->next;
	}
}

void	ft_cost_analysis_b(t_stack **stack_a, t_stack **stack_b)
{
	int		cost;
	t_stack	*tb;

	tb = *stack_b;
	while (tb != NULL)
	{
		cost = 0;
		if (tb->above_median == 1 && tb->target_node->above_median == 1)
		{
			if (tb->target_node->index < tb->index)
				cost = tb->index;
			else
				cost = tb->target_node->index;
		}
		else if (tb->above_median == 0 && tb->target_node->above_median == 0)
		{
			if (tb->target_node->index < tb->index)
				cost = ft_size_stack(*stack_b) - tb->index;
			else
				cost = ft_size_stack(*stack_a) - tb->target_node->index;
		}
		else if (tb->above_median == 1 && tb->target_node->above_median == 0)
			cost = tb->index + ft_size_stack(*stack_a) - tb->target_node->index;
		else if (tb->above_median == 0 && tb->target_node->above_median == 1)
			cost = tb->target_node->index + ft_size_stack(*stack_b) - tb->index;
		tb->push_cost = cost;
		tb = tb->next;
	}
}

void	ft_min_on_top(t_stack **stack_a,  t_inst **inst)
{
    t_stack	*min;
    int		i;

    min = ft_find_min(*stack_a);
    i = min->index;

    // If the minimum element is above the median, rotate up (ra)
    if (min->above_median == 1)
    {
        while (i > 0)
        {
            ft_ra(stack_a, inst);
            i--;
        }
    }
    // If the minimum element is below the median, rotate down (rra)
    else
    {
        i = ft_size_stack(*stack_a) - i;
        while (i > 0)
        {
            ft_rra(stack_a, inst);
            i--;
        }
    }
}
