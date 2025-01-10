/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:17:26 by pchatagn          #+#    #+#             */
/*   Updated: 2025/01/10 13:31:08 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_empty_b(t_stack **a, t_stack **b, t_inst **inst)
{
	t_stack	*node;

	node = ft_get_cheapest(*b);
	if (node->above_median == 1 && node->target_node->above_median == 1)
		ft_rotate_both(a, b, node, inst);
	else if (node->above_median == 0 && node->target_node->above_median == 0)
		ft_rev_rotate_both(a, b, node, inst);
	ft_node_to_the_top(a, node->target_node, 'a', inst);
	ft_node_to_the_top(b, node, 'b', inst);
	ft_pa(b, a, inst);
}

t_stack	*ft_get_cheapest(t_stack *b)
{
	if (b == NULL)
		return (NULL);
	while (b)
	{
		if (b->cheapest == 1)
			return (b);
		b = b->next;
	}
	return (NULL);
}

void	ft_node_to_the_top(t_stack **a, t_stack *node, char c, t_inst **inst)
{
	while (*a != node)
	{
		if (c == 'a')
		{
			if (node->above_median == 1)
				ft_ra(a, inst);
			else
				ft_rra(a, inst);
		}
		else if (c == 'b')
		{
			if (node->above_median == 1)
				ft_rb(a, inst);
			else
				ft_rrb(a, inst);
		}
	}	
}

t_stack	*ft_find_smallest(t_stack *a)
{
	long	min;
	t_stack	*smallest_node;

	if (a == NULL)
		return (NULL);
	min = LONG_MAX;
	while (a)
	{
		if (a->data < min)
		{
			min = a->data;
			smallest_node = a;
		}
		a = a->next;
	}
	return (smallest_node);
}
