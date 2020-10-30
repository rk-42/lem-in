# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/13 03:19:21 by rakrouna          #+#    #+#              #
#    Updated: 2019/11/17 13:43:25 by rakrouna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INC = -I ./

FLAGS = -Wall -Wextra -Werror

SRCS_NAME = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	   ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	   ft_memcpy.c ft_memmove.c ft_memset.c ft_strcat.c ft_strchr.c \
	   ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlcat.c ft_strlen.c \
	   ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnstr.c ft_strrchr.c \
	   ft_strstr.c ft_tolower.c ft_toupper.c ft_itoa.c ft_memalloc.c \
	   ft_memdel.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
	   ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strclr.c \
	   ft_strdel.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
	   ft_strmap.c ft_strmapi.c ft_strnequ.c ft_strnew.c ft_strsplit.c ft_strsub.c \
	   ft_strtrim.c ft_facteursp.c ft_is_prime.c ft_pgcd.c ft_ppcm.c \
	   ft_sqrt.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c \
	   ft_lstiter.c ft_lstmap.c ft_lstnew.c \
	   ft_convert_base.c ft_print_words_tables.c ft_itoa.c \
	   ft_rech_dichotomique.c ft_sort_integer_table.c \
	   ft_strcapitalize.c ft_strrev.c ft_tri_bulle.c ft_printlst.c ft_strsplitlst.c \
	ft_get_table.c ft_tabcmp.c ft_cpytabat.c ft_strdupplus.c ft_strdupstr.c \
	ft_tablen.c ft_strcountword.c ft_reverse_tab.c ft_putstrendt.c ft_putin.c ft_putendll.c \
	ft_strcount.c ft_putendlll.c ft_strduptab.c ft_strndup.c ft_fstrjoin.c ft_strndup.c ft_abs.c \
pf_putchar.c pf_putstr.c ft_printf.c pf_putnbr.c pf_putunbr.c get_next_line2.c\
		 pf_putaddr.c pf_putnbr_base.c pf_invalid.c ft_scmp.c free_split.c \
	ft_puterr.c exceeds_int.c ft_countchr.c ft_lstnew2.c \
		  pf_putlong_base.c parse_flags.c put_padding.c pf_putfloat.c\
		  pf_strnequ.c parse_colors.c base_utils.c pf_float_padding.c \
		  putfloat_utils.c parse_functions.c ft_dprintf.c


### PATH ###
SRCS_PATH = ./
OBJ_PATH  = obj/

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(SRCS_NAME:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	@gcc -c $(FLAGS) $(INC) $< -o $@
	@echo "\033[34m\033[1mCompilation of \033[0m\033[36m$(notdir $<)\033[1m\033[34m done.\033[0m"

clean:
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\033[31mObjects files \033[1;31m$(OBJS_LIST)\033[1;0m\033[31m removed.\033[0m"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
