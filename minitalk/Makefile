# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xcharley <xcharley@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/30 18:33:53 by xcharley          #+#    #+#              #
#    Updated: 2022/02/16 20:54:47 by xcharley         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME      = 
SERVER    = server
CLIENT    = client
LIBFT     = ./libft/libft.a
LIBFT_DIR = ./libft

CC       = gcc
CFLAGS   = -Wall -Wextra -Werror

SRC_S    = server.c
SRC_C    = client.c

all: $(SERVER) $(CLIENT) 

$(NAME): all 
$(SERVER): $(LIBFT) minitalk.h
	$(CC) $(SRC_S) $(LIBFT) -o $(SERVER)
	@printf "server ready!\n"

$(CLIENT): $(LIBFT) minitalk.h
	$(CC) $(SRC_C) $(LIBFT) -o $(CLIENT)
	@printf "client ready!\n"

$(LIBFT):
	$(MAKE) -C ./libft

.PHONY: clean fclean

clean:
	rm -rf $(CLIENT) $(SERVER)

fclean: 
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf $(CLIENT) $(SERVER)

re: fclean all