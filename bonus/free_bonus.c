/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 01:26:45 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/09 11:26:30 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void ft_free_stack_bonus(t_stack *l)
{
    t_stack *t;
    
    while (l)
    {
        t = l->next;
        free(l);
        l = t;
    }
}

void ft_clean_bonus(t_stack *a, t_stack *b)
{
    ft_free_stack_bonus(a);
    ft_free_stack_bonus(b);
}

void	ft_free_split_bonus(char **split)
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

void	ft_cleanup_bonus(t_stack **stack, char **split_argv)
{
	if (stack)
		ft_free_stack_bonus(*stack);
	if (split_argv)
		ft_free_split_bonus(split_argv);
}