# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/29 21:32:58 by wescande          #+#    #+#              #
#    Updated: 2017/09/12 14:33:32 by tdebarge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	asm

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -fsanitize=address
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
controller.c\
FONCTIONS/add_instruct.c\
FONCTIONS/aff_instruct.c\
FONCTIONS/and_instruct.c\
FONCTIONS/cmd_string.c\
FONCTIONS/comments_string.c\
FONCTIONS/direct_param.c\
FONCTIONS/fork_instruct.c\
FONCTIONS/indirect_param.c\
FONCTIONS/ld_instruct.c\
FONCTIONS/ldi_instruct.c\
FONCTIONS/lfork_instruct.c\
FONCTIONS/live_instruct.c\
FONCTIONS/lld_instruct.c\
FONCTIONS/lldi_instruct.c\
FONCTIONS/or_instruct.c\
FONCTIONS/others_string.c\
FONCTIONS/register_param.c\
FONCTIONS/st_instruct.c\
FONCTIONS/sti_instruct.c\
FONCTIONS/sub_instruct.c\
FONCTIONS/xor_instruct.c\
FONCTIONS/zjmp_instruct.c\
INIT_STRUCT/init_content.c\
INIT_STRUCT/init_global.c\
INIT_STRUCT/init_label.c\
INIT_STRUCT/init_map.c\
LIB_ASM/convert_base.c\
LIB_ASM/convert_hexa.c\
LIB_ASM/free_strjoin.c\
LIB_ASM/free_tab.c\
LIB_ASM/get_the_argument.c\
LIB_ASM/go_to_label.c\
LIB_ASM/is_labelchars.c\
LIB_ASM/print_lines.c\
LIB_ASM/strdup.c\
LIB_ASM/strisdigit.c\
LIB_ASM/strlen_tab.c\
LIB_ASM/strsplit_asm.c\
LIB_ASM/strsplit_cmt.c\
LIB_ASM/strsplitspa.c\
LIB_ASM/strsplitvirg.c\
LIB_ASM/strstart.c\
LIB_ASM/strsubc.c\
LIB_ASM/test_debug/ft_print_words_tables.c\
LIB_ASM/test_debug/test.c\
parse_header.c\
parse_label.c\
read.c\
write.c

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
