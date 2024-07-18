CFLAGS = -Wall -Wextra -Werror -c

SOURCES = linkedlist_utils1.c linkedlist_utils2.c \
	  initialize_linkedlists.c operations.c bucket_sort.c push_swap.c \
	  error_handling.c argument_parsing.c insertion_sort.c ft_split.c argument_parsing2.c

OBJECTS = ${SOURCES:.c=.o}

NAME = push_swap.a


all: ${NAME}

.c.o:
	@clang $(CFLAGS) $< -o ${<:.c=.o}

${NAME}: ${OBJECTS}
	@ar rcs ${NAME} ${OBJECTS}
	@clang -o push_swap push_swap.a

clean:
	@rm -f ${OBJECTS}

fclean: clean
	@rm -f ${NAME}

re: fclean all
