/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:45:56 by pchatagn          #+#    #+#             */
/*   Updated: 2024/11/29 15:42:55 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_nodes_a(t_stack **stack_a, t_stack **stack_b)
{
    ft_index(stack_a);
    ft_index(stack_b);
    ft_target_b(stack_a, stack_b);
    ft_cost_analysis_a(stack_a, stack_b);
    ft_find_cheapest(stack_a);
}

void    ft_index(t_stack **stack)
{
    int i;
    int median;
    t_stack *temp;

    if (!(*stack) || !stack)
        return ;
    i = 0;
    median = ft_size_stack(*stack) / 2;
    temp = *stack;
    while (temp)
    {
        temp->index = i;
        if (i < median)
            temp->above_median = 1;
        else
            temp->above_median = 0;
        i++;
        temp = temp->next;
    }
}
void    ft_target_b(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *temp_b;
    t_stack *temp_a;
    t_stack *target_node;
    long     diff;

    temp_a = *stack_a;
    while(temp_a)
    {
        temp_b = *stack_b;
        target_node = NULL;
        diff = __LONG_MAX__;
        while(temp_b)
        {
            if (temp_b->data < temp_a->data && diff > (temp_a->data - temp_b->data))
            {
                 target_node = temp_b;
                 diff = temp_a->data - target_node->data;
            }
            temp_b = temp_b->next;
        }
        if (!target_node)
            target_node = ft_find_max(*stack_b);
        temp_a->target_node = target_node;
        temp_a = temp_a->next;
    }
}

void    ft_cost_analysis_a(t_stack **stack_a, t_stack **stack_b)
{
    int cost;
    t_stack *temp_a;

    temp_a = *stack_a;
    while (temp_a != NULL)
    {
        cost = 0;
        if (temp_a->above_median == 1 && temp_a->target_node->above_median == 1)
        {
            if (temp_a->target_node->index < temp_a->index)
                cost = temp_a->index;
            else
                cost = temp_a->target_node->index;
        }
        else if (temp_a->above_median == 0 && temp_a->target_node->above_median == 0)
        {
            if (temp_a->target_node->index < temp_a->index)
                cost = ft_size_stack(*stack_a) -  temp_a->index;
            else 
                cost = ft_size_stack(*stack_b) - temp_a->target_node->index;
        }
        else if (temp_a->above_median == 1 && temp_a->target_node->above_median == 0)
             cost = temp_a->index + ft_size_stack(*stack_b) - temp_a->target_node->index;
           
        else if (temp_a->above_median == 0 && temp_a->target_node->above_median == 1)
            cost = temp_a->target_node->index + ft_size_stack(*stack_a) - temp_a->index;
        temp_a->push_cost = cost;
        temp_a = temp_a->next;
    }
}

void    ft_find_cheapest(t_stack **stack)
{
    int    temp_cheapest_value;
    t_stack *temp_cheapest_node;
    t_stack *temp;

    if (!(*stack))
        return ;
    temp = *stack;
    while (temp)
    {
        temp->cheapest = 0;
        temp = temp->next;
    }
    temp = *stack;
    temp_cheapest_value = temp->push_cost;
    temp_cheapest_node = temp;
    while (temp)
    {
        if (temp->push_cost < temp_cheapest_value)
        {
            temp_cheapest_node = temp;
            temp_cheapest_value = temp->push_cost;
        }
        temp = temp->next;
    }
    temp_cheapest_node->cheapest = 1;
}
