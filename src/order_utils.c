/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:45:56 by pchatagn          #+#    #+#             */
/*   Updated: 2025/01/10 13:33:10 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_nodes(t_stack *a, t_stack *b)
{
	ft_index(a);
	ft_index(b);
	ft_find_target_node(a, b);
	ft_calculate_cost(a, b);
	ft_find_cheapest(b);
}

void	ft_index(t_stack *stack)
{
	int		i;
	int		median;
	t_stack	*temp;

	if (stack == NULL)
		return ;
	i = 0;
	median = ft_size_stack(stack) / 2;
	temp = stack;
	while (temp)
	{
		temp->index = i;
		if (i <= median)
			temp->above_median = 1;
		else
			temp->above_median = 0;
		i++;
		temp = temp->next;
	}
}

void	ft_find_target_node(t_stack *a, t_stack *b)
{
	t_stack	*temp;
	t_stack	*t_node;
	long	temp_best;

	while (b)
	{
		temp_best = LONG_MAX;
		temp = a;
		while (temp)
		{
			if (temp->data > b->data && temp->data < temp_best)
			{
				temp_best = temp->data;
				t_node = temp;
			}
			temp = temp->next;
		}
		if (temp_best == LONG_MAX)
			b->target_node = ft_find_smallest(a);
		else
			b->target_node = t_node;
		b = b->next;
	}
}

void	ft_calculate_cost(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;

	size_a = ft_size_stack(a);
	size_b = ft_size_stack(b);
	while (b)
	{
		b->push_cost = b->index;
		if (b->above_median == 0)
			b->push_cost = size_b - (b->index);
		if (b->target_node->above_median == 1)
			b->push_cost += b->target_node->index;
		else
			b->push_cost += size_a - (b->target_node->index);
		b = b->next;
	}
}

void	ft_find_cheapest(t_stack *b)
{
	int		best;
	t_stack	*cheap_node;

	if (b == NULL)
		return ;
	best = INT_MAX;
	while (b)
	{
		if (b->push_cost < best)
		{
			best = b->push_cost;
			cheap_node = b;
		}
		b = b->next;
	}
	cheap_node->cheapest = 1;
}
