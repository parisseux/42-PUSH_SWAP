/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:56:30 by parissachat       #+#    #+#             */
/*   Updated: 2024/11/22 13:56:46 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_print_str(char *str)
{
    int i;

    i = 0;
    while (str[i])
    { 
        write(1, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
}