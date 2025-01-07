/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:16:47 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/07 17:42:59 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	second = first ->next;
	first->next = second ->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
}

void	ft_sa(t_stack **stack)
{
	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	ft_swap(stack);
	ft_print_str("sa");
}

void	ft_sb(t_stack **stack)
{
	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	ft_swap(stack);
	ft_print_str("sb");
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_print_str("ss");
	return ;
}
