/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:02:13 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/08 22:04:30 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted_and_empty_b(t_stack **stack_a, t_stack **stack_b)
{
    if (ft_check_stack(stack_a) == 1 && !*stack_b)
		return (1);
	return (0); 
}
void	ft_order(t_stack **stack_a, t_stack **stack_b)
{
	t_inst	*inst;
	int size;

	inst = NULL;
	if (is_sorted_and_empty_b(stack_a, stack_b) == 1)
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
	size = 0;
	while (size != ft_nombre_instruction(inst))
	{
		size = ft_nombre_instruction(inst);
		ft_check_inst1(inst);
		ft_check_inst2(&inst);
	}
	ft_print_inst(inst);
	ft_free_instructions(inst);
}

int ft_nombre_instruction(t_inst *inst)
{
	int size;
	size = 0;
    while (inst) {
        size++;
        inst = inst->next;
    }
    return size;
}

void	ft_order_stack_size_3(t_stack **stack, t_inst **inst)
{
	int	max_index;

	if (ft_check_stack(stack))
        return ;
	max_index = ft_find_index_of_max(*stack);
	if (max_index == 0)
		ft_ra(stack, inst);
	else if (max_index == 1)
		ft_rra(stack, inst);
	if (ft_check_stack(stack) == 0)
		ft_sa(stack, inst);
}

void	ft_order_stack_size_4(t_stack **stack_a, t_stack **stack_b,  t_inst **inst)
{
	int	min_index;

	if (is_sorted_and_empty_b(stack_a, stack_b) == 1)
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
	if (is_sorted_and_empty_b(stack_a, stack_b) == 1)
		return ; 
	ft_pb(stack_a, stack_b, inst);
	ft_order_stack_size_3(stack_a, inst);
	ft_pa(stack_b, stack_a, inst);
}

void	ft_order_big_stack(t_stack **stack_a, t_stack **stack_b,  t_inst **inst)
{
	if (is_sorted_and_empty_b(stack_a, stack_b) == 1)
		return ; 
	ft_pb(stack_a, stack_b, inst);
	ft_pb(stack_a, stack_b, inst);
	while (ft_size_stack(*stack_a) > 3 && ft_check_stack(stack_a) == 0)
	{
		init_nodes_a(stack_a, stack_b);
		move_a_to_b(stack_a, stack_b, inst);
	}
	if (ft_size_stack(*stack_a) == 3 && ft_check_stack(stack_a) == 0)
		ft_order_stack_size_3(stack_a, inst);
	while (*stack_b)
	{
		init_nodes_b(stack_a, stack_b);
		move_b_to_a(stack_a, stack_b, inst);
	}
	if (is_sorted_and_empty_b(stack_a, stack_b) == 1)
		return ; 
	ft_index(stack_a);
	ft_min_on_top(stack_a, inst);
}
