# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbie <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 18:33:46 by pbie              #+#    #+#              #
#    Updated: 2016/02/12 16:32:13 by pbie             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = ft_libft/ft_atoi.c \
		ft_libft/ft_buildtab.c \
		ft_libft/ft_bzero.c \
		ft_libft/ft_char_swap.c \
		ft_libft/ft_check_white.c \
		ft_libft/ft_exit.c \
		ft_libft/ft_get_next_line.c \
		ft_libft/ft_includes_char.c \
		ft_libft/ft_isalnum.c \
		ft_libft/ft_isalpha.c \
		ft_libft/ft_isascii.c \
		ft_libft/ft_isdigit.c \
		ft_libft/ft_isprint.c \
		ft_libft/ft_itoa.c \
		ft_libft/ft_memalloc.c \
		ft_libft/ft_memccpy.c \
		ft_libft/ft_memchr.c \
		ft_libft/ft_memcmp.c \
		ft_libft/ft_memcpy.c \
		ft_libft/ft_memdel.c \
		ft_libft/ft_memmove.c \
		ft_libft/ft_memset.c \
		ft_libft/ft_non_white.c \
		ft_libft/ft_putchar.c \
		ft_libft/ft_putchar_fd.c \
		ft_libft/ft_putendl.c \
		ft_libft/ft_putendlnbr.c \
		ft_libft/ft_putendl_fd.c \
		ft_libft/ft_putnbr.c \
		ft_libft/ft_putnbr_fd.c \
		ft_libft/ft_putstr.c \
		ft_libft/ft_putstr_fd.c \
		ft_libft/ft_strcat.c \
		ft_libft/ft_strchr.c \
		ft_libft/ft_strclr.c \
		ft_libft/ft_strcmp.c \
		ft_libft/ft_strcpy.c \
		ft_libft/ft_strdel.c \
		ft_libft/ft_strdup.c \
		ft_libft/ft_strequ.c \
		ft_libft/ft_striter.c \
		ft_libft/ft_striteri.c \
		ft_libft/ft_strjoin.c \
		ft_libft/ft_strnjoin.c \
		ft_libft/ft_strlcat.c \
		ft_libft/ft_strlen.c \
		ft_libft/ft_strmap.c \
		ft_libft/ft_strmapi.c \
		ft_libft/ft_strncat.c \
		ft_libft/ft_strncmp.c \
		ft_libft/ft_strncpy.c \
		ft_libft/ft_strnequ.c \
		ft_libft/ft_strnew.c \
		ft_libft/ft_strnstr.c \
		ft_libft/ft_strrchr.c \
		ft_libft/ft_strsplit.c \
		ft_libft/ft_strstr.c \
		ft_libft/ft_strsub.c \
		ft_libft/ft_strtrim.c \
		ft_libft/ft_tolower.c \
		ft_libft/ft_toupper.c \
		ft_libft/ft_lstadd.c \
		ft_libft/ft_lstdel.c \
		ft_libft/ft_lstdelone.c \
		ft_libft/ft_lstiter.c \
		ft_libft/ft_lstnew.c \
		ft_libft/ft_lstmap.c \
		ft_libft/ft_lstaddend.c \
		ft_libft/ft_islower.c \
		ft_libft/ft_isupper.c \
		ft_libft/ft_swap.c \
		ft_libft/ft_wordcount.c \
		ft_libft/ft_strndup.c \
		ft_libft/ft_putstrtab.c \
		ft_libft/ft_tablen.c \
		ft_printf/ft_printf.c \
		ft_libft/ft_strlower.c \
		ft_libft/ft_strrev.c \
		ft_libft/ft_strupper.c \
		ft_printf/output/utils/ft_ws_strcmp.c \
		ft_printf/output/utils/ft_ws_width.c \
		ft_printf/output/utils/get_int_type.c \
		ft_printf/output/utils/oct_change.c \
		ft_printf/output/utils/oct_malloc.c \
		ft_printf/output/utils/print_hex_long_prefix.c \
		ft_printf/output/utils/print_int_zero_space.c \
		ft_printf/output/utils/print_o_ul.c \
		ft_printf/output/utils/print_plus_byte.c \
		ft_printf/output/utils/print_prefix.c \
		ft_printf/output/utils/print_space_byte.c \
		ft_printf/output/utils/print_x_ul.c \
		ft_printf/output/utils/print_zero_byte.c \
		ft_printf/output/utils/print_zero_space.c \
		ft_printf/output/utils/print_zero_space_ws.c \
		ft_printf/output/utils/unsigned_int_setup.c \
		ft_printf/output/print_address.c \
		ft_printf/output/print_char.c \
		ft_printf/output/print_hex.c \
		ft_printf/output/print_hex_long.c \
		ft_printf/output/print_hex_max.c \
		ft_printf/output/print_identifier.c \
		ft_printf/output/print_int.c \
		ft_printf/output/print_invalid_identifier.c \
		ft_printf/output/print_long.c \
		ft_printf/output/print_oct.c \
		ft_printf/output/print_percentage.c \
		ft_printf/output/print_string.c \
		ft_printf/output/print_unsigned_int.c \
		ft_printf/output/print_wide_string.c \
		ft_printf/output/print_wide.c \
		ft_printf/utils/check_format.c \
		ft_printf/utils/converters/ft_address_to_hex.c \
		ft_printf/utils/converters/ft_dec_to_hex.c \
		ft_printf/utils/converters/ft_dec_to_hex_long.c \
		ft_printf/utils/converters/ft_dec_to_hex_max.c \
		ft_printf/utils/converters/ft_dec_to_oct.c \
		ft_printf/utils/converters/ft_lltoa.c \
		ft_printf/utils/checks/ft_isconversion.c \
		ft_printf/utils/checks/ft_isflag.c \
		ft_printf/utils/checks/ft_islmod.c \
		ft_printf/utils/print_pfi.c \
		ft_printf/utils/lengths/int_length.c \
		ft_printf/utils/lengths/long_length.c \
		ft_printf/handlers/handle_flag.c \
		ft_printf/handlers/handle_identifier.c \
		ft_printf/handlers/handle_field_width.c \
		ft_printf/handlers/handle_precision.c \
		ft_printf/handlers/handle_len_mod.c \
		ft_printf/handlers/handle_conversion.c \
		ft_printf/inits/init_pfi.c \
		ft_printf/inits/free_pfi.c \


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) created"
	@ranlib $(NAME)
	@echo "$(NAME) indexed"

%.o: %.c
	@gcc $(FLAG) -I includes -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re
