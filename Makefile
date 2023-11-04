# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 13:16:39 by karisti-          #+#    #+#              #
#    Updated: 2023/11/04 11:42:10 by karisti-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project compilation files and directories

NAME	=	push_swap

CFILE	=	main.c \
			parser.c \
			op_swap.c \
			op_push.c \
			op_rotate.c \
			op_reverse_rotate.c \
			sort.c \
			helpers_stacks.c \
			helpers_sort.c

SRCSFD	=	srcs/
OBJSFD	=	objs/
HDR_INC	=	-I./includes

SRCS	=	$(addprefix $(SRCSFD), $(CFILE))
OBJS	=	$(addprefix $(OBJSFD), $(CFILE:.c=.o))
# # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# Libraries
LIBFT	=	libft/bin/libft.a
# # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# Compilation
COMP	=	gcc
CFLAGS	=	-Wall -Wextra -Werror
# # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# Colors
RED		= \033[0;31m
GREEN	= \033[0;32m
NONE	= \033[0m
# # # # # # # # # # # # # # # # # # # # # # # # # # # # #

all: check_libft project $(NAME)
	@echo "... project ready"

check_libft: $(LIBFT)

project:
	@echo "Checking project ..."

projectb:
	@echo "Checking project bonus ..."

$(LIBFT):
	@make -C libft extras

$(OBJSFD):
	@mkdir $@
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ directory"

$(OBJSFD)%.o: $(SRCSFD)%.c
	@$(COMP) $(CFLAGS) $(HDR_INC) -o $@ -c $<
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ object"

$(NAME): $(OBJSFD) $(OBJS) 
	@$(COMP) $(CFLAGS) $(OBJS) $(LIBFT) -o $@
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ executable"

bonus: check_libft projectb $(NAME)
	@echo "... project bonus ready"

clean:
	@echo "Cleaning project ..."
	@/bin/rm -rf $(OBJSFD)
	@echo "\t[ $(RED)✗$(NONE) ] Objects directory"
	@make -C ./libft clean

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\t[ $(RED)✗$(NONE) ] $(NAME) executable"
	@make -C ./libft fclean

re: fclean all

test: all
	@ARG=$$(seq 0 1000 | sort -R | tail -n 500 | tr '\n' ' ') ; ./push_swap $$ARG | ./checker_Mac $$ARG; ./push_swap $$ARG | wc -l

testlog: all
	@ARG=$$(seq 0 1000 | sort -R | tail -n 500 | tr '\n' ' ') ; ./push_swap $$ARG

testcomp: all
	@ARG=$$(seq 0 1000 | sort -R | tail -n 500 | tr '\n' ' ') ; ./push_swap $$ARG | wc -l; ./push_swap1 $$ARG | wc -l;
	
.PHONY: check_libft project all clean fclean re test
