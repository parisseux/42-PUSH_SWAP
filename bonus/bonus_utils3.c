/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:41:10 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/09 14:01:01 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_delete_first_node_bonus(t_stack **head)
{
	t_stack	*temp;

	if (!(*head) || !head)
		return ;
	temp = *head;
	*head = (*head)->next;
	if (*head)
		(*head)->prev = NULL;
	free(temp);
}

void	ft_create_or_add_front_bonus(t_stack **head, int value)
{
	t_stack	*new;

	new = ft_new_node_bonus(value);
	if (!new)
		return ;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	new->next = *head;
	(*head)->prev = new;
	*head = new;
}