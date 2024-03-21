# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 21:45:00 by chruhin           #+#    #+#              #
#    Updated: 2024/03/14 10:12:41 by chruhin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=			megaphone

SRC_DIR			=			src
OBJ_DIR			=			Obj

SRCS			=			$(wildcard $(SRC_DIR)/*.cpp)
OBJS			=			$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

FLAGS			=			-Wall -Wextra -std=c++98 -Werror

CC				=			c++

RM				=			rm -rf

.PHONY:						clean fclean re all

all:						$(OBJ_DIR) $(NAME)

$(OBJ_DIR):
							@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:				$(SRC_DIR)/%.cpp
							@$(CC) $(FLAGS) -c $< -o $@

$(NAME):					$(OBJS)
							@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
							@printf "${GRN}"'Compiled successfuly'"${RST}\n"

clean:
							@$(RM) $(OBJ_DIR)
							@printf "${RED}"'Deleted Object Files'"${RST}\n"

fclean:						clean
							@$(RM) $(NAME)
							@printf "${RED}"'and the Executable File'"${RST}\n"

re:							fclean all

RED				=			\e[1;31m
GRN				=			\e[1;32m
RST				=			\e[0m
