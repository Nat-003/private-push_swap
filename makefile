NAME        = push_swap

# Compiler and Flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I -g3

# Source Files
# We list them explicitly to be safe, but include the 'operation' subdirectory

SRCS =		main.c \
			\
			algorithm/complex/radix.c \
			algorithm/complex/radix_utils.c \
			\
			algorithm/medium/medium.c \
			algorithm/medium/medium_utils1.c \
			algorithm/medium/medium_utils2.c \
			\
			algorithm/simple/simple.c \
			\
			operation/push_op.c \
			operation/reverse_rotate_op.c \
			operation/rotate_op.c \
			operation/swap_op.c \
			\
			parser/parser.c \
			parser/parser_utils1.c \
			parser/parser_utils2.c \
			parser/parser_utils3.c \
			\
			selection_and_bench/bench.c \
			selection_and_bench/config.c \
			\
			smal_sort/sm.c \
			smal_sort/sort_five.c \
			smal_sort/sort_three.c \
			\
			utils/disorder.c \
			utils/ft_split.c \
			utils/utils.c


# Object Files
# This replaces the .c extension with .o
OBJS        = $(SRCS:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Standard clean rules
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re