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
LD = -lrt -lm -lasound -ljack -pthread -Lminilibx-linux -lmlx -lXext -lX11 -lz
INC = -Iinc/ -Iminilibx-linux/
RM = rm -f

SOURCE = graphic_render.c audio_render.c main.c
OBJ = $(SOURCE:.c=.o)
NAME = minisynth

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(PORTAUDIO) $(LD) -o $(NAME)

.o: %.c
	$(CC) $(CFLAGS) $(INC) $< -o $@

clean :
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
.PHONY: fclean clean all