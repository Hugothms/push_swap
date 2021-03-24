# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 15:05:09 by hthomas           #+#    #+#              #
#    Updated: 2021/03/24 14:52:24 by hthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra
LDFLAGS			=	-g3 -fsanitize=address

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

ARG= -v -3 -5


# ARG= 108 489 863 876 239 889 980 72 8 158 874 503 626 929 666 948 171 826 461 619 356 778 527 967 146 306 427 937 538 539 289 777 956 785 60 173 402 314 780 825 551 263 710 494 757 79 105 148 864 986 384 553 810 288 233 349 632 416 603 209 332 162 429 301 624 953 904 32 925 49 488 192 414 474 598 78 612 14 906 528 19 453 616 431 669 775 933 831 747 581 999 462

# ARG= 30 267 882 863 556 429 649 214 275 135 489 23 462 562 701 730 209 519 889 162 212 167 963 119 879 814 705 211 467 846 560 17 549 891 122 200 385 343 656 261 961 347 591 900 112 403 114 438 284 940 729 917 76 240 599 169 291 842 664 389 737 976 72 798 354 173 418 823 461 183 669 964 848 653 919 913 263 716 526 101 94 68 815 975 817 722 756 137 609 785 619 634 587 714 835 289 388 197 42 803 39 65 700 608 509 432 869 166 941 513 511 904 199 557 469 396 635 423 959 313 395 740 654 266 825 18 680 708 503 491 493 566 884 38 583 317 857 277 226 342 833 235 8 217 580 19 236 663 155 907 831 229 325 138 145 736 706 765 329 821 733 98 672 315 597 481 989 237 186 330 422 633 345 532 760 999 908 807 808 763 477 368 966 255 781 995 977 421 476 464 570 47 402 370 473 71 750 780 828 69 474 57 883 838 490 899 168 589 100 158 369 179 741 935 436 677 247 414 525 934 319 893 379 836 673 588 465 106 693 390 358 276 559 415 545 620 637 595 751 911 182 816 24 321 984 205 314 290 552 375 204 331 690 773 598 657 245 704 111 550 184 206 215 871 29 150 504 129 866 417 845 576 645 400 877 451 762 257 392 22 661 958 359 761 692 218 86 980 721 990 592 764 134 147 784 444 51 515 686 749 231 190 225 876 547 442 195 311 326 387 449 524 702 82 960 256 84 488 727 992 969 956 867 834 621 44 687 49 428 348 952 770 20 258 870 829 527 707 837 855 409 805 507 363 254 228 796 970 160 517 824 544 285 157 32 694 720 533 632 316 216 83 819 483 21 806 574 676 563 296 2 896 658 782 196 0 854 496 873 26 905 604 99 728 993 11 13 924 856 843 453 735 107 322 479 923 754 539 922 841 852

test:			checker $(NAME)
	./$(NAME) $(ARG); ./$(NAME) $(ARG) | wc -l; ./$(NAME) $(ARG) | ./checker $(ARG)

test_push_swap:	checker $(NAME)
	./$(NAME) $(ARG)
	
test_checker:	checker
	./$< $(ARG)

