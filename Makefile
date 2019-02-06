# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/04 18:27:30 by jcorwin           #+#    #+#              #
#    Updated: 2019/02/05 14:16:33 by jcorwin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

SDL_HDR = ~/Library/Frameworks/SDL2.framework/Versions/A/Headers
SDL = ~/Library/Frameworks/

SOURCE_PATH = ./srcs/
SOURCE = *.c
SRC = $(addprefix $(SOURCE_PATH), $(SOURCE))

OBJECTS_PATH = ./objects/
OBJECTS = $(SOURCE:.c=.o)
OBJ = $(addprefix $(OBJECTS_PATH), $(OBJECTS))

INCLUDE_PATH = ./includes/
INCLUDE = rtv1.h
INC = $(addprefix $(INCLUDE_PATH), $(INCLUDE))

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -F $(SDL) -framework SDL2

$(OBJ): $(SRC) $(INC)
	mkdir -p $(OBJECTS_PATH)
	cd $(OBJECTS_PATH) && gcc -c ../$(SRC) -I ../includes/ -I $(SDL_HDR) -F $(SDL)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(OBJECTS_PATH)
	rm -rf $(NAME)

re: fclean all
