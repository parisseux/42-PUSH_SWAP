/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:56:30 by parissachat       #+#    #+#             */
/*   Updated: 2024/11/29 15:02:09 by parissachat      ###   ########.fr       */
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

long	ft_atol(const char *str)
{
	int	i;
	int	count;
	int	res;

	res = 0;
	count = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		count = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (count == 1)
		return (-res);
	return (res);
}
