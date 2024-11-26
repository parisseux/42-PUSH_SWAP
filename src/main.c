/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:51:26 by pchatagn          #+#    #+#             */
/*   Updated: 2024/11/26 17:23:44 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_validate_args(char **argv, int j, t_stack **stack,char **split_argv)
{
	int value;
	
	while (argv[j])
	{
		if (!(ft_check_number(argv[j])))
		{
			ft_cleanup(stack, split_argv);
			return (0);
		}
		value = ft_atol(argv[j]);
		ft_create_or_add_back(stack, value);
		j++;	
	}
	if (!ft_check_doublon(stack))
	{
		ft_cleanup(stack, split_argv);
		return (0);
	}
	return (1);
}

void	ft_cleanup(t_stack **stack, char **split_argv)
{
	if (stack)
		ft_free_stack(stack);
	if (split_argv)
		ft_free_split(split_argv);
}
t_stack	*ft_create_stack_a(int argc, char **argv)
{
	t_stack	*stack;
	char **split_argv;
	int j;
	
	j = 1;
	stack = NULL;
	split_argv = NULL;
	if (argc == 2)
	{
		split_argv = ft_split(argv[1], ' ');
		if (!split_argv)
			return (NULL);
		j = 0;
		argv = split_argv;
	}
	if (!ft_validate_args(argv, j, &stack, split_argv))
		return (NULL);
	if (split_argv)
			ft_free_split(split_argv);
	return (stack);
}

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
