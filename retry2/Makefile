# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 15:15:53 by yshimoma          #+#    #+#              #
#    Updated: 2023/02/27 12:15:57 by yshimoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_u_putnbr_fd.c ft_16_upper_fd.c ft_16_lower_fd.c\
	ft_16_address_fd.c ft_u_itoa.c ft_16_itoa.c ft_16_address_itoa.c ft_printf_utils.c
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
INCLUDE = include

all: ${NAME}

${NAME}: ${OBJS}
	$(MAKE) -C libft
	cp libft/libft.a ${NAME}
	${AR} ${ARFLAGS} ${NAME} ${OBJS}

.c.o:
	${CC} ${CFLAGS} -I${INCLUDE} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re