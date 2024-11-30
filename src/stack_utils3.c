/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:39:35 by pchatagn          #+#    #+#             */
/*   Updated: 2024/11/30 19:16:26 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_min(t_stack *stack)
{
	t_stack	*min;

	if (!stack)
		return (NULL);
	min = stack;
	while (stack)
	{
		if (min->data > stack->data)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

int	ft_find_index_of_min(t_stack *head)
{
	int	index;
	int	min;
	int	count;

	if (!head)
		return (-1);
	index = 0;
	min = head->data;
	count = 0;
	while (head)
	{
		if (head->data < min)
		{
			min = head->data;
			index = count;
		}
		count++;
		head = head ->next;
	}
	return (index);
}
