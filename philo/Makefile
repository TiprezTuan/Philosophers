# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 17:58:06 by ttiprez           #+#    #+#              #
#    Updated: 2026/01/21 17:05:08 by ttiprez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Regles Makefile
MAKEFLAGS += -s

# Compilateur et flags
CC			= cc
CFLAGS		= -Wall -Wextra -g -I$(HEADERS_DIR)

# Nom de l'executable
NAME		= philo

# Dossiers
SRC_DIR		= src
OBJ_DIR		= obj
HEADERS_DIR	= include

# Fichiers sources
SRCS		= $(SRC_DIR)/error_management.c		\
			  $(SRC_DIR)/philo_actions.c		 \
			  $(SRC_DIR)/hypervisor.c			  \
			  $(SRC_DIR)/philo.c				   \
			  $(SRC_DIR)/utils.c				    \
			  $(SRC_DIR)/main.c					     \
			  $(SRC_DIR)/fork.c

# Ficher objets
OBJS		= $(OBJ_DIR)/fork.o					      \
			  $(OBJ_DIR)/main.o					     \
			  $(OBJ_DIR)/utils.o				    \
			  $(OBJ_DIR)/philo.o				   \
			  $(OBJ_DIR)/hypervisor.o			  \
			  $(OBJ_DIR)/philo_actions.o		 \
			  $(OBJ_DIR)/error_management.o

# Couleur
RED			= \033[0;31m
GREEN		= \033[0;32m
CYAN		= \033[0;36m
RESET		= \033[0m

# Regles
all: $(NAME)

# Creer les dossiers objets
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compiler les fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Creer l'executable
$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) && echo "$(GREEN)[OK] Compilation réussie, exécutable créé$(RESET)" || (echo "$(RED)[FAIL] Compilation échouée$(RESET)"; exit 1)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(CYAN)Fichiers objets supprimés$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(CYAN)Exécutable supprimé$(RESET)"

re: fclean all

.PHONY: all clean fclean re