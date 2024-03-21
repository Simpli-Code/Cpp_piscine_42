# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 20:50:53 by chruhin           #+#    #+#              #
#    Updated: 2024/03/14 12:47:30 by chruhin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=			phonebook

OBJ_DIR			=			Obj
SRC_DIR			=			src
INC_DIR			=			inc

SRCS			=			$(wildcard $(SRC_DIR)/*.cpp)
OBJS			=			$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
INCS			=			-I $(INC_DIR)

FLAGS			=			-Wall -Wextra -std=c++98 -Werror
CC				=			clang++
RM				=			rm -rf

.PHONY:						clean fclean re all
all:						$(OBJ_DIR) $(NAME)

$(OBJ_DIR):
							@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:				$(SRC_DIR)/%.cpp
							@$(CC) $(FLAGS) $(INCS) -c $< -o $@

$(NAME):					$(OBJS)
							@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
							@printf "${GRN}Compiled successfuly ${RST}\n"

clean:
							@$(RM) $(OBJ_DIR)
							@printf "${RED}"'Deleted Object Files'"${RST}\n"

fclean:						clean
							@$(RM) $(NAME)
							@printf "${RED}"'and the Executable'"${RST}\n"

re:							fclean all

RED				=			\e[1;31m
GRN				=			\e[1;32m
YEL				=			\e[1;33m
RST				=			\e[0m
