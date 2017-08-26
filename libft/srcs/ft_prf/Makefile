# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/17 15:11:18 by pdamoune          #+#    #+#              #
#    Updated: 2017/08/17 16:03:37 by pdamoune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SOURCES	=	ft_prf.c \
			prf_parsing.c \
			prf_conversion.c \
			prf_set_padding.c \
			conversions/prf_type_s.c \
			conversions/prf_type_c.c \
			conversions/prf_type_uc.c \
			conversions/prf_type_us.c \
			conversions/prf_type_d.c \
			conversions/prf_type_u.c \
			conversions/prf_type_x.c \
			conversions/prf_type_b.c \
			conversions/prf_type_o.c \
			functions/prf_set_precision.c \
			functions/prf_fill_c.c \
			functions/prf_fill_data.c \
			functions/prf_fill_wchar.c \
			functions/prf_set_x.c \
			functions/prf_set_prefixe.c \
			functions/prf_lltoa_base.c \
			functions/prf_ulltoa_base.c \
			functions/prf__ulltoa_base.c \
			functions/prf_wctoa.c \
			functions/prf_strlen_wchar.c \
			functions/prf_set_arg.c \
			functions/prf_color.c \
			functions/prf_atoi.c \
			functions/prf_strtoupper.c \
			functions/prf_bzero.c \
			functions/prf_strlen.c \
			functions/prf_toupper.c \
			functions/prf_isblank.c \
			functions/prf_strncmp.c \
			functions/prf_isdigit.c \
			functions/prf_strncpy.c \
			functions/prf_isspace.c \
			functions/prf_strrev.c


CFLAGS	=	-Wall -Wextra -Werror
CC		=	gcc

PATHSRC =	src
PATHINC	=	include
PATHOBJ	=	obj

SRC		=	$(patsubst %,src/%, $(SOURCES))

OBJETS	=	$(patsubst %.c,$(PATHOBJ)/%.o,$(SRC))

all: $(NAME)

$(PATHOBJ)/%.o: %.c
	@mkdir -p $(PATHOBJ)
	@mkdir -p $(PATHOBJ)/$(PATHSRC)
	@mkdir -p $(PATHOBJ)/$(PATHSRC)/conversions
	@mkdir -p $(PATHOBJ)/$(PATHSRC)/functions
	$(CC) $(CFLAGS) -I $(PATHINC) -c $< -o $@

$(NAME): $(OBJETS)
		@ar rc $(NAME) $(OBJETS)
		@ranlib $(NAME)

library:
		@make -C $(PATHLIB)

clean:
		@rm -rf $(PATHOBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: clean, fclean, re, all
