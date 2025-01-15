/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:02:13 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/15 15:44:04 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_order(t_stack **stack_a, t_stack **stack_b)
{
	t_inst	*inst;

	inst = NULL;
	if (ft_check_stack(*stack_a) == 1 && *stack_b == NULL)
		return ;
	if (ft_size_stack(*stack_a) == 2)
	{
		ft_sa(stack_a, &inst);
		(void)stack_b;
	}
	else if (ft_size_stack(*stack_a) == 3)
	{
		ft_order_stack_size_3(stack_a, &inst);
		(void)stack_b;
	}
	else if (ft_size_stack(*stack_a) == 4)
		ft_order_stack_size_4(stack_a, stack_b, &inst);
	else if (ft_size_stack(*stack_a) >= 5)
		ft_order_big_stack(stack_a, stack_b, &inst);
	ft_optimise_inst(inst);
	ft_free_instructions(inst);
}

void	ft_order_stack_size_3(t_stack **stack, t_inst **inst)
{
	int	max_index;

	if (ft_check_stack(*stack))
		return ;
	max_index = ft_find_index_of_max(*stack);
	if (max_index == 0)
		ft_ra(stack, inst);
	else if (max_index == 1)
		ft_rra(stack, inst);
	if (ft_check_stack(*stack) == 0)
		ft_sa(stack, inst);
}

void	ft_order_stack_size_4(t_stack **stack_a,
			t_stack **stack_b, t_inst **inst)
{
	int	min_index;

	if (ft_check_stack(*stack_a) == 1 && *stack_b == NULL)
		return ;
	min_index = ft_find_index_of_min(*stack_a);
	if (min_index == 1)
		ft_sa(stack_a, inst);
	else if (min_index == 2)
	{
		ft_ra(stack_a, inst);
		ft_ra(stack_a, inst);
	}
	else if (min_index == 3)
		ft_rra(stack_a, inst);
	if (ft_check_stack(*stack_a) == 1 && *stack_b == NULL)
		return ;
	ft_pb(stack_a, stack_b, inst);
	ft_order_stack_size_3(stack_a, inst);
	ft_pa(stack_b, stack_a, inst);
}

void	ft_order_big_stack(t_stack **stack_a, t_stack **stack_b, t_inst **inst)
{
	int		size_a;

	if (ft_check_stack(*stack_a) == 1 && *stack_b == NULL)
		return ;
	size_a = ft_size_stack(*stack_a);
	while (size_a > 3)
	{
		ft_pb(stack_a, stack_b, inst);
		size_a = ft_size_stack(*stack_a);
	}
	ft_order_stack_size_3(stack_a, inst);
	while (*stack_b)
	{
		ft_init_nodes(*stack_a, *stack_b);
		ft_empty_b(stack_a, stack_b, inst);
	}
	if (ft_check_stack(*stack_a) == 1 && *stack_b == NULL)
		return ;
	ft_index(*stack_a);
	ft_put_smallest_on_top(stack_a, inst);
}
