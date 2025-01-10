/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:00:21 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/10 13:38:42 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_normalise_stack(t_stack *head)
{
	int		size;
	t_stack	*temp;
	long	*tab;

	size = 0;
	temp = head;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	tab = (long *)malloc(size * sizeof(long));
	if (!tab)
		exit(1);
	ft_fill_and_order_tab(head, tab, size);
	ft_add_data_norm(head, tab, size);
	ft_replace_data_with_normalised(head);
	free(tab);
}

void	ft_replace_data_with_normalised(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	while (temp)
	{
		temp->data = temp->data_norm;
		temp = temp->next;
	}
}

void	ft_fill_and_order_tab(t_stack *head, long *tab, int size)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = head;
	while (temp)
	{
		tab[i] = temp->data;
		temp = temp->next;
		i++;
	}
	ft_order_tab(tab, size);
}

void	ft_order_tab(long *tab, int size)
{
	int	check;
	int	i;

	check = 0;
	while (check == 0)
	{
		check = 1;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap_long(tab, i);
				check = 0;
			}
			else
				i++;
		}
	}
}

void	ft_add_data_norm(t_stack *head, long *tab, int size)
{
	int		i;
	t_stack	*temp;

	temp = head;
	while (temp)
	{
		i = 0;
		while (i < size)
		{
			if (temp->data == tab[i])
			{
				temp->data_norm = i + 1;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}
}
