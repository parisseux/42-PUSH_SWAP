/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:13:06 by pchatagn          #+#    #+#             */
/*   Updated: 2024/11/25 15:37:23 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_size_stack(t_stack *stack)
{
	int i;
	
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
t_stack	*ft_new_node(int value)
{
	t_stack *head;

	head = (t_stack *)malloc(1 * sizeof(t_stack));
	if (!head)
		return (NULL);
	head->data = value;
	head->next = NULL;
	head->prev = NULL;
	return (head);
}

void	ft_create_or_add_back(t_stack **head, int value)
{
	t_stack *last;
	t_stack *new;

	if (*head == NULL)
	{
		*head = ft_new_node(value);
		return ;
	}
	last = *head;
	while (last -> next != NULL)
		last = last->next;
	new = ft_new_node(value);
	if (!new)
		return ;
	last->next = new;
	new->prev = last;
}

void    ft_free_stack(t_stack **stack)
{
	t_stack *temp;
	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

void print_stack(t_stack *head)
{
    t_stack *temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
