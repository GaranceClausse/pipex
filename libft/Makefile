# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gclausse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 11:13:42 by gclausse          #+#    #+#              #
#    Updated: 2022/01/10 14:43:31 by gclausse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC= ft_isalpha.c\
     ft_isdigit.c\
     ft_isalnum.c\
     ft_isascii.c\
     ft_isprint.c\
     ft_strlen.c\
     ft_memset.c\
     ft_bzero.c\
     ft_memcpy.c\
     ft_memmove.c\
     ft_strlcpy.c\
     ft_strlcat.c\
     ft_toupper.c\
     ft_tolower.c\
     ft_strchr.c\
     ft_strrchr.c\
     ft_strncmp.c\
     ft_memchr.c\
     ft_memcmp.c\
     ft_strnstr.c\
     ft_atoi.c\
     ft_calloc.c\
     ft_strdup.c\
     ft_substr.c\
     ft_strjoin.c\
     ft_strtrim.c\
     ft_split.c\
     ft_itoa.c\
     ft_strmapi.c\
     ft_striteri.c\
     ft_putchar_fd.c\
     ft_putstr_fd.c\
     ft_putendl_fd.c\
     ft_putnbr_fd.c\
	 ft_lstnew.c\
	 ft_lstadd_front.c\
	 ft_lstsize.c\
	 ft_lstlast.c\
	 ft_lstadd_back.c\
	 ft_lstdelone.c\
	 ft_lstclear.c\
	 ft_lstiter.c\
	 ft_lstmap.c\
	 ft_putnbr_base.c\
	 ft_putnbr_base_unsgn.c\
	 ft_putnbr_usgn_lg.c\
	 ft_printf.c
	
NAME= libft.a

CC= gcc

CFLAGS= -Wall -Werror -Wextra

OBJ= ${SRC:.c=.o}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	ar -rc ${NAME} ${OBJ}

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean fclean all re
