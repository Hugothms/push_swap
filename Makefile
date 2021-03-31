# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 15:05:09 by hthomas           #+#    #+#              #
#    Updated: 2021/03/31 18:17:20 by hthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

CC				=	clang
CFLAGS			=	-Wall -Werror -Wextra
LDFLAGS			=	#-g3 -fsanitize=address #-fsanitize=leak

OBJS_CHECKER	=	$(SRCS_CHECKER:.c=.o)
OBJS_PUSH_SWAP	=	$(SRCS_PUSH_SWAP:.c=.o)
INCL			=	includes/
HEADER			=	$(INCL)$(NAME).h

LIBFT			=	libft.a
LIBFTDIR		=	libft/
LIBFTLINK		=	-L $(LIBFTDIR) -lft

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

########################### EXEC
all:		checker $(NAME)

$(NAME):	complib $(OBJS_PUSH_SWAP)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS_PUSH_SWAP) $(LIBFTLINK)

checker:	complib $(OBJS_CHECKER)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS_CHECKER) $(LIBFTLINK)


bonus:		complib $(OBJS_CHECKER) $(OBJS_PUSH_SWAP) compil_bonuses all

########################### LIBARY
complib:
	$(MAKE) -C $(LIBFTDIR)

########################### OBJECTS
%.o:		%.c $(HEADER)
	$(CC) -c $(CFLAGS) $(LDFLAGS) -I $(INCL) -o $@ $<
	@# printf "$(GREEN)██"

compil_bonuses:
	$(CC) -c $(CFLAGS) $(LDFLAGS) -I $(INCL) -o srcs/scan_input.o srcs/scan_input.c -D BONUS

########################### CLEAN
clean:
	$(MAKE) -C $(LIBFTDIR) clean
	rm -f $(OBJS_PUSH_SWAP) $(OBJS_CHECKER)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -f $(OBJS_PUSH_SWAP) $(OBJS_CHECKER)
	rm -f $(NAME) checker a.out

re:			fclean all
.PHONY:		re clean fclean
# .SILENT:

########################### TEST

ARG=3 1 2 9

test:			checker $(NAME)
	./push_swap $(ARG); ./push_swap $(ARG) | wc -l; ./push_swap $(ARG) | ./checker $(ARG)

test_push_swap:	checker $(NAME)
	./push_swap $(ARG)

test_checker:	checker
	./checker $(ARG)

test_bonus:				bonus
	./push_swap $(ARG); ./push_swap $(ARG) | wc -l; ./push_swap $(ARG) | ./checker $(ARG)

test_bonus_push_swap:	bonus
	./push_swap $(ARG)

test_bonus_checker:		bonus
	./checher $(ARG)

test_leaks:		checker $(NAME)
	leaks -atExit -- ./push_swap $(ARG)