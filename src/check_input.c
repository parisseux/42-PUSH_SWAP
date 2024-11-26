/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:55:40 by pchatagn          #+#    #+#             */
/*   Updated: 2024/11/26 15:27:10 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
int ft_check_doublon(t_stack **head)
{
    t_stack *temp;
    t_stack *check;
    
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
int ft_check_number(char *argv)
{
    int i;
    
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
void    ft_error_message(void)
{
    write(2, "Error:\n", 7);
    write(2, "- Input must contain only positive or negative numbers.\n", 57);
    write(2, "- No duplicates are allowed.\n", 30);
    write(2, "- At least two numbers are required.\n", 38);
}
