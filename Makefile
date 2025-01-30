
SRC = src/check_map_2.c \
      src/get_next_line.c \
      src/inite_map.c \
      src/setters.c \
      src/check_map.c \
      src/helper_func.c \
      src/moving.c \
	  so_long.c 

OBJ = $(SRC:.c=.o)

SRC_BONUS = src_bonus/check_map_2_bonus.c \
			src_bonus/check_map_bonus.c \
			src_bonus/get_next_line_bonus.c \
            src_bonus/inite_map_bonus.c \
			src_bonus/setters_bonus.c \
			src_bonus/helper_func_bonus.c \
            src_bonus/moving_bonus.c \
			so_bonus.c \
			src_bonus/setters_bonus_2.c
			
			
OBJ_BONUS = $(SRC_BONUS:.c=.o)
NAME = so_long
NAME_BONUS = so_long_bonus
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror 
LIBFT_DIR = libft
LIBFT = libft/libft.a
MLX = -Lminilibx-linux -lmlx_Linux -lX11 -lXext

GREEN = \033[0;32m
RESET = \033[0m

# run: bonus clean
# 	@clear 
# 	@./so_long_bonus maps/map.ber



all: $(LIBFT) $(NAME)

$(LIBFT):
	@echo "$(GREEN)loading to create libft.a ...$(RESET)"
	@make -C $(LIBFT_DIR) > /dev/null
	@make clean -C $(LIBFT_DIR) > /dev/null

$(NAME): $(OBJ)
	$(CC) $(CFLAGS)  -o $(NAME) $(OBJ) $(MLX) $(LIBFT)

bonus: $(LIBFT) $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS)  -o $(NAME_BONUS) $(OBJ_BONUS) $(MLX) $(LIBFT)

clean:
	@make clean -C $(LIBFT_DIR) > /dev/null
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	@make fclean -C $(LIBFT_DIR) > /dev/null
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all

# Rules
.PHONY: all clean fclean re
