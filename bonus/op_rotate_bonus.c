/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:24:16 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/10 14:03:50 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rotate_bonus(t_stack_b **head)
{
	t_stack_b	*last;
	t_stack_b	*second;
	t_stack_b	*first;

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

void	ft_ra_bonus(t_stack_b **head)
{
	ft_rotate_bonus(head);
}

void	ft_rb_bonus(t_stack_b **head)
{
	ft_rotate_bonus(head);
}

void	ft_rr_bonus(t_stack_b **head_a, t_stack_b **head_b)
{
	ft_rotate_bonus(head_a);
	ft_rotate_bonus(head_b);
}
