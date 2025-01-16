/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:11:18 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/10 14:01:34 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_create_or_add_back_bonus(t_stack_b **head, int value)
{
	t_stack_b	*last;
	t_stack_b	*new;

	if (*head == NULL)
	{
		*head = ft_new_node_bonus(value);
		return ;
	}
	last = *head;
	while (last->next != NULL)
		last = last->next;
	new = ft_new_node_bonus(value);
	if (!new)
		return ;
	last->next = new;
	new->prev = last;
}

t_stack_b	*ft_new_node_bonus(int value)
{
	t_stack_b	*head;

	head = (t_stack_b *)malloc(1 * sizeof(t_stack_b));
	if (!head)
		return (NULL);
	head->data = value;
	head->next = NULL;
	head->prev = NULL;
	return (head);
}

int	ft_is_stack_order_bonus(t_stack_b *a, t_stack_b *b)
{
	t_stack_b	*temp;

	if (b || !a || !a->next)
		return (0);
	temp = a;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ft_size_stack_bonus(t_stack_b *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	ft_delete_first_node_bonus(t_stack_b **head)
{
	t_stack_b	*temp;

	if (!(*head) || !head)
		return ;
	temp = *head;
	*head = (*head)->next;
	if (*head)
		(*head)->prev = NULL;
	free(temp);
}
