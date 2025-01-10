/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:36:24 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/10 14:03:24 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_reverse_rotate_bonus(t_stack_b **head)
{
	t_stack_b	*last;
	t_stack_b	*first;

	if (!head || !(*head) || !(*head)->next)
		return ;
	first = *head;
	while (first->next != NULL)
	{
		last = first;
		first = first->next;
	}
	first->prev = NULL;
	last->next = NULL;
	first->next = *head;
	*head = first;
}

void	ft_rra_bonus(t_stack_b **head)
{
	ft_reverse_rotate_bonus(head);
}

void	ft_rrb_bonus(t_stack_b **head)
{
	ft_reverse_rotate_bonus(head);
}

void	ft_rrr_bonus(t_stack_b **head_a, t_stack_b **head_b)
{
	ft_reverse_rotate_bonus(head_a);
	ft_reverse_rotate_bonus(head_b);
}
