/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:26:30 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/09 14:03:28 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void ft_read_and_do_operation_bonus(t_stack **a, t_stack **b)
{
    char *line;

    line = get_next_line(0);
    while (line)
    {
        ft_do_operations_bonus(line, a, b);
        free(line);
        line = get_next_line(0);
    }
}
void ft_do_operations_bonus(char *inst, t_stack **a, t_stack **b)
{
    if (ft_strcmp(inst, "sa\n") == 0)
        ft_sa_bonus(a); 
    else if (ft_strcmp(inst, "sb\n") == 0)
        ft_sb_bonus(b); 
    else if (ft_strcmp(inst, "pa\n") == 0)
        ft_pa_bonus(b, a); 
    else if (ft_strcmp(inst, "pb\n") == 0)
        ft_pb_bonus(a, b); 
    else if (ft_strcmp(inst, "ra\n") == 0)
       ft_ra_bonus(a); 
    else if (ft_strcmp(inst, "rb\n") == 0)
        ft_rb_bonus(b); 
    else if (ft_strcmp(inst, "rra\n") == 0)
        ft_rra_bonus(a); 
    else if (ft_strcmp(inst, "rrb\n") == 0)
        ft_rrb_bonus(b);  
    else if (ft_strcmp(inst, "ss\n") == 0)
        ft_ss_bonus(a, b);
    else if (ft_strcmp(inst, "rr\n") == 0)
        ft_rr_bonus(a, b);
    else if (ft_strcmp(inst, "rrr\n") == 0)
        ft_rrr_bonus(a, b);
    else
        ft_printf("Error: unknown operation \"%s\".\n", inst);
}
