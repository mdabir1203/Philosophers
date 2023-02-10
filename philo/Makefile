# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 03:54:34 by mabbas            #+#    #+#              #
#    Updated: 2023/02/10 09:41:22 by mabbas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG =  philo
# PROG_B  = philo_bonus

SRCS = 	srcs/destroy.c \
		srcs/initialization.c
		srcs/utils.c \
		srcs/routines.c \
		srcs/time_check.c \
		srcs/utils.c \
		srcs/utils_2.c \
		srcs/init_checker.c \
		srcs/destroy.c \
		srcs/philosophers.c

		  
OBJS =  ${SRCS:.c=.o}
MAIN =  srcs/main.c
# SRCS_B	= srcs/pipex_bonus.c srcs/utils.c srcs/utils_bonus.c
# OBJS_B	= ${SRCS_B:.c=.o}
# MAIN_B	= srcs/pipex_bonus.c

HEADER	= -Iincludes
CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror #-g -fsanitize=threads

.c.o: %.o : %.c
	@gcc ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all: ${PROG}

${PROG}:	${OBJS}
	@echo "\033[33m----Compiling Philos---"
	@$(CC) ${OBJS}  -o ${PROG}
					@echo "\033[32mPhilo Compiled! (\033[31m\033[32m_\033[31m\033[32m)\n"


# bonus:		${PROG_B}

# ${PROG_B}:	${OBJS_B}
# 					@echo "\033[33m----Compiling lib----"
# 					@make re -C ./lib/libft
# 					@$(CC) ${OBJS_B} -Llib/libft -lft -o pipex
# 					@echo "\033[32mPipex Bonus Compiled!(\033[31m\033[32m_\033[31m\033[32m)\n"

clean:
	@echo "\n\033[31mTrashing the objects ! ⌐(ಠ۾ಠ)¬\n"
	@rm -f ${OBJS} ${OBJS_B}

fclean: clean
	@rm -f $(NAME)
	@rm -f ${PROG}
	@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n"

re:			fclean all

re_bonus:	fclean bonus

.PHONY: all clean fclean re #re_bonus bonus
