# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/25 11:35:04 by verdant           #+#    #+#              #
#    Updated: 2023/01/19 11:42:58 by mwilsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# If on Codam Mac || Intel
## -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
# If on M1 ARM Processor
## -lglfw -L /opt/homebrew/Cellar/glfw/3.3.8/lib/ -pthread -lm

## Marcos ##
NAME			=	FdF
LIBFT			=	libft
SRC_DIR		=	src/
OBJ_DIR		=	obj/
CC				=	gcc
CFLAGS		= -g -I include
HEADERS		=	-I $(LIBMLX)/include -I /System/Volumes/Data/opt/homebrew/Cellar/glfw/3.3.8/include
LIBMLX		=	./lib/MLX42
LIBS			=	$(LIBMLX)/libmlx42.a -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreGraphics
RM			=	rm -rf

## Colors ##

Reset			=	\033[0m
Black			=	\033[30m
Red				=	\033[31m
Green			=	\033[32m
Yellow		=	\033[33m
Blue			=	\033[34m
Magenta		=	\033[35m
Cyan			=	\033[36m
White			=	\033[37m

## Files ##

SRC_FILES	=	fdf_monitor fdf_colors fdf_keys fdf_utils fdf_error fdf_parse fdf_draw fdf

SRC				=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ				=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF			=	test

start:
	@make -C $(LIBMLX)
	@make -C $(LIBFT)
	@cp $(LIBFT)/libft.a .
	@make all

all:	$(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(CLFAGS) $(OBJ) $(LIBS) $(HEADERS) libft.a -o $(NAME)
			@echo "$(Magenta)FdF complied$(Reset)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@$(CC) $(CFLAGS) -c $< $(HEADERS) -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT)
	@make clean -C $(LIBMLX)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)/libft.a
	@$(RM) libft.a
	@find . -name ".DS_Store" -delete
	@echo "$(Red)All libs cleaned$(Reset)"

re: fclean start
	@echo "$(Yellow)Recomplied everything$(Reset)"

.PHONY: start 3all clean fclean re