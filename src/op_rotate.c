/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:24:16 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/10 13:36:24 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **head)
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

void	ft_ra(t_stack **head, t_inst **inst)
{
	ft_rotate(head);
	ft_add_instruction(inst, "ra");
}

void	ft_rb(t_stack **head, t_inst **inst)
{
	ft_rotate(head);
	ft_add_instruction(inst, "rb");
}

void	ft_rr(t_stack **head_a, t_stack**head_b, t_inst **inst)
{
	ft_rotate(head_a);
	ft_rotate(head_b);
	ft_add_instruction(inst, "rr");
}

void	ft_rotate_both(t_stack **a, t_stack **b, t_stack *node, t_inst **inst)
{
	while (*a != node->target_node && *b != node)
		ft_rr(a, b, inst);
	ft_index(*a);
	ft_index(*b);
}
