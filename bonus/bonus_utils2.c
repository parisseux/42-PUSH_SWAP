/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:11:18 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/09 14:10:25 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_create_or_add_back_bonus(t_stack **head, int value)
{
	t_stack	*last;
	t_stack	*new;

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

t_stack	*ft_new_node_bonus(int value)
{
	t_stack	*head;

	head = (t_stack *)malloc(1 * sizeof(t_stack));
	if (!head)
		return (NULL);
	head->data = value;
	head->next = NULL;
	head->prev = NULL;
	return (head);
}

void	ft_print_stack_bonus(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	while (temp)
	{
		printf("%ld ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int ft_is_stack_order_bonus(t_stack *a, t_stack *b)
{
	t_stack *temp;
 
	if (b || !a || !a->next )
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

int	ft_size_stack_bonus(t_stack *stack)
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
