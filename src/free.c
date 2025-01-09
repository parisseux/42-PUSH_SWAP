/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:56:17 by pchatagn          #+#    #+#             */
/*   Updated: 2025/01/09 14:40:47 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
void	ft_free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

void	ft_cleanup(t_stack **stack, char **split_argv)
{
	if (stack)
		ft_free_stack(stack);
	if (split_argv)
		ft_free_split(split_argv);
}

void ft_free_instructions(t_inst *head)
{
    t_inst *temp;
	
    while (head) {
        temp = head;
        head = head->next;
        free(temp->inst);
        free(temp);
    }
}