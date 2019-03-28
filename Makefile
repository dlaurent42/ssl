.PHONY: 		all clean fclean re

NAME 		= 	ft_ssl

CC 			=	gcc
CFLAGS		= 	-g3 -Wall -Wextra -Werror -I$(INC_DIR)

SRC_DIR 	=	./src/
SRC			=	ssl.c														\
				md5/md5.c													\
				md5/memory.c												\
				md5/padding.c												\
				md5/process.c												\
				sha224/sha224.c												\
				sha224/memory.c												\
				sha224/padding.c											\
				sha224/process.c											\
				sha256/sha256.c												\
				sha256/memory.c												\
				sha256/padding.c											\
				sha256/process.c											\
				sha384/char_to_uint64.c										\
				sha384/sha384.c												\
				sha384/memory.c												\
				sha384/padding.c											\
				sha384/process.c											\
				sha512/char_to_uint64.c										\
				sha512/sha512.c												\
				sha512/memory.c												\
				sha512/padding.c											\
				sha512/process.c											\
				misc/errors/errors.c										\
				misc/execution/display.c									\
				misc/execution/execution.c									\
				misc/execution/parser.c										\
				misc/execution/read_file.c									\
				misc/execution/read_stdin.c									\
				misc/memory/free.c											\
				misc/memory/malloc.c										\
				misc/memory/reset.c											\
				misc/utils/hex_prepend_zeros.c								\
				misc/utils/print_memory.c									\
				misc/utils/reverse_bits.c									\
				misc/utils/rotate.c											\
				misc/utils/stdin_input_available.c							\
				misc/utils/strnjoinsf1.c

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_ALL))

OBJ_DIR 	=	./obj/
OBJ		 	=	$(SRC:.c=.o)
OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ))

INC_DIR 	=	./include/
INC 		=	ssl.h														\
				constants.h													\
				prototypes.h												\
				structures.h

INCS 		=	$(addprefix $(INC_DIR), $(INC))

all:	 		$(NAME)

$(NAME):		$(OBJ_DIR) $(OBJS)
				@make -C libft/
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L libft/ -lft

$(OBJ_DIR)%.o: 	$(SRC_DIR)%.c $(INCS)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)
				@mkdir -p $(OBJ_DIR)/md5
				@mkdir -p $(OBJ_DIR)/sha224
				@mkdir -p $(OBJ_DIR)/sha256
				@mkdir -p $(OBJ_DIR)/sha384
				@mkdir -p $(OBJ_DIR)/sha512
				@mkdir -p $(OBJ_DIR)/misc
				@mkdir -p $(OBJ_DIR)/misc/errors
				@mkdir -p $(OBJ_DIR)/misc/execution
				@mkdir -p $(OBJ_DIR)/misc/memory
				@mkdir -p $(OBJ_DIR)/misc/utils

clean:
				@make clean -C libft/
				@rm -f $(OBJS)
				@rm -rf $(OBJ_DIR)

fclean: 		clean
				@make fclean -C libft/
				@rm -f $(NAME)

re: 			fclean all
