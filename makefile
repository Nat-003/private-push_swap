NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

PRINTF_DIR = ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

SRC = main.c \
algorithm/complex/radix.c \
algorithm/complex/radix_utils.c \
algorithm/medium/medium.c \
algorithm/medium/medium_utils1.c \
algorithm/medium/medium_utils2.c \
algorithm/simple/simple.c \
operation/push_op.c \
operation/reverse_rotate_op.c \
operation/rotate_op.c \
operation/swap_op.c \
parser/parser.c \
parser/parser_utils1.c \
parser/parser_utils2.c \
parser/parser_utils3.c \
selection_and_bench/bench.c \
selection_and_bench/config.c \
smal_sort/sm.c \
smal_sort/sort_five.c \
smal_sort/sort_three.c \
utils/disorder.c \
utils/ft_split.c \
utils/utils.c

OBJ = $(SRC:.c=.o)

INCLUDES = -I. -Ift_printf

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) clean -C $(PRINTF_DIR)
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(PRINTF_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re