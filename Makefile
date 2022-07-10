# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teevee <teevee@students.21-school.ru>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/28 19:12:10 by teevee            #+#    #+#              #
#    Updated: 2020/10/28 19:20:57 by teevee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = srcs/main.c srcs/libft/get_next_line.c srcs/libft/get_next_line_utils.c \
		srcs/libft/ft_calloc.c srcs/libft/ft_lstadd_back.c \
		srcs/libft/ft_lstadd_front.c srcs/libft/ft_lstclear.c \
		srcs/libft/ft_lstdelone.c srcs/libft/ft_lstiter.c \
		srcs/libft/ft_lstlast.c srcs/libft/ft_lstmap.c \
		srcs/libft/ft_lstnew.c srcs/libft/ft_lstsize.c \
		srcs/libft/ft_strjoin.c srcs/libft/ft_bzero.c srcs/libft/ft_strlen.c \
		srcs/libft/ft_putchar.c srcs/libft/ft_isdigit.c \
		srcs/libft/ft_atoi.c srcs/ft_init.c srcs/error.c  srcs/raycast.c \
		srcs/libft/ft_strdup.c srcs/screenshot.c srcs/libft/ft_putstr_fd.c \
		srcs/init.c srcs/init_utils.c srcs/valid_param.c \
		srcs/libft/ft_strncmp.c srcs/keys.c srcs/keys_utils.c srcs/valid_map.c \
		srcs/raycast_utils.c srcs/sprite.c srcs/ft_free.c srcs/libft/ft_memset.c

OBJ = $(SRCS:.c=.o)

INCLUDE = srcs/cub3d.h srcs/libft/libft.h

MLX = libmlx.dylib

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C ./minilibx_mms
	@mv ./minilibx_mms/$(MLX) . && rm -f ./minilibx_mms/$(MLX)
	@gcc $(FLAG) $(SRCS) -L. -lmlx -lm -framework OpenGL -framework AppKit -o $(NAME)

$(OBJ): %.o: %.c
	gcc $(FLAG) -c $< -o $@
	
clean:
	@$(MAKE) -C ./minilibx_mms clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(MLX)
	@/bin/rm -f $(NAME)
	@/bin/rm -f screenshot.bmp 

re: fclean all

.PHONY: all clean fclean re test