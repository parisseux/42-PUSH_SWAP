# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 11:37:38 by pchatagn          #+#    #+#              #
#    Updated: 2025/01/07 14:37:12 by pchatagn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBDIR = libraries
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(LIBDIR)/libft -I$(LIBDIR)/ft_printf -g
RM = rm -f

SRCDIR = src
OBJDIR = obj

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
		order_utils3.c
	
LIBFT = $(LIBDIR)/libft/libft.a
FT_PRINTF = $(LIBDIR)/ft_printf/libftprintf.a

SRC = $(addprefix $(SRCDIR)/, $(FILES))
OBJ = $(addprefix $(OBJDIR)/, $(FILES:.c=.o))

SUCCESS = "\033[1;35mSuccessful compilation!\033[0m"

all: $(NAME)
	@echo $(SUCCESS)
$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)

$(LIBFT):
	@make all bonus -C $(LIBDIR)/libft

$(FT_PRINTF):
	@make -C $(LIBDIR)/ft_printf

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)  # Ensure obj/ directory exists
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@$(RM) $(OBJ)
	@rmdir $(OBJDIR) 2>/dev/null || true  
	@make -C $(LIBDIR)/libft clean      
	@make -C $(LIBDIR)/ft_printf clean 

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBDIR)/libft fclean     
	@make -C $(LIBDIR)/ft_printf fclean  
re: fclean all

.PHONY: all clean fclean re