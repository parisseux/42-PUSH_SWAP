/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:53:41 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/10 14:09:10 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_stack
{
	struct s_stack	*next;
	long			data;
	struct s_stack	*prev;
	int				above_median;
	int				cheapest;
	int				index;
	struct s_stack	*target_node;
	int				push_cost;
	long			data_norm;
}					t_stack;

typedef struct s_stack_b
{
	struct s_stack_b	*next;
	long				data;
	struct s_stack_b	*prev;
}	t_stack_b;

typedef struct s_inst {
	char			*inst;
	struct s_inst	*next;
	struct s_inst	*prev;
}	t_inst;

#endif
