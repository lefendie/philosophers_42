# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lefendie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/20 14:29:06 by lefendie          #+#    #+#              #
#    Updated: 2022/03/05 20:45:48 by lefendie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= philo

SRC		:= parser.c parser2.c main.c tools.c loop.c state.c philo.c time.c free.c \
				routine.c loop2.c thread.c

OBJ		:= $(SRC:.c=.o)

%.o: %.c; ${CC} ${CFLAGS} -o $@ -c $<

RM	= /bin/rm -rf

CC	= clang

CFLAGS	= -Wall -Wextra -Werror  -I. -g3

LFLAGS	= -lpthread 

all: ${NAME} 

${NAME}: ${OBJ}
	${CC} ${OBJ} ${LFLAGS} -o ${NAME}

debug: ${OBJ}
	${CC} ${OBJ} ${LFLAGS} -fsanitize=thread -o ${NAME}
clean:
	${RM} ${OBJ}

fclean:	clean
	${RM} ${NAME}

re:	fclean clean all

.PHONY: re clean fclean all debug
