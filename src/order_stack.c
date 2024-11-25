/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:02:13 by parissachat       #+#    #+#             */
/*   Updated: 2024/11/25 16:13:06 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_order(t_stack **stack_a, t_stack **stack_b)
{
    if (ft_size_stack(*stack_a) == 2)
    {
        ft_sa(stack_a);
        (void)stack_b;
    }	
	else if (ft_size_stack(*stack_a) == 3)
    {
        ft_order_stack_size_3(stack_a);
        (void)stack_b;
    }
	//else if (ft_size_stack(stack_a) > 3)
	//	ft_order_big_stack(&stack_a, &stack_b);
}
void    ft_order_stack_size_3(t_stack **head)
{
    
    if (ft_find_index_of_max(*head) == 1)
        ft_ra(head);
    else if (ft_find_index_of_max(*head) == 2)
        ft_rra(head);
    if (ft_check_stack(head) == 0)
        ft_sa(head);
}  

/*void ft_order_big_stack(t_stack **stack_a, t_stack **stack_b)
{
    
}*/

/*Turk algorithm
while (stack_size(stack_a))
{
    //push randomly two nodes to stack b 
    ft_pb 
    ft_pb 
    // find min and max dans stack b
    
    //every a node needs a target node from stack b - target node: closest smaller number to the a node
    --> if a node cant find its target value then its target value is the biggest node from stack b

    
    //we need to calculate cost analysis to know which a node we want to push to stack b
    formula:
    push cost = x operations to bring 'a' to on top + x operations to bring 'a'->target node on top
    we then push the a node with the smallest cost 

    repeat this until there is only three numbers in stack a
    --> order stack a

    push back ot a every b node need a target value which is the closest biggest value 
    if no biggest value the target node is the smallest value
    --> every 

*/


