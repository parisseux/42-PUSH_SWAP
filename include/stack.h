/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:53:41 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/09 11:12:35 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_stack
{
	struct s_stack	*next;
	long			data;
	struct s_stack	*prev;
	#ifdef PUSH_SWAP_H
	int				above_median;
	int				cheapest;
	int				index;
	struct s_stack	*target_node;
	int				push_cost;
	long 			data_norm;
	#endif
}					t_stack;

typedef struct s_inst {
    char *inst;  
    struct s_inst *next;
	struct s_inst *prev;
} t_inst;

#endif
