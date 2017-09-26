# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wescande <wescande@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/29 21:32:58 by wescande          #+#    #+#              #
#    Updated: 2017/09/19 20:01:38 by wescande         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	corewar

CC			?=	gcc
FLAGS		=	-Wall -Wextra -Werror -O3 -fsanitize=address
MAIN_FLAGS	=
OBJ_FLAGS	=	`pkg-config --cflags gtk+-3.0`

LEN_NAME	=	`echo $(NAME) |wc -c`
DELTA		=	$$(echo "$$(tput cols)-31-$(LEN_NAME)"|bc)

SRC_DIR		=	srcs/
INC_DIR		=	includes/
OBJ_DIR		=	objs/

LIBFT_DIR	=	../libft/
LIBFT_LIB	=	$(LIBFT_DIR)libft.a
LIBFT_INC	=	$(LIBFT_DIR)includes/

LIBS		=	`pkg-config --libs gtk+-3.0`

SRC_BASE	=	\
tools/del_process.c\
tools/usage.c\
tools/remove_all_process.c\
tools/analyze_value.c\
tools/fork_process.c\
tools/move_pc.c\
tools/free_vm.c\
tools/display.c\
tools/add_process.c\
tools/calc_addr.c\
init/init_file.c\
init/init_process_list.c\
init/init_data.c\
init/init_area.c\
init/init_vm_value.c\
init/init_vm_memory.c\
init/init_number.c\
init/init_dump.c\
do_one_cycle.c\
ops/op_sub.c\
ops/op_xor.c\
ops/op_zjmp.c\
ops/op_sti.c\
ops/op_lldi.c\
ops/op_lfork.c\
ops/op_st.c\
ops/op_fork.c\
ops/op_ld.c\
ops/op_lld.c\
ops/op_and.c\
ops/op_live.c\
ops/op_add.c\
ops/op_aff.c\
ops/op_or.c\
ops/op_ldi.c\
main.c\
display/dump.c\
display/display_win.c\
war_end.c\
gtk/px_manage/iter_on_px.c\
gtk/px_manage/erase_px.c\
gtk/px_manage/init_px.c\
gtk/px_manage/calcul_px.c\
gtk/px_manage/draw_px.c\
gtk/px_manage/px_calc_color.c\
gtk/init_gtk_value.c\
gtk/update/update_players.c\
gtk/update/update_process.c\
gtk/update/update_process_info.c\
gtk/pc_manage/init_pc.c\
gtk/pc_manage/erase_pc.c\
gtk/pc_manage/draw_pc.c\
gtk/callbacks/cb_key_event_release.c\
gtk/callbacks/cb_configure_event.c\
gtk/callbacks/cb_reboot.c\
gtk/callbacks/cb_key_event_press.c\
gtk/callbacks/cb_more_info.c\
gtk/callbacks/cb_mouse.c\
gtk/callbacks/cb_speed.c\
gtk/callbacks/cb_play.c\
gtk/callbacks/cb_step.c\
gtk/callbacks/cb_process_box.c\
gtk/callbacks/cb_draw.c\
gtk/callbacks/cb_quit.c\
gtk/cairo/cairo.c\
gtk/do_one_step.c\
gtk/draw/draw_underline.c\
gtk/draw/draw_border.c\
gtk/draw/calcul_border.c\
gtk/create/create_process_info.c\
gtk/create/create_info_win.c\
gtk/create/create_panel.c\
gtk/create/create_gtk.c\
gtk/create/create_players_info.c\
gtk/create/create_menu.c\
gtk/create/create_widget.c\
gtk/init_gtk_memory.c\
check/check_cycle.c\
check/check_arg.c\
check/check_live.c\
area_interface/get_type_from_area.c\
area_interface/get_value_from_area.c\
area_interface/set_value_in_area.c

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
NB			=	$(words $(SRC_BASE))
INDEX		=	0
SHELL		=	/bin/bash

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
