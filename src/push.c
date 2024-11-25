/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:23:07 by parissachat       #+#    #+#             */
/*   Updated: 2024/11/25 14:35:46 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_pa(t_stack **src, t_stack **dst)
{
    if (!src || !(*src))
        return ;
    ft_create_or_add_front(dst, (*src)->data);
    ft_delete_first_node(src);
    ft_print_str("pa");
}

void    ft_pb(t_stack **src, t_stack **dst)
{
    if (!src || !(*src))
        return ;
    ft_create_or_add_front(dst, (*src)->data);
    ft_delete_first_node(src);
    ft_print_str("pb");
}
