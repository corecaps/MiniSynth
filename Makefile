# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 23:32:42 by jgarcia           #+#    #+#              #
#    Updated: 2022/08/23 23:38:51 by jgarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CURRENT_DIR = $(shell pwd)
CC = gcc
CFLAGS = -Wall -Wextra -g -c

PORTAUDIO = lib/libportaudio.a
PORTSF = lib/libportsf.a
LD = -lrt -lm -lasound -ljack -pthread -Lminilibx-linux -lXext -lXext -X11 -lz
INC = -Iinc/ -Iminilibx-linux/
RM = rm -f

SOURCE = main.c
OBJ = $(SRC:.c=.o)
NAME = minisymth

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(PORTAUDIO) $(LD) -o $(NAME)

.o: %.c
	$(CC) $(CFLAGS) $(INC) $< -o $@

clean :
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
.PHONY: clean all
