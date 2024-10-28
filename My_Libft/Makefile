# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 11:17:48 by agiliber          #+#    #+#              #
#    Updated: 2024/06/21 10:22:34 by agiliber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------------------------------------------------------
# 								HEADER
# ------------------------------------------------------------------------------

NAME = my_libft.a
HEADER = src/my_libft.h

# ------------------------------------------------------------------------------
# 								COMPILATION
# ------------------------------------------------------------------------------

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(dir $(HEADER))

# ------------------------------------------------------------------------------
# 									DIR
# ------------------------------------------------------------------------------

SRC_DIR = src/
OBJ_DIR = obj/

# ------------------------------------------------------------------------------
# 									FILES
# ------------------------------------------------------------------------------

SRC_LIB = ft_memchr.c ft_strchr.c ft_strrchr.c ft_atoi.c ft_memcmp.c ft_strdup.c \
	ft_strtrim.c ft_bzero.c ft_memcpy.c ft_striteri.c ft_substr.c ft_calloc.c \
	ft_memmove.c ft_strjoin.c ft_tolower.c ft_isascii.c ft_memset.c ft_strlcat.c \
	ft_toupper.c ft_isalnum.c ft_putchar_fd.c ft_strlcpy.c ft_isalpha.c \
	ft_putendl_fd.c ft_strlen.c ft_isdigit.c ft_putnbr_fd.c ft_strmapi.c \
	ft_isprint.c ft_putstr_fd.c ft_strncmp.c ft_itoa.c ft_split.c ft_strnstr.c \
	get_next_line.c ft_printf.c ft_tools.c ft_tools2.c ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \
	ft_lstiter_bonus.c ft_lstmap_bonus.c

SRCF = $(addprefix $(SRC_DIR), $(SRC_LIB))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_LIB:%.c=%.o))

DEP = $(OBJ:%.o=%.d)

# ------------------------------------------------------------------------------
# 									COMMANDS
# ------------------------------------------------------------------------------

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEP)