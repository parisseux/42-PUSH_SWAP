/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:17:26 by pchatagn          #+#    #+#             */
/*   Updated: 2024/11/28 18:51:35 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_node_and_target_node(t_stack **stack_a, t_stack **stack_b, t_stack *node)
{
    while (*stack_a != node && *stack_b != node->target_node)
        ft_rr(stack_a, stack_b);
    ft_index(stack_a);
    ft_index(stack_b);
}

void reverse_rotate_node_and_target_node(t_stack **stack_a, t_stack **stack_b, t_stack *node)
{
    while (*stack_a != node && *stack_b != node->target_node)
        ft_rrr(stack_a, stack_b);
    ft_index(stack_a);
    ft_index(stack_b); 
}
void move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *cheapest_node;
    t_stack *temp;
    
    if (!stack_a || !(*stack_a))
        return ;
    temp = *stack_a;
    cheapest_node = NULL;
    while (temp->cheapest == 0)
            temp = temp ->next;
    cheapest_node = temp;
    if (cheapest_node->above_median == 1 && cheapest_node->target_node->above_median == 1)
        rotate_node_and_target_node(stack_a, stack_b, cheapest_node);
    if (cheapest_node->above_median == 0 && cheapest_node->target_node->above_median == 0)
        reverse_rotate_node_and_target_node(stack_a, stack_b, cheapest_node);
    ft_node_at_the_top_stack_a(stack_a, cheapest_node);
    ft_node_at_the_top_stack_b(stack_b, cheapest_node->target_node);
    ft_pb(stack_a, stack_b);
}

void    ft_node_at_the_top_stack_a(t_stack **stack, t_stack *node)
{
    int nbr_of_operation;
    if (node == *stack)
        return ;
    if (node->above_median == 1)
    {
        nbr_of_operation = node->index;
        while (nbr_of_operation > 0)
        {
            ft_ra(stack);
            nbr_of_operation--;
        }
    }
    else if (node->above_median == 0)
    {
        nbr_of_operation = ft_size_stack(*stack) - node->index;
        while (nbr_of_operation > 0)
        {
            ft_rra(stack);
            nbr_of_operation--;
        }
    }
}

void    ft_node_at_the_top_stack_b(t_stack **stack, t_stack *node)
{
    int nbr_of_operation;
    
    if (node == *stack)
        return ;
    if (node->above_median == 1)
    {
        nbr_of_operation = node->index;
        while (nbr_of_operation > 0)
        {
            ft_rb(stack);
            nbr_of_operation--;
        }
    }
    else if (node->above_median == 0)
    {
        nbr_of_operation = ft_size_stack(*stack) - node->index;
        while (nbr_of_operation > 0)
        {
            ft_rrb(stack);
            nbr_of_operation--;
        }
    }
}
