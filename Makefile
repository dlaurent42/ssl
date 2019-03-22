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
				sha256/sha256.c												\
				sha256/crypter.c											\
				sha256/utils.c											\
				misc/dispatcher/dispatcher.c								\
				misc/display/display.c										\
				misc/errors/errors.c										\
				misc/memory/free.c											\
				misc/memory/malloc_arg.c									\
				misc/memory/malloc_ssl.c									\
				misc/parser/parser.c										\
				misc/parser/read_file.c										\
				misc/parser/read_stdin.c									\
				misc/utils/left_rotate.c									\
				misc/utils/print_memory.c									\
				misc/utils/reverse_bits.c									\
				misc/utils/strlenu.c										\
				misc/utils/strnjoins.c										\
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
				@mkdir -p $(OBJ_DIR)/sha256
				@mkdir -p $(OBJ_DIR)/misc
				@mkdir -p $(OBJ_DIR)/misc/dispatcher
				@mkdir -p $(OBJ_DIR)/misc/display
				@mkdir -p $(OBJ_DIR)/misc/errors
				@mkdir -p $(OBJ_DIR)/misc/memory
				@mkdir -p $(OBJ_DIR)/misc/parser
				@mkdir -p $(OBJ_DIR)/misc/utils

clean:
				@make clean -C libft/
				@rm -f $(OBJS)
				@rm -rf $(OBJ_DIR)

fclean: 		clean
				@make fclean -C libft/
				@rm -f $(NAME)

re: 			fclean all
