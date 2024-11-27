# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 11:37:38 by pchatagn          #+#    #+#              #
#    Updated: 2024/11/27 15:51:19 by parissachat      ###   ########.fr        #
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
		create_stack.c \
		check_input.c \
		utils.c \
        stack_utils.c \
		stack_utils2.c \
		stack_utils3.c \
		swap.c \
		rotate.c \
		reverse_rotate.c \
		push.c \
		order_stack.c \
		order_utils.c \
		order_utils2.c
		

LIBFT = $(LIBDIR)/libft/libft.a
FT_PRINTF = $(LIBDIR)/ft_printf/libftprintf.a

SRC = $(addprefix $(SRCDIR)/, $(FILES))
OBJ = $(addprefix $(OBJDIR)/, $(FILES:.c=.o))

all: $(NAME)

# Rule to link the final executable
$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)

# Rule to build libft.a
$(LIBFT):
	@make all bonus -C $(LIBDIR)/libft

# Rule to build libftprintf.a
$(FT_PRINTF):
	@make -C $(LIBDIR)/ft_printf

# Rule to compile .c files into .o files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)  # Ensure obj/ directory exists
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	$(RM) $(OBJ)
	@rmdir $(OBJDIR) 2>/dev/null || true  # Remove obj/ only if empty
	@make all bonus -C $(LIBDIR)/libft clean
	@make -C $(LIBDIR)/ft_printf clean

# Clean everything including the executable
fclean: clean
	$(RM) $(NAME)
	@make all bonus -C $(LIBDIR)/libft fclean
	@make -C $(LIBDIR)/ft_printf fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re

