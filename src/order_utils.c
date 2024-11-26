/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:45:56 by pchatagn          #+#    #+#             */
/*   Updated: 2024/11/26 18:55:06 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *init_nodes_a(t_stack *stack_a, t_stack *stack_b)
{
    ft_index(stack_a);
    ft_index(stack_b);
    ft_target(stack_a, stack_b);
    ft_cost_analysis(stack_a, stack_b);
    ft_find_cheapest(stack_a);
}

void    ft_index(t_stack **stack)
{
    int i;
    int median;

    if (!(*stack))
        return ;
    i = 0;
    median = ft_size_stack(&stack) / 2;
    while (stack)
    {
        (*stack)->index = i;
        if (i <= median)
            (*stack)->above_median = 1;
        else
            (*stack)->above_median = 0;
        stack = (*stack)->next;
        i++;
    }
}
void    ft_target_b(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *temp_b;
    t_stack *target_node;
    int     diff;

    while(stack_a)
    {
        temp_b = *stack_b;
        target_node = NULL;
        diff = __LONG_MAX__;
        while(temp_b)
        {
            if (temp_b->data < (*stack_a)->data && diff > (*stack_a)->data - temp_b->data)
            {
                 target_node = temp_b;
                 diff = (*stack_a)->data - target_node->data;
            }
            temp_b = temp_b->next;
        }
        if (!target_node)
            target_node = ft_find_max(stack_b);
        (*stack_a)->target_node = target_node;
        stack_a = (*stack_a)->next;
    }
}

void    ft_cost_analysis(t_stack **stack_a, t_stack **stack_b)
{
    int cost;

    while (*stack_a)
    {
        if ((*stack_a)->above_median == 1 && (*stack_a)->target_node->above_median == 1)
        {
            if ((*stack_a)->target_node->index < (*stack_a)->index)
                cost = (*stack_a)->index;
            else
                cost = (*stack_a)->target_node->index;
        }
        else if ((*stack_a)->above_median == 0 && (*stack_b)->above_median == 0)
        {
            if ((*stack_a)->target_node->index > (*stack_a)->index)
                cost = ft_size_stack(stack_a) - (*stack_a) ->index;
            else 
                cost = ft_size_stack(stack_b) - (*stack_a)->target_node->index;
        }
        else if ((*stack_a)->above_median == 1 && (*stack_b)->above_median == 0)
            cost = (*stack_a)->index + ft_size_stack(stack_b) - (*stack_a)->target_node->index;
        else if ((*stack_a)->above_median == 0 && (*stack_b)->above_median == 1)
            cost = (*stack_a)->target_node->index + ft_size_stack(stack_a) - (*stack_a) ->index;
        (*stack_a)->push_cost = cost;
        (*stack_a) = (*stack_a)->next;
    }
}

void    ft_find_cheapest(t_stack **stack)
{
    long    temp_cheapest_value;
    t_stack *temp_cheapest_node;

    if (!(*stack))
        return ;
    temp_cheapest_value = (*stack)->push_cost;
    temp_cheapest_node = *stack;
    while (*stack)
    {
        if ((*stack)->push_cost < temp_cheapest_value)
        {
            temp_cheapest_node = *stack;
            temp_cheapest_value = (*stack)->push_cost;
        }
        (*stack) = (*stack)->next;
    }
    temp_cheapest_node->cheapest = 1;
}
