# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 15:05:09 by hthomas           #+#    #+#              #
#    Updated: 2021/03/23 19:24:08 by hthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra
LDFLAGS			=	-g3 -fsanitize=address

SRCS_COMMON		=	srcs/operations.c			\
					srcs/operations_redir.c		\
					srcs/utils.c				\
					srcs/print.c				\
					srcs/scan_input.c

SRCS_CHECKER	=	srcs/main_checker.c			\
					$(SRCS_COMMON)
						

SRCS_PUSH_SWAP	=	srcs/main_push_swap.c		\
					srcs/operations_precise.c	\
					srcs/sort_naif_utils.c		\
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

ARG= 8 -v -3 5

# ARG= 108 489 863 876 239 889 980 72 8 158 874 503 626 929 666 948 171 826 461 619 356 778 527 967 146 306 427 937 538 539 289 777 956 785 60 173 402 314 780 825 551 263 710 494 757 79 105 148 864 986 384 553 810 288 233 349 632 416 603 209 332 162 429 301 624 953 904 32 925 49 488 192 414 474 598 78 612 14 906 528 19 453 616 431 669 775 933 831 747 581 999 462

# ARG= 22 9 152 861 353 703 992 600 646 118 178 542 713 43 321 721 595 435 953 635 660 647 354 72 931 491 847 111 292 498 163 774 448 417 902 991 15 698 138 21 364 142 827 449 724 527 899 691 662 822 802 124 657 211 643 966 617 831 55 1000 257 258 553 628 639 375 666 926 825 425 674 493 133 299 749 652 951 655 239 821 689 393 162 604 469 249 633 115 202 474 71 932 743 569 620 823 50 690 879 362 483 741 948 906 670 980 14 582 909 818 237 35 75 487 407 99 108 640 884 768 836 625 540 919 6 767 181 602 947 747 310 826 222 934 752 835 579 799 531 820 176 709 439 323 974 490 57 38 244 499 218 456 356 203 766 51 287 40 759 887 634 993 196 319 723 347 722 873 27 607 563 334 160 562 558 363 381 422 496 883 93 192 420 432 978 378 615 988 677 764 313 351 614 568 269 583 815 918 143 860 725 227 241 255 169 25 792 653 955 357 270 950 916 277 968 177 979 326 753 131 954 388 872 981 281 370 593 90 92 49 881 679 26 623 735 358 840 97 252 970 528 576 234 930 248 969 23 806 517 462 853 708 141 464 228 941 791 349 880 676 312 851 514 535 1 274 149 949 461 471 424 784 272 262 619 841 289 929 330 925 501 745 327 608 103 575 466 294 126 59 245 411 368 567 543 246 268 44 862 260 849 298 497 123 598 645 433 762 154 903 247 86 644 94 112 890 702 200 771 681 77 130 989 342 166 410 688 42 332 904 427 648 137 668 612 844 217 242 942 986 685 436 460 341 782 803 302 212 682 278 594 737 120 387 773 185 480 266 301 83 4 641 658 158 834 210 564 885 793 81 339 34 280 611 946 696 3 589 374 343 875 70 445 478

test:			checker $(NAME)
	./$(NAME) $(ARG); ./$(NAME) $(ARG) | wc -l; ./$(NAME) $(ARG) | ./checker $(ARG)

test_push_swap:	checker $(NAME)
	./$(NAME) $(ARG)
	
test_checker:	checker
	./$< $(ARG)

