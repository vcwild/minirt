# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 19:19:40 by vwildner          #+#    #+#              #
#    Updated: 2022/08/04 21:52:55 by vwildner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt

CC := $(shell ./scripts/set_compiler.sh)
CFLAGS = -Wall -Wextra

EXTERNAL_LIBS = -lm -lmlx -lXext -lX11
INTERNAL_LIBS = -lft -ltuple

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

# mlx
MLX = libmlx.a
MLX_PATH = $(LIBS_PATH)/mlx_linux
MLX_ARCHIVE = $(ARCHIVES_PATH)/$(MLX)

# libft
LIBFT = ft
LIBFT_NAME = lib$(LIBFT).a
LIBFT_PATH = $(LIBS_PATH)/$(LIBFT)

# tuple
TUPLE = tuple
TUPLE_NAME = lib$(TUPLE).a
TUPLE_PATH = $(LIBS_PATH)/$(TUPLE)

# canvas
CANVAS = canvas
CANVAS_NAME = lib$(CANVAS).a
CANVAS_PATH = $(LIBS_PATH)/$(CANVAS)

ifeq (run,$(firstword $(MAKECMDGOALS)))
  # use the rest as arguments for "run"
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  # ...and turn them into do-nothing targets
  $(eval $(RUN_ARGS):;@:)
endif

.PHONY: all run valgrind re fclean clean archives_clean \
	libft libft_clean \
	libmlx libmlx_clean \
	libtuple libtuple_clean \
	libcanvas libcanvas_clean

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER) libft libmlx libtuple
	@$(CC) $(CFLAGS) \
	-w -g $(OBJECTS) \
	-o $(NAME) \
	-L $(ARCHIVES_PATH) \
	-I $(INCLUDES_PATH) $(INTERNAL_LIBS) $(EXTERNAL_LIBS)

$(OBJECTS_PATH)/%.o: $(SOURCES_PATH)/%.c $(HEADER)
	@$(SAFE_MKDIR) $(OBJECTS_PATH)
	@$(CC) $(CFLAGS) -g -I $(INCLUDES_PATH) -o $@ -c $<

libft:
	$(MAKE_EXTERNAL) $(LIBFT_PATH)

libft_clean:
	@$(MAKE_EXTERNAL) $(LIBFT_PATH) clean

libmlx:
	@$(MAKE_EXTERNAL) $(MLX_PATH)
	@$(SAFE_MKDIR) $(ARCHIVES_PATH)
	@$(COPY) $(MLX_PATH)/$(MLX) $(ARCHIVES_PATH)

libmlx_clean:
	@$(MAKE_EXTERNAL) $(MLX_PATH) clean
	@$(REMOVE) $(MLX_ARCHIVE)

libtuple:
	@$(MAKE_EXTERNAL) $(TUPLE_PATH)

libtuple_clean:
	@$(MAKE_EXTERNAL) $(TUPLE_PATH) clean

libcanvas: libft
	@$(MAKE_EXTERNAL) $(CANVAS_PATH)

libcanvas_clean:
	@$(MAKE_EXTERNAL) $(CANVAS_PATH) clean

valgrind: $(NAME)
	$(VALGRIND) ./$(NAME) $(RUN_ARGS)

re:	fclean all

archives_clean:
	@$(REMOVE) $(ARCHIVES_PATH)

clean: libft_clean libmlx_clean libtuple_clean libcanvas_clean
	@$(REMOVE) $(OBJECTS_PATH)

fclean: clean archives_clean
	@$(REMOVE) $(NAME)

TEST_SRC += tests/munit/munit.c
TEST_SRC += tests/main.c
TEST_SRC += tests/test_tuples.c

test: libft libtuple libcanvas
	$(CC) -g $(TEST_SRC) -o ./test_bin -L $(ARCHIVES_PATH) -I $(INCLUDES_PATH) -lft -lm -ltuple -lcanvas
	./test_bin # || ./test_bin --no-fork
