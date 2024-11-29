/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:06:28 by parissachat       #+#    #+#             */
/*   Updated: 2024/11/28 18:50:10 by parissachat      ###   ########.fr       */
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
void	ft_free_split(char **split)
{
	int i = 0;

	if (!split)
		return;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
