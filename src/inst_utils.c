/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:01:53 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/09 20:09:17 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_print_inst(t_inst *head)
{
    t_inst *temp;

    temp = head;
    while (temp)
    {
        ft_printf("%s\n", (temp->inst));
        temp = temp->next;
    }    
}

void    ft_add_instruction(t_inst **head, const char *inst)
{
    t_inst *temp;
    t_inst *new;

    new = malloc(sizeof(t_inst));
    if (!new)
        exit(1);
    new->inst = ft_strdup(inst);
    if (!new->inst)
    {
        free(new);
        exit(1);
    }
    new->next = NULL;
    new->prev = NULL;
    if (!*head)
        *head = new;
    else
    {
        temp = *head;
        while (temp->next)
            temp = temp->next;
        temp->next = new;
         new->prev = temp;
    }
}

int ft_nombre_instruction(t_inst *inst)
{
	int size;
	size = 0;
    while (inst) {
        size++;
        inst = inst->next;
    }
    return size;
}
