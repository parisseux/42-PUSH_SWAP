/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:36:24 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/09 19:52:08 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack **head)
{
	t_stack	*last;
	t_stack	*first;

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

void	ft_rra(t_stack **head, t_inst **inst)
{
	ft_reverse_rotate(head);
	ft_add_instruction(inst, "rra");
}

void	ft_rrb(t_stack **head, t_inst **inst)
{
	ft_reverse_rotate(head);
	ft_add_instruction(inst, "rrb");
}

void	ft_rrr(t_stack **head_a, t_stack **head_b, t_inst **inst)
{
	ft_reverse_rotate(head_a);
	ft_reverse_rotate(head_b);
	ft_add_instruction(inst, "rrr");
}

void	ft_rev_rotate_both(t_stack **a, t_stack **b, t_stack *node, t_inst **inst)
{
	while (*a != node->target_node && *b != node)
		ft_rrr(a, b, inst);
	ft_index(*a);
	ft_index(*b);
}
