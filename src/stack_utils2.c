/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:25:36 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/09 20:04:13 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_index_of_max(t_stack *head)
{
	int		index;
	long	max_value;
	int		count;

	if (!head)
		return (-1);
	index = 0;
	count = 0;
	max_value = head->data;
	while (head)
	{
		if (head->data > max_value)
		{
			max_value = head->data;
			index = count;
		}
		count++;
		head = head ->next;
	}
	return (index);
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
		head = head->next;
	}
	return (index);
}

int	ft_check_stack(t_stack *head)
{
	t_stack	*temp;

	if (!head || !head->next)
		return (1);
	temp = head;
	while (temp->next)
	{
		if (temp->data >= temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

