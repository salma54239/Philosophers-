# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/06 02:44:46 by ssaadaou          #+#    #+#              #
#    Updated: 2023/09/08 03:30:28 by ssaadaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
HEADER = philo.h

CC = cc

CFLAGS = -Wall -Wextra -Werror 

RM = rm -rf

SRC = utils.c input.c philo.c routine.c death_note.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS)  $(OBJ) -o $(NAME) 

clean:
	$(RM) $(OBJ) 

fclean: clean
	$(RM) $(NAME) $(CHECKER)

re: fclean all