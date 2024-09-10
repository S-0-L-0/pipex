# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edforte <edforte@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/26 20:26:02 by edforte           #+#    #+#              #
#    Updated: 2024/09/10 16:53:42 by edforte          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CFILES = \
			pipex.c \
			pipex2.c \
			ft_spit.c \
			pipex_utils.c \
			libft_functs.c \
			ft_printf/ft_printf.c \
			ft_printf/ft_putnbr.c \
			ft_printf/ft_putstr.c \
			ft_printf/ft_putchar.c \

OBJ = $(CFILES:.c=.o)


CC = @ gcc
FLAGS = -g -Wall -Wextra -Werror
RM = rm -rf


name : $(NAME)

all : $(NAME)

$(NAME) : $(OBJ)
	 $(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean :
	@ $(RM) $(OBJ)

fclean : clean
	@ $(RM) $(NAME)

re : fclean all
