/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:24:16 by parissachat       #+#    #+#             */
/*   Updated: 2024/11/25 14:36:13 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//rotate A B C D --> B C D A 
void    ft_rotate(t_stack **head)
{
    t_stack *last;
    t_stack *second;
    t_stack *first;
    
    if (!head || !(*head) || !(*head)->next)
        return ;
    first = *head;
    last = *head;
	while (last -> next != NULL)
		last = last->next;
    second = first->next;
    second -> prev = NULL;
    last -> next = first;
    first -> prev = last; 
    first -> next = NULL;
    *head = second;
}

void    ft_ra(t_stack **head)
{
    ft_rotate(head);
    ft_print_str("ra");
}
void    ft_rb(t_stack **head)
{
    ft_rotate(head);
    ft_print_str("rb");
}

void    ft_rr(t_stack **head_a, t_stack**head_b)
{  
    ft_rotate(head_a);
    ft_rotate(head_b);
    ft_print_str("rr");
}