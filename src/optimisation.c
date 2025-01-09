/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:00:36 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/09 14:41:19 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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
void ft_changement_inst(t_inst *temp, char *new_inst)
{
    t_inst *to_delete;
    
    free(temp->inst);
    temp->inst = ft_strdup(new_inst);
    to_delete = temp->next;
    temp->next = temp->next->next;
    free(to_delete->inst);
    free(to_delete);  
}
void ft_check_inst1(t_inst *head)
{
    t_inst *temp;

    if (!head)
        return;

    temp = head;
    while (temp && temp->next)
    { 
        if ((ft_strncmp(temp->inst, "ra", 3) == 0 && ft_strncmp(temp->next->inst, "rb", 3) == 0) ||
            (ft_strncmp(temp->inst, "rb", 3) == 0 && ft_strncmp(temp->next->inst, "ra", 3) == 0))
            ft_changement_inst(temp, "rr");
        else if ((ft_strncmp(temp->inst, "rra", 4) == 0 && ft_strncmp(temp->next->inst, "rrb", 4) == 0) ||
                 (ft_strncmp(temp->inst, "rrb", 4) == 0 && ft_strncmp(temp->next->inst, "rra", 4) == 0))
            ft_changement_inst(temp, "rrr");
        else if ((ft_strncmp(temp->inst, "sa", 3) == 0 && ft_strncmp(temp->next->inst, "sb", 3) == 0) ||
                 (ft_strncmp(temp->inst, "sb", 3) == 0 && ft_strncmp(temp->next->inst, "sa", 3) == 0))
            ft_changement_inst(temp, "ss");
        else
            temp = temp->next;
    }
}

void ft_remove_inst(t_inst **head, t_inst *temp)
{
    t_inst *to_delete1;
    t_inst *to_delete2;
    
    if (!head || !*head || !temp || !temp->next)
        return;
    to_delete1 = temp;
    to_delete2 = temp->next; 

    if (to_delete1 == *head)
    {
        *head = to_delete2->next;
        if (*head)
            (*head)->prev = NULL;
    } 
    else 
    {
        if (to_delete2->next)
            to_delete1->prev->next = to_delete2->next;
        else
            to_delete1->prev->next = NULL;
    }
    free(to_delete1->inst);
    free(to_delete1);
    free(to_delete2->inst);
    free(to_delete2);
}
void ft_check_inst2(t_inst **head)
{
    t_inst *temp;
    t_inst *next_valid;
    if (!head || !*head) 
        return;

    temp = *head;

    while (temp && temp->next) {
        if ((ft_strcmp(temp->inst, "pa") == 0 && ft_strcmp(temp->next->inst, "pb") == 0) ||
            (ft_strcmp(temp->inst, "pb") == 0 && ft_strcmp(temp->next->inst, "pa") == 0) ||
            (ft_strcmp(temp->inst, "rra") == 0 && ft_strcmp(temp->next->inst, "ra") == 0) ||
            (ft_strcmp(temp->inst, "ra") == 0 && ft_strcmp(temp->next->inst, "rra") == 0) ||
            (ft_strcmp(temp->inst, "rb") == 0 && ft_strcmp(temp->next->inst, "rrb") == 0) ||
            (ft_strcmp(temp->inst, "rrb") == 0 && ft_strcmp(temp->next->inst, "rb") == 0) ||
            (ft_strcmp(temp->inst, "sa") == 0 && ft_strcmp(temp->next->inst, "sa") == 0)) 
        {
            next_valid = temp->next->next;
            ft_remove_inst(head, temp);
            temp = next_valid;
        } 
        else 
            temp = temp->next;
    }
}

void ft_print_inst(t_inst *head)
{
    t_inst *temp;

    temp = head;
    while (temp)
    {
        ft_print_str(temp->inst);
        temp = temp->next;
    }    
}
