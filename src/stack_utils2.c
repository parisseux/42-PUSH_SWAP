/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:25:36 by parissachat       #+#    #+#             */
/*   Updated: 2024/11/27 16:15:46 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_create_or_add_front(t_stack **head, int value)
{
    t_stack *new;
    
    new = ft_new_node(value);
    if (!new)
        return ;
	if (*head == NULL)
    {
		*head = new;
		return ;
	}
    new->next = *head;
    (*head)->prev = new;
    *head = new;

}
void   ft_delete_first_node(t_stack **head)
{
    t_stack *temp;
    
    if (!(*head) || !head)
        return ;
    temp = *head;
    *head = (*head)->next;
    if (*head)
        (*head)->prev = NULL;
    free(temp);
}

int ft_find_index_of_max(t_stack *head)
{
    int index;
    long max;
    int count;

    if (!head)
        return (-1);
    max = head->data;
    index = 1;
    count =  0;
    while (head)
    {
        count = count + 1;
        if (head->data > max)
        {
            max = head->data;
            index = count;
        }
        head = head ->next;
    }
    return (index);
}

int ft_check_stack(t_stack **head)
{
    t_stack *temp;

    if (!(*head) || !head || !(*head)->next)
        return (1);
    temp = *head;
    while (temp->next)
    {
        if (temp->data >= temp->next->data)
            return (0);
        temp = temp->next;
    }
    return (1);
}

t_stack *ft_find_max(t_stack *stack)
{
    t_stack *max;

    if (!stack)
        return (NULL);
    max = stack;    
    while (stack)
    {
        if (max->data < stack->data)
            max = stack;
        stack = stack->next;
    }
    return (max);
}
