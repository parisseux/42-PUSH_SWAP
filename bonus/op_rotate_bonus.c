/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:24:16 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/09 13:58:43 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rotate_bonus(t_stack **head)
{
	t_stack	*last;
	t_stack	*second;
	t_stack	*first;

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

void	ft_ra_bonus(t_stack **head)
{
	ft_rotate_bonus(head);
}

void	ft_rb_bonus(t_stack **head)
{
	ft_rotate_bonus(head);
}

void	ft_rr_bonus(t_stack **head_a, t_stack**head_b)
{
	ft_rotate_bonus(head_a);
	ft_rotate_bonus(head_b);
}
