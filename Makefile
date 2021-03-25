# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 15:05:09 by hthomas           #+#    #+#              #
#    Updated: 2021/03/25 16:34:34 by hthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

CC				=	clang
CFLAGS			=	-Wall -Werror -Wextra
LDFLAGS			=	-g3 -fsanitize=address #-fsanitize=leak

SRCS_COMMON		=	srcs/find_median.c			\
					srcs/operations_precise.c	\
					srcs/operations_precise2.c	\
					srcs/operations_redir.c		\
					srcs/operations.c			\
					srcs/print.c				\
					srcs/sort_naif_utils.c		\
					srcs/scan_input.c 			\
					srcs/sort_stack_2.c			\
					srcs/sort_stack_under_3.c	\
					srcs/utils.c

SRCS_CHECKER	=	srcs/main_checker.c			\
					$(SRCS_COMMON)


SRCS_PUSH_SWAP	=	srcs/divide_stack.c			\
					srcs/main_push_swap.c		\
					srcs/sort_naif.c			\
					srcs/sort_quick.c			\
					$(SRCS_COMMON)

OBJS_CHECKER	=	$(SRCS_CHECKER:.c=.o)
OBJS_PUSH_SWAP	=	$(SRCS_PUSH_SWAP:.c=.o)
INCL			=	includes/
HEADER			=	$(INCL)$(NAME).h

LIBFT			=	libft.a
LIBFTDIR		=	libft/
LIBFTLINK		=	-L $(LIBFTDIR) -lft


########################### PROGRAM
all:		checker $(NAME)

$(NAME):	complib $(OBJS_PUSH_SWAP)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS_PUSH_SWAP) $(LIBFTLINK)

checker:	complib $(OBJS_CHECKER)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS_CHECKER) $(LIBFTLINK)

########################### LIBS
complib:
	$(MAKE) -C $(LIBFTDIR)

########################### OBJECTS
%.o:		%.c $(HEADER)
	$(CC) -c $(CFLAGS) $(LDFLAGS) -I $(INCL) -o $@ $<
	@# printf "$(GREEN)██"

########################### CLEAN
clean:
	$(MAKE) -C $(LIBFTDIR) clean
	rm -f $(OBJS_PUSH_SWAP) $(OBJS_CHECKER)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -f $(OBJS_PUSH_SWAP) $(OBJS_CHECKER)
	rm -f $(NAME) checker a.out

re:			fclean all
.PHONY:		all re clean fclean
# .SILENT:


########################### COLORS
#----------------reset----------------#
NC = \033[0m
#-----------Regular Colors------------#
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[32m
YELLOW = \033[33;33m
BLUE = \033[0;34m
PURPLE = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[0;37m

########################### ECHO
echoCompil:
	echo "$(YELLOW)Compiling $(RED)$(NAME)$(NC)"
echoCompil2:
	echo "$(YELLOW)Compiling $(RED)checker$(NC)"
echoOK:
	echo "$(GREEN) OK$(NC)"
echoSuccess :
	echo "$(GREEN)===> Compilation Success$(NC)\n"
echoCLEAN :
	echo "$(PURPLE)Cleanning OBJS$(NC)\n"
echoFCLEAN :
	echo "$(PURPLE)Cleanning Exec & Lib$(NC)\n"

########################### TEST

ARG= -3 -8 7 4 2 1 9 6 3 45 78 96 36 25 58 12

test:			checker $(NAME)
	./$(NAME) $(ARG); ./$(NAME) $(ARG) | wc -l; ./$(NAME) $(ARG) | ./checker $(ARG)

test_push_swap:	checker $(NAME)
	./$(NAME) $(ARG)

test_checker:	checker
	./$< $(ARG)

