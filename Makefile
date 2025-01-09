# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 11:37:38 by pchatagn          #+#    #+#              #
#    Updated: 2025/01/09 14:36:21 by parissachat      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUSNAME = checker
LIBDIR = libraries
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I./include -I$(LIBDIR)/libft -I$(LIBDIR)/ft_printf -g

RM = rm -f

SRCDIR = src
OBJDIR = obj
BONUSDIR = bonus
BONUSOBJDIR = bonus_obj

FILES = main.c \
		free.c \
		create_check_stack.c \
		order_stack.c \
		op_swap.c \
		op_rotate.c \
		op_reverse_rotate.c \
		op_push.c \
		utils.c \
		stack_utils.c \
		stack_utils2.c \
		stack_utils3.c \
		order_utils.c \
		order_utils2.c \
		order_utils3.c \
		optimisation.c \
		normalise.c

BONUS_FILES = main_bonus.c \
			free_bonus.c \
			bonus_utils.c \
			bonus_utils2.c \
			bonus_utils3.c \
			implement_operations.c \
			op_push_bonus.c \
			op_reverse_rotate_bonus.c \
			op_rotate_bonus.c \
			op_swap_bonus.c 

LIBFT = $(LIBDIR)/libft/libft.a
FT_PRINTF = $(LIBDIR)/ft_printf/libftprintf.a

SRC = $(addprefix $(SRCDIR)/, $(FILES))
OBJ = $(addprefix $(OBJDIR)/, $(FILES:.c=.o))
BONUS_SRC = $(addprefix $(BONUSDIR)/, $(BONUS_FILES))
BONUS_OBJ = $(addprefix $(BONUSOBJDIR)/, $(BONUS_FILES:.c=.o))

SUCCESS = "\033[1;35mSuccessful compilation of PUSH_SWAP!\033[0m"
SUCCESS2 = "\033[1;32mSuccessful compilation of PUSH_SWAP BONUS!\033[0m"

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)
	@echo $(SUCCESS)

bonus: $(BONUSNAME)

$(BONUSNAME): $(BONUS_OBJ) $(LIBFT) $(FT_PRINTF)
	@$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) $(FT_PRINTF) -o $(BONUSNAME)
	@echo $(SUCCESS2)

$(LIBFT):
	@make all -C $(LIBDIR)/libft

$(FT_PRINTF):
	@make -C $(LIBDIR)/ft_printf

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BONUSOBJDIR)/%.o: $(BONUSDIR)/%.c
	@mkdir -p $(BONUSOBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	@$(RM) $(OBJ) $(BONUS_OBJ)
	@rmdir $(OBJDIR) 2>/dev/null || true  
	@rmdir $(BONUSOBJDIR) 2>/dev/null || true  
	@make -C $(LIBDIR)/libft clean      
	@make -C $(LIBDIR)/ft_printf clean 

fclean: clean
	@$(RM) $(NAME) $(BONUSNAME)
	@make -C $(LIBDIR)/libft fclean     
	@make -C $(LIBDIR)/ft_printf fclean 

re: fclean all

.PHONY: all clean fclean re bonus
