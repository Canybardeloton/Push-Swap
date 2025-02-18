# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 10:25:55 by agiliber          #+#    #+#              #
#    Updated: 2024/08/27 16:51:19 by agiliber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------------------------------------------------------
# 								HEADER
# ------------------------------------------------------------------------------

NAME_LIB = my_libft.a
NAME = push_swap
HEADER = push_swap.h

# ------------------------------------------------------------------------------
# 								COMPILATION
# ------------------------------------------------------------------------------

CC = cc
CFLAGS = -Wall -Wextra -Werror -I -g3
LIBFT_FLAGS = -L./$(LIB_DIR) -l:my_libft.a

# ------------------------------------------------------------------------------
# 									DIR
# ------------------------------------------------------------------------------

LIB_DIR = My_Libft/
SRC_DIR = src/
OBJ_DIR = obj/

# ------------------------------------------------------------------------------
# 									FILES
# ------------------------------------------------------------------------------

SRC = push_swap.c ft_push_swap_util.c ft_check_input.c ft_input_rules.c \
	ft_free_all.c push.c reverse_rotate.c rotate.c ft_algorythm.c \
	ft_best_move.c ft_command.c ft_execute_operations.c ft_handle_position.c \
	ft_rotation_push_to_a.c ft_fill_list.c swap.c norm.c median_handling.c \
	ft_initiate.c

SRCF = $(addprefix $(SRC_DIR), $(SRC))
OBJ = $(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

DEP = $(OBJ:%.o=%.d)

LIBFT_OBJ = $(addprefix $(LIB_DIR), $(NAME_LIB))

# ------------------------------------------------------------------------------
# 									COMMANDS
# ------------------------------------------------------------------------------

all : $(NAME)

$(NAME) : $(OBJ) | $(LIBFT_OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_FLAGS) -o $@

$(LIBFT_OBJ) :
	make -C $(LIB_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIB_DIR) fclean

re : fclean all

.PHONY : all clean fclean re

-include $(DEP)

# ------------------------------------------------------------------------------------------------------------- >
#
#                 ████████╗███████╗░██████╗████████╗███████╗██╗░░░██╗██████╗░
#                 ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝██╔════╝██║░░░██║██╔══██╗
#                 ░░░██║░░░█████╗░░╚█████╗░░░░██║░░░█████╗░░██║░░░██║██████╔╝
#                 ░░░██║░░░██╔══╝░░░╚═══██╗░░░██║░░░██╔══╝░░██║░░░██║██╔══██╗
#                 ░░░██║░░░███████╗██████╔╝░░░██║░░░███████╗╚██████╔╝██║░░██║
#                 ░░░╚═╝░░░╚══════╝╚═════╝░░░░╚═╝░░░╚══════╝░╚═════╝░╚═╝░░╚═╝

#     COPY PASTE ALL OF THIS SOMEWHERE IN YOUR MAKEFILE
#     MAKE SURE THE NAME OF THE PROJECT IS:
#         $(NAME) = push_swap
#     or else change the value of $(NAMEE)

#     AVAILABLE: (see desccription below)
#     make a
#     make m
#     make n

NAMEE = push_swap
NAMEE_BONUS = push_swap_bonus

MIN = -999
MAX = 999
HOW_MANY = 100
HOW_MUCH = 200

# MAKE A: Run PUSH_SWAP with 'HOW_MANY' random numbers between 'MIN' and 'MAX'
#
a: $(NAMEE)
	@$(call random_shmol_cat, "\'tis push shwap", $(HOW_MANY) number ね?, $(CLS), );
	@ARGS=$$(seq $(MIN) $(MAX) | shuf -n $(HOW_MANY) | tr '\n' ' ' | sed -r 's/ $$//'); \
	echo $$ARGS; \
	./$(word 1, $^) $$ARGS

# MAKE M: Run PUSH_SWAP 'HOW_MUCH' times, output the total move cost
#             prints the return of YOUR main (0 is expeccted for stack sorted, 1 if not)
#
m: $(NAMEE)
	@$(call random_shmol_cat, "\'tis push shwap tesshter、0 is OK、1 is KO", $(HOW_MANY) numbers、$(HOW_MUCH) times ね?, $(CLS), );
	@total=0; \
	for i in $$(seq 1 $(HOW_MUCH)); do \
		ARGS=$$(seq $(MIN) $(MAX) | shuf -n $(HOW_MANY) | tr '\n' ' ' | sed -r 's/ $$//'); \
		output=$$(./$(word 1, $^) $$ARGS); \
		return_code=$$?; \
		count=$$(echo "$$output" | wc -l); \
		echo "test $$i: $$count moves, OK? $$return_code"; \
		if [ $$return_code -eq 1 ]; then \
			echo "pile isnt sorted with these: $$ARGS"; \
			echo "$$ARGS" > bad_output; \
			echo "$$output" >> bad_output; \
		fi; \
		total=$$((total + count)); \
	done; \
	average=$$((total / $(HOW_MUCH))); \
	$(call random_shmol_cat, "heres average numbar:", $$average, , )

BAD_ARGS =  "0 1 2 2a 5" "0 1 2 wtf" "0 1 2 -2147483648 -2147483650" "0 1 2 9999999999 9" "4" "" " "  "-" "i want ..." "0 1-2 8 5" "0 1 2 8 1 5"

# MAKE N: Run a dozen bad arguments, with valgrind
#
n: $(NAMEE)
	@for arg in $(BAD_ARGS); do \
	$(call random_shmol_cat, teshting lots of bad args:, $$arg, $(CLS), ); \
	$(VALGRIIND) ./$(word 1, $^) $$arg; \
	echo "\t\033[5m~ Press Enter to continue...\033[0m"; \
	read -p "" key; \
	done
	$(call random_shmol_cat, this one should work fine:, 1 5 2 7 -3, $(CLS), )
	$(VALGRIIND) ./$(word 1, $^) 1 5 2 7

# ------------------------------------------------------------------------------------------------------------- >
# @$(call random_shmol_cat, text 1, text 2, $(CLS), $(RESET));
# $(1)= $(CLEAR); $(2)= text1; $(3)= text2; $(4)= $(RESET)
define random_shmol_cat
	COLOR=$$(printf "\033[38;5;%dm" $$(shuf -i 1-255 -n 1)); \
	COLOR2=$$(printf "\033[38;5;%dm" $$(shuf -i 0-255 -n 1)); \
	echo "$(3)$${COLOR2}\
	\tにゃ~$${COLOR}\t⠀╱|、\n\
	\t\t(˚ˎ。7⠀⠀⠀$${COLOR2}~ $(1) ~$${COLOR}\n\
	\t\t⠀|、˜\\\\\t\t$${COLOR2}~ $(2)$${COLOR}\n\
	\t\t⠀じしˍ)ノ\n$(4)"
endef

CLS = \033[2J\033[H
# - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - -  - VALGRIIND
VALGRIIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s --track-fds=yes
# ------------------------------------------------------------------------------------------------------------- >
