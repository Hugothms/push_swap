# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 15:05:09 by hthomas           #+#    #+#              #
#    Updated: 2021/03/08 15:39:12 by hthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra
LDFLAGS			=	#-g3 -fsanitize=address

SRCS_CHECKER	=	srcs/checker_main.c	\
					srcs/checker.c

SRCS			=	srcs/main.c			\
					srcs/checker.c

OBJS_CHECKER	=	$(SRCS_CHECKER:.c=.o)
OBJS			=	$(SRCS:.c=.o)
INCL			=	includes/
HEADER			=	$(INCL)$(NAME).h

LIBFT			=	libft.a
LIBFTDIR		=	libft/
LIBFTLINK		=	-L $(LIBFTDIR) -lft


########################### PROGRAM
all:		$(NAME)

$(NAME):	complib echoCompil $(OBJS) echoOK echoSuccess
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LIBFTLINK)

checker:	complib echoCompil $(OBJS_CHECKER) echoOK echoSuccess
	$(CC) $(LDFLAGS) -o $@ $(OBJS_CHECKER) $(LIBFTLINK)
########################### LIBS
complib:
	$(MAKE) -C $(LIBFTDIR)

########################### OBJECTS
%.o:		%.c $(HEADER)
	$(CC) -c $(LDFLAGS) -I $(INCL) -o $@ $<
	printf "$(GREEN)██"

########################### CLEAN
clean: echoCLEAN
	$(MAKE) -C $(LIBFTDIR) clean
	rm -f $(OBJS)

fclean: clean echoFCLEAN
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -f $(OBJS)
	rm -f $(NAME) a.out

re:			fclean all
.PHONY:		all re clean fclean
.SILENT:


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
	echo "$(YELLOW)===> Compiling $(RED)$(NAME)$(NC)\n"
echoOK:
	echo "$(GREEN) OK$(NC)\n"
echoSuccess :
	echo "$(GREEN)===> Compilation Success$(NC)\n"
echoCLEAN :
	echo "\n$(PURPLE)===> Cleanning OBJS$(NC)"
echoFCLEAN :
	echo "$(PURPLE)===> Cleanning Exec & Lib$(NC)\n"

########################### TEST
test:		$(NAME)
	./$< 2 4 9 8 5 1 3 6 7

test_checker:	checker
	./$< 2 4 9 8 5 1 3 6 7
