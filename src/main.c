/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:51:26 by pchatagn          #+#    #+#             */
/*   Updated: 2024/11/27 12:06:24 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int argc, char **argv)
{
    t_stack	*stack_a;
	t_stack	*stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
    if (argc < 2)
		return (1);
	stack_a = ft_create_stack_a(argc, argv);
	if (!stack_a)
		return (1);
	if (ft_size_stack(stack_a) < 2)
	{
		ft_free_stack(&stack_a);
		ft_error_message();
		return (1);
	}
	if (!ft_check_stack(&stack_a))
		ft_order(&stack_a, &stack_b);
//	print_stack(stack_a);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
