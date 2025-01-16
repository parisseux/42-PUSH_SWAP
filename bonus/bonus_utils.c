/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:03:09 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/16 14:42:57 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack_b	*ft_create_stack_a_bonus(int argc, char **argv)
{
	t_stack_b	*stack;
	char		**split_argv;
	int			j;

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
	if (!ft_validate_args_bonus(argv, j, &stack, split_argv))
		return (NULL);
	if (split_argv)
		ft_free_split_bonus(split_argv);
	return (stack);
}

int	ft_validate_args_bonus(char **argv,
	int j, t_stack_b **stack, char **split_argv)
{
	int	value;

	while (argv[j])
	{
		if (!(ft_check_number_bonus(argv[j])))
		{
			ft_cleanup_bonus(stack, split_argv);
			return (0);
		}
		value = ft_atol(argv[j]);
		ft_create_or_add_back_bonus(stack, value);
		j++;
	}
	if (!ft_check_doublon_bonus(stack))
	{
		ft_cleanup_bonus(stack, split_argv);
		return (0);
	}
	return (1);
}

int	ft_check_doublon_bonus(t_stack_b **head)
{
	t_stack_b	*temp;
	t_stack_b	*check;

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
				ft_error_message_bonus();
				return (0);
			}
			check = check->next;
		}
		temp = temp->next;
	}
	return (1);
}

int	ft_check_number_bonus(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	if (argv[i] == '\0')
	{
		ft_error_message_bonus();
		return (0);
	}
	while (argv[i])
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))
		{
			ft_error_message_bonus();
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_error_message_bonus(void)
{
	write(2, "Error:\n", 7);
	write(2, "- Input must contain only positive or negative numbers.\n", 57);
	write(2, "- No duplicates are allowed.\n", 30);
}
