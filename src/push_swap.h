/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:37:20 by pchatagn          #+#    #+#             */
/*   Updated: 2024/11/25 16:10:04 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

//fonctions utils
t_stack	*ft_new_node(int value);
void	ft_create_or_add_back(t_stack **head, int value);
void    ft_free_stack(t_stack **stack);
void	print_stack(t_stack *head);
int 	ft_check_number(char *argv);
int 	ft_check_doublon(t_stack **head);
void    ft_error_message(void);
void	ft_free_split(char **split);
int		ft_size_stack(t_stack *stack);
void	ft_create_or_add_front(t_stack **head, int value);
void    ft_delete_first_node(t_stack **head);
void 	ft_print_str(char *str);
int 	ft_find_index_of_max(t_stack *head);
int 	ft_validate_args(char **argv, int j, t_stack **stack,char **split_argv);
void	ft_cleanup(t_stack **stack, char **split_argv);

//operations 
void 	ft_swap(t_stack **stack);
void 	ft_sa(t_stack **stack);
void 	ft_sb(t_stack **stack);
void 	ft_ss(t_stack **stack_a, t_stack **stack_b);
void    ft_pa(t_stack **src, t_stack **dst);
void    ft_pb(t_stack **src, t_stack **dst);
void    ft_reverse_rotate(t_stack **head);
void    ft_rra(t_stack **head);
void    ft_rrb(t_stack **head);
void    ft_rrr(t_stack **head_a, t_stack **head_b);
void    ft_rotate(t_stack **head);
void    ft_ra(t_stack **head);
void    ft_rb(t_stack **head);
void    ft_rr(t_stack **head_a, t_stack**head_b);

//fonctions to order stack
void	ft_order(t_stack **stack_a, t_stack **stack_b);
int 	ft_check_stack(t_stack **head);
void    ft_order_stack_size_2(t_stack **head);
void    ft_order_stack_size_3(t_stack **head);
//void ft_order_big_stack(t_stack **stack_a, t_stack **stack_b);

#endif