# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 19:42:52 by chruhin           #+#    #+#              #
#    Updated: 2024/04/02 20:32:18 by chruhin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=			harlFilter

OBJ_DIR			=			Obj

SRCS			=			Harl.cpp main.cpp
OBJS			=			$(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
DEPS			=			$(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.d))

FLAGS			=			-Wall -Wextra -std=c++98 -MMD -Werror
RM				=			rm -rf
CC				=			c++

.PHONY:						all clean fclean re
all:						$(OBJ_DIR) $(NAME)

$(OBJ_DIR):
							@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:				%.cpp
							@$(CC) $(FLAGS) -c $< -o $@

$(NAME):					$(OBJS)
							@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
							@printf "${GRN}Compiled successfuly $(RST) $(PIN)./$(NAME) ${RST}\n"

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
PIN				=			\e[1;35m
RST				=			\e[0m
