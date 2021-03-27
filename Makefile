# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 15:05:09 by hthomas           #+#    #+#              #
#    Updated: 2021/03/27 09:47:20 by hthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

CC				=	clang
CFLAGS			=	-Wall -Werror -Wextra
LDFLAGS			=	#-g3 -fsanitize=address #-fsanitize=leak

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
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS_PUSH_SWAP) $(LIBFTLINK) -D BONUS=0

checker:	complib $(OBJS_CHECKER)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS_CHECKER) $(LIBFTLINK) -D BONUS=0

bonus:		complib $(OBJS_CHECKER) $(NAME)
	$(CC) $(CFLAGS) $(LDFLAGS) -o checker $(OBJS_CHECKER) $(LIBFTLINK) -D BONUS=1

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


########################### TEST

ARG=57 141 253 -v 225 493 105

# ARG= 214 331 495 366 403 41 408 405 483 467 242 179 390 44 401 172 272 377 332 5 155 75 407 279 4 414 212 346 191 169 312 18 246 70 252 319 404 151 294 431 322 40 456 139 45 54 46 349 267 409 290 358 39 73 74 351 124 217 424 389 2 283 30 255 416 420 453 243 326 232 130 284 468 465 82 376 189 271 177 418 97 181 300 237 278 22 192 147 14 165 247 388 383 477 128 281 291 367 455 368 90 429 480 324 202 297 433 266 309 257 486 440 370 159 19 231 71 116 469 80 419 120 23 236 132 335 99 164 56 111 380 195 259 397 34 182 193 112 168 464 89 125 450 15 203 183 260 133 67 186 190 269 371 426 24 496 106 72 288 286 314 448 490 470 473 436 329 140 93 395 316 219 157 141 253 225 493 105 230 494 9 221 425 25 42 170 487 385 318 51 378 447 280 163 396 308 233 13 263 339 136 17 158 200 364 100 398 38 27 65 50 411 391 457 95 355 127 16 304 406 156 35 500 239 361 289 338 84 53 137 302 117 275 497 63 29 340 91 428 235 303 119 445 256 101 306 451 315 254 220 359 109 410 330 8 245 482 1 148 0 104 201 118 432 171 196 103 96 64 499 265 180 238 218 363 138 427 400 43 215 150 305 262 356 317 244 6 36 113 381 122 441 392 357 417 110 492 205 142 333 384 234 160 229 478 12 87 175 295 55 85 471 166 59 185 491 434 210 77 347 327 485 31 261 299 258 115 86 187 94 184 228 437 161 197 49 83 102 226 10 143 479 68 337 343 439 423 26 442 3 62 207 301 328 435 292 413 344 352 323 222 69 438 342 307 107 373 311 135 282 173 325 444 33 422 446 251 121 276 463 79 461 274 213 52 78 372 277 20 458 21 249 108 58 131 293 484 88 28 421 76 354 264 369 248 313 474 341 241 454 402 204 379 123 345 57 415 412 336 152 66 348 285 452 129 334 227 270 273 92 382 188 162 211 476 488 298 462 459 98 174 199 310 287 320 61 350 387 11 47 194 481 489 296 394 206 126 466 460 353 223 224 146 81 37 365 209 176 321 374 393 250 167 208 48 449 145 386 149 240 198 360 60 154 178 430 153 134 399 375 498 32 7 443 144 475 472 268 114 216

test:			checker $(NAME)
	./push_swap $(ARG); ./push_swap $(ARG) | wc -l; ./push_swap $(ARG) | ./checker $(ARG)

test_push_swap:	checker $(NAME)
	./push_swap $(ARG)

test_checker:	checker
	./$< $(ARG)

