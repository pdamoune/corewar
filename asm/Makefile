# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/29 21:32:58 by wescande          #+#    #+#              #
#    Updated: 2017/10/24 15:40:46 by tdebarge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	asm

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -fsanitize=address -g
MAIN_FLAGS	=
OBJ_FLAGS	=

LEN_NAME	=	`printf "%s" $(NAME) |wc -c`
DELTA		=	$$(echo "$$(tput cols)-31-$(LEN_NAME)"|bc)

SRC_DIR		=	srcs/
INC_DIR		=	includes/
OBJ_DIR		=	objs/

LIBFT_DIR	=	../libft/
LIBFT_LIB	=	$(LIBFT_DIR)libft.a
LIBFT_INC	=	$(LIBFT_DIR)includes/

LIBS		=

SRC_BASE	=	\
browse_content.c\
browse_counting.c\
comment_done.c\
controller.c\
fonctions/add_instruct.c\
fonctions/aff_instruct.c\
fonctions/and_instruct.c\
fonctions/fork_instruct.c\
fonctions/ld_instruct.c\
fonctions/ldi_instruct.c\
fonctions/lfork_instruct.c\
fonctions/live_instruct.c\
fonctions/lld_instruct.c\
fonctions/lldi_instruct.c\
fonctions/or_instruct.c\
fonctions/st_instruct.c\
fonctions/sti_instruct.c\
fonctions/sub_instruct.c\
fonctions/xor_instruct.c\
fonctions/zjmp_instruct.c\
free.c\
init_struct/init_content.c\
init_struct/init_global.c\
init_struct/init_label.c\
init_struct/init_map.c\
lib_asm/convert_base.c\
lib_asm/convert_hexa.c\
lib_asm/free_strjoin.c\
lib_asm/get_the_argument.c\
lib_asm/go_to_label.c\
lib_asm/is_labelchars.c\
lib_asm/strdup.c\
lib_asm/strisdigit.c\
lib_asm/strlen_tab.c\
lib_asm/strsplit_asm.c\
lib_asm/strsplit_cmt.c\
lib_asm/strsplitspa.c\
lib_asm/strsplitvirg.c\
lib_asm/strstart.c\
lib_asm/strsubc.c\
main.c\
parse_header.c\
parse_label.c

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
NB			=	$(words $(SRC_BASE))
INDEX		=	0

all :
	@make -C $(LIBFT_DIR)
	@make -j $(NAME)

$(NAME):		$(LIBFT_LIB) $(OBJ_DIR) $(OBJS) Makefile
	@$(CC) $(OBJS) -o $(NAME) \
		-I $(INC_DIR) \
		-I $(LIBFT_INC) \
		$(LIBS) $(LIBFT_LIB) $(MAIN_FLAGS) $(FLAGS)
	@printf "\r\033[38;5;117m✓ MAKE $(NAME)\033[0m\033[K\n"

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o :	$(SRC_DIR)%.c Makefile | $(OBJ_DIR)
	@$(eval DONE=$(shell echo $$(($(INDEX)*20/$(NB)))))
	@$(eval PERCENT=$(shell echo $$(($(INDEX)*100/$(NB)))))
	@$(eval TO_DO=$(shell echo $$((20-$(INDEX)*20/$(NB) - 1))))
	@$(eval COLOR=$(shell list=(160 196 202 208 215 221 226 227 190 154 118 82 46); index=$$(($(PERCENT) * $${#list[@]} / 100)); echo "$${list[$$index]}"))
	@printf "\r\033[38;5;%dm⌛ [%s]: %2d%% `printf '█%.0s' {0..$(DONE)}`%*s❙%*.*s\033[0m\033[K" $(COLOR) $(NAME) $(PERCENT) $(TO_DO) "" $(DELTA) $(DELTA) "$(shell echo "$@" | sed 's/^.*\///')"
	@$(CC) $(FLAGS) $(OBJ_FLAGS) -MMD -c $< -o $@\
		-I $(INC_DIR) \
		-I $(LIBFT_INC)
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

clean:			cleanlib
	@if [ -e $(OBJ_DIR) ]; \
	then \
		rm -rf $(OBJ_DIR); \
		printf "\r\033[38;5;202m✗ clean $(NAME).\033[0m\033[K\n"; \
	fi;

fclean:			fcleanlib clean
	@if [ -e $(NAME) ]; \
	then \
		rm -rf $(NAME); \
		printf "\r\033[38;5;196m✗ fclean $(NAME).\033[0m\033[K\n"; \
	fi;

re:				fclean all

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

cleanlib:
	@make -C $(LIBFT_DIR) clean

fcleanlib:
	@make -C $(LIBFT_DIR) fclean

relib:
	@make -C $(LIBFT_DIR) re

.PHONY :		clean fclean re cleanlib fcleanlib relib

-include $(OBJS:.o=.d)
