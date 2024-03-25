# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 20:50:53 by chruhin           #+#    #+#              #
#    Updated: 2024/03/25 19:32:21 by chruhin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=			phonebook

INC_DIR			=			inc
OBJ_DIR			=			Obj
SRC_DIR			=			src

SRCS			=			$(wildcard $(SRC_DIR)/*.cpp)
INCS			=			$(addprefix -I, $(INC_DIR))
OBJS			=			$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
DEPS			=			$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.d, $(SRCS))

CC				=			c++
FLAGS			=			-Wall -Wextra -std=c++98 -MMD -Werror
RM				=			rm -rf

.PHONY:						all clean fclean re
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

-include $(DEPS)

RED				=			\e[1;31m
GRN				=			\e[1;32m
RST				=			\e[0m
