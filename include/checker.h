/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 01:14:39 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/10 14:07:51 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "ft_printf.h"
# include "stack.h"

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

//free
void		ft_cleanup_bonus(t_stack_b **stack, char **split_argv);
void		ft_free_split_bonus(char **split);
void		ft_clean_bonus(t_stack_b *a, t_stack_b *b);
void		ft_free_stack_bonus(t_stack_b *l);

//utils 
t_stack_b	*ft_create_stack_a_bonus(int argc, char **argv);
int			ft_validate_args_bonus(char **argv, int j,
				t_stack_b **stack, char **split_argv);
int			ft_check_doublon_bonus(t_stack_b **head);
int			ft_check_number_bonus(char *argv);
void		ft_error_message_bonus(void);
void		ft_create_or_add_back_bonus(t_stack_b **head, int value);
t_stack_b	*ft_new_node_bonus(int value);
int			ft_is_stack_order_bonus(t_stack_b *a, t_stack_b *b);
int			ft_size_stack_bonus(t_stack_b *stack);
void		ft_delete_first_node_bonus(t_stack_b **head);
void		ft_create_or_add_front_bonus(t_stack_b **head, int value);
void		ft_read_and_do_operation_bonus(t_stack_b **a, t_stack_b **b);
void		ft_do_operations_bonus(char *inst, t_stack_b **a, t_stack_b **b);

//operations_bonus 
void		ft_pa_bonus(t_stack_b **src, t_stack_b **dst);
void		ft_pb_bonus(t_stack_b **src, t_stack_b **dst);
void		ft_reverse_rotate_bonus(t_stack_b **head);
void		ft_rra_bonus(t_stack_b **head);
void		ft_rrb_bonus(t_stack_b **head);
void		ft_rrr_bonus(t_stack_b **head_a, t_stack_b **head_b);
void		ft_swap_bonus(t_stack_b **stack);
void		ft_sa_bonus(t_stack_b **stack);
void		ft_sb_bonus(t_stack_b **stack);
void		ft_ss_bonus(t_stack_b **stack_a, t_stack_b **stack_b);
void		ft_rotate_bonus(t_stack_b **head);
void		ft_ra_bonus(t_stack_b **head);
void		ft_rb_bonus(t_stack_b **head);
void		ft_rr_bonus(t_stack_b **head_a, t_stack_b **head_b);

#endif