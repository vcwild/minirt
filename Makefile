# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 19:19:40 by vwildner          #+#    #+#              #
#    Updated: 2022/07/30 21:13:17 by vwildner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt

CC := $(shell ./scripts/set_compiler.sh)
CFLAGS = -Wall -Wextra

EXTERNAL_LIBS = -lm -lmlx -lXext -lX11
INTERNAL_LIBS = -lft

VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -q --tool=memcheck

SAFE_MKDIR = mkdir -p

COPY = cp -p

REMOVE = rm -rf

OBJECTS_PATH = ./objects
SOURCES_PATH = ./sources
INCLUDES_PATH = ./includes
LIBS_PATH = ./libs
ARCHIVES_PATH = ./archives

HEADER_FILE = $(NAME).h
HEADER = $(addprefix $(INCLUDES_PATH)/,$(HEADER_FILE))

SOURCE_FILES =	main.c

SOURCES = $(addprefix $(SOURCES_PATH)/,$(SOURCE_FILES))

OBJECTS = $(addprefix $(OBJECTS_PATH)/,$(subst .c,.o,$(SOURCE_FILES)))

MAKE_EXTERNAL = make -C

# libft
LIBFT_NAME = libft.a
LIBFT_PATH = $(LIBS_PATH)/libft
LIBFT_LIB = $(LIBFT_PATH)/$(LIBFT_NAME)
LIBFT_ARCHIVE = $(ARCHIVES_PATH)/$(LIBFT_NAME)

# mlx
MLX = libmlx.a
MLX_PATH = $(LIBS_PATH)/mlx_linux
MLX_ARCHIVE = $(ARCHIVES_PATH)/$(MLX)

ifeq (run,$(firstword $(MAKECMDGOALS)))
  # use the rest as arguments for "run"
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  # ...and turn them into do-nothing targets
  $(eval $(RUN_ARGS):;@:)
endif

.PHONY: all run valgrind re fclean clean archives_clean libft libft_clean libmlx libmlx_clean

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER) libft libmlx
	@$(CC) $(CFLAGS) \
	-w -g $(OBJECTS) \
	-o $(NAME) \
	-L $(ARCHIVES_PATH) \
	-I $(INCLUDES_PATH) $(INTERNAL_LIBS) $(EXTERNAL_LIBS)

$(OBJECTS_PATH)/%.o: $(SOURCES_PATH)/%.c $(HEADER)
	@$(SAFE_MKDIR) $(OBJECTS_PATH)
	@$(CC) $(CFLAGS) -g -I $(INCLUDES_PATH) -o $@ -c $<

libft: $(LIBFT_ARCHIVE)

$(LIBFT_ARCHIVE): $(LIBFT_LIB)
	@$(SAFE_MKDIR) $(ARCHIVES_PATH)
	@$(COPY) $(LIBFT_PATH)/libft.a $(ARCHIVES_PATH)

$(LIBFT_LIB):
	@$(MAKE_EXTERNAL) $(LIBFT_PATH)

libmlx:
	@$(MAKE_EXTERNAL) $(MLX_PATH)
	@$(SAFE_MKDIR) $(ARCHIVES_PATH)
	@$(COPY) $(MLX_PATH)/$(MLX) $(ARCHIVES_PATH)

libmlx_clean:
	@$(MAKE_EXTERNAL) $(MLX_PATH) clean
	@$(REMOVE) $(MLX_ARCHIVE)

libft_clean:
	@$(MAKE_EXTERNAL) $(LIBFT_PATH) clean
	@$(REMOVE) $(LIBFT_ARCHIVE)

valgrind: $(NAME)
	$(VALGRIND) ./$(NAME) $(RUN_ARGS)

re:	fclean all

archives_clean:
	@$(REMOVE) $(ARCHIVES_PATH)

clean:
	@$(REMOVE) $(OBJECTS_PATH)

fclean: clean archives_clean libft_clean libmlx_clean
	@$(REMOVE) $(NAME)
