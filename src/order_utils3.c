/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:51:15 by parissachat       #+#    #+#             */
/*   Updated: 2024/11/29 15:20:34 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    init_nodes_b(t_stack **stack_a, t_stack **stack_b)
{
    ft_index(stack_a);
    ft_index(stack_b);
    ft_target_a(stack_a, stack_b);
    ft_cost_analysis_b(stack_a, stack_b);
    ft_find_cheapest(stack_b);
}

void    move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *cheapest_node;
    t_stack *temp;
    
    if (!stack_b || !(*stack_b))
        return ;
    temp = *stack_b;
    cheapest_node = NULL;
    while (temp->cheapest == 0)
            temp = temp ->next;
    cheapest_node = temp;
    if (cheapest_node->above_median == 1 && cheapest_node->target_node->above_median == 1)
        rotate_node_and_target_node(stack_b, stack_a, cheapest_node);
    if (cheapest_node->above_median == 0 && cheapest_node->target_node->above_median == 0)
        reverse_rotate_node_and_target_node(stack_b, stack_a, cheapest_node);
    ft_node_at_the_top_stack_a(stack_a, cheapest_node->target_node);
    ft_node_at_the_top_stack_b(stack_b, cheapest_node);
    ft_pa(stack_b, stack_a);
}

void    ft_target_a(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *temp_b;
    t_stack *temp_a;
    t_stack *target_node;
    long     diff;
    
    temp_b = *stack_b;
    while (temp_b)
    {
        temp_a = *stack_a;
        target_node = NULL;
        diff = __LONG_MAX__;
        while (temp_a)
        {
            if (temp_a->data > temp_b->data && diff > (temp_a->data - temp_b->data))
            {
                target_node = temp_a;
                diff = temp_a->data - temp_b->data;
            }
            temp_a = temp_a->next;
        }
        if (!target_node)
            target_node = ft_find_min(*stack_a);
        temp_b->target_node = target_node;
        temp_b = temp_b->next;
    } 
}

void    ft_cost_analysis_b(t_stack **stack_a, t_stack **stack_b)
{
    int cost;
    t_stack *temp_b;

    temp_b = *stack_b;
    while (temp_b != NULL)
    {
        cost = 0;
        if (temp_b->above_median == 1 && temp_b->target_node->above_median == 1)
        {
            if (temp_b->target_node->index < temp_b->index)
                cost = temp_b->index;
            else
                cost = temp_b->target_node->index;
        }
        else if (temp_b->above_median == 0 && temp_b->target_node->above_median == 0)
        {
            if (temp_b->target_node->index < temp_b->index)
                cost = ft_size_stack(*stack_b) -  temp_b->index;
            else 
                cost = ft_size_stack(*stack_a) - temp_b->target_node->index;
        }
        else if (temp_b->above_median == 1 && temp_b->target_node->above_median == 0)
            cost = temp_b->index + ft_size_stack(*stack_a) - temp_b->target_node->index;
        else if (temp_b->above_median == 0 && temp_b->target_node->above_median == 1)

            cost = temp_b->target_node->index + ft_size_stack(*stack_b) - temp_b->index;
        temp_b->push_cost = cost;
        temp_b = temp_b->next;
    }
}

void ft_min_on_top(t_stack **stack_a)
{
    t_stack *min;
    int i;
    
    min = ft_find_min(*stack_a);
    if (min->above_median == 1)
    {
        i = min->index;
        while (i > 0)
        {
            ft_ra(stack_a);
            i--;
        }
    }
    else 
    {
        i = ft_size_stack(*stack_a) - min->index;
        while (i > 0)
        {
           ft_rra(stack_a);
           i--;
        }
    }   
}
