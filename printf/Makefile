NAME ?= printf.a
SOURCES = \
	ft_memcpy.c \
	ft_atoi.c \
	ft_itoa.c \
	ft_uitoa.c \
	ft_strlen.c \
	ft_printf.c \
	ft_print_char.c \
	ft_print_str.c \
	ft_print_int.c \
	ft_print_void.c \
	ft_print_hex.c \
	ft_print_uint.c \
	ft_empty_flag.c

OBJECTS = $(SOURCES:.c=.o)

AR = ar rcs
CC = gcc
CFLAGS ?= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
