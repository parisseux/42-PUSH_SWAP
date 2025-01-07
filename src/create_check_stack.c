/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_and_check_input.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:06:28 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/07 12:00:58 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_validate_args(char **argv, int j, t_stack **stack, char **split_argv)
{
	int	value;

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

t_stack	*ft_create_stack_a(int argc, char **argv)
{
	t_stack	*stack;
	char	**split_argv;
	int		j;

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
int	ft_check_doublon(t_stack **head)
{
	t_stack	*temp;
	t_stack	*check;

	if (!head || !(*head))
		return (1);
	temp = *head;
	while (temp)
	{
		check = temp->next;
		while (check)
		{
			if (temp->data == check->data)
			{
				ft_error_message();
				return (0);
			}
			check = check->next;
		}
		temp = temp->next;
	}
	return (1);
}

int	ft_check_number(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	if (argv[i] == '\0')
	{
		ft_error_message();
		return (0);
	}
	while (argv[i])
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))
		{
			ft_error_message();
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_error_message(void)
{
	write(2, "Error:\n", 7);
	write(2, "- Input must contain only positive or negative numbers.\n", 57);
	write(2, "- No duplicates are allowed.\n", 30);
	write(2, "- At least two numbers are required.\n", 38);
}

