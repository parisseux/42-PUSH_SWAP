/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:16:47 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/09 13:58:48 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap_bonus(t_stack **stack)
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

void	ft_sa_bonus(t_stack **stack)
{
	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	ft_swap_bonus(stack);
}

void	ft_sb_bonus(t_stack **stack)
{
	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	ft_swap_bonus(stack);
}

void	ft_ss_bonus(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap_bonus(stack_a);
	ft_swap_bonus(stack_b);
}
