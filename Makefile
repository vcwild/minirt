# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 19:19:40 by vwildner          #+#    #+#              #
#    Updated: 2022/09/09 23:59:17 by vwildner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt

SET_COMPILER = $(PWD)/scripts/set_compiler.sh
CC = $(shell $(SET_COMPILER))
CFLAGS = -Wall -Wextra

EXTERNAL_LIBS = -lm -lmlx_Linux -lXext -lX11
INTERNAL_LIBS = -lparser -lcamera -lworld -llight -lray -lmaterial -lmatrix -lcanvas -ltuple -lft

VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -q --tool=memcheck

SAFE_MKDIR = mkdir -p

COPY = cp -p

REMOVE = rm -rf

OBJECTS_PATH = $(PWD)/objects
SOURCES_PATH = $(PWD)/sources
INCLUDES_PATH = $(PWD)/includes
LIBS_PATH = $(PWD)/libs
ARCHIVES_PATH = $(PWD)/archives

HEADER_FILE = $(NAME).h
HEADER = $(addprefix $(INCLUDES_PATH)/,$(HEADER_FILE))

SOURCE_FILES =	$(shell ls ./sources | grep .c$)

SOURCES = $(addprefix $(SOURCES_PATH)/,$(SOURCE_FILES))

OBJECTS = $(addprefix $(OBJECTS_PATH)/,$(subst .c,.o,$(SOURCE_FILES)))

MAKE_EXTERNAL = make -C

# mlx
MLX = libmlx_Linux.a
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

# world
MATRIX = matrix
MATRIX_NAME = lib$(MATRIX).a
MATRIX_PATH = $(LIBS_PATH)/$(MATRIX)

# ray
RAY = ray
RAY_NAME = lib$(RAY).a
RAY_PATH = $(LIBS_PATH)/$(RAY)

# material
MATERIAL = material
MATERIAL_NAME = lib$(MATERIAL).a
MATERIAL_PATH = $(LIBS_PATH)/$(MATERIAL)

# light
LIGHT = light
LIGHT_NAME = lib$(LIGHT).a
LIGHT_PATH = $(LIBS_PATH)/$(LIGHT)

# world
WORLD = world
WORLD_NAME = lib$(WORLD).a
WORLD_PATH = $(LIBS_PATH)/$(WORLD)

# camera
CAMERA = camera
CAMERA_NAME = lib$(CAMERA).a
CAMERA_PATH = $(LIBS_PATH)/$(CAMERA)

# parser
PARSER = parser
PARSER_NAME = lib$(PARSER).a
PARSER_PATH = $(LIBS_PATH)/$(PARSER)

ALL_LIBS = libft libparser libmlx libtuple libcanvas libmatrix libray libmaterial liblight libworld libcamera

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
	libcanvas libcanvas_clean \
	libmatrix libmatrix_clean \
	libray libray_clean \
	libmaterial libmaterial_clean \
	liblight liblight_clean \
	libworld libworld_clean \
	libcamera libcamera_clean

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER) $(ALL_LIBS)
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

libmatrix: libft libcanvas
	@$(MAKE_EXTERNAL) $(MATRIX_PATH)

libmatrix_clean:
	@$(MAKE_EXTERNAL) $(MATRIX_PATH) clean

libray: libmatrix libtuple
	@$(MAKE_EXTERNAL) $(RAY_PATH)

libray_clean:
	@$(MAKE_EXTERNAL) $(RAY_PATH) clean

libmaterial: libray libcanvas
	@$(MAKE_EXTERNAL) $(MATERIAL_PATH)

libmaterial_clean:
	@$(MAKE_EXTERNAL) $(MATERIAL_PATH) clean

liblight: libray
	@$(MAKE_EXTERNAL) $(LIGHT_PATH)

liblight_clean:
	@$(MAKE_EXTERNAL) $(LIGHT_PATH) clean

libworld: liblight
	@$(MAKE_EXTERNAL) $(WORLD_PATH)

libworld_clean:
	@$(MAKE_EXTERNAL) $(WORLD_PATH) clean

libcamera: libworld
	@$(MAKE_EXTERNAL) $(CAMERA_PATH)

libcamera_clean:
	@$(MAKE_EXTERNAL) $(CAMERA_PATH) clean

libparser: libworld libcanvas
	@$(MAKE_EXTERNAL) $(PARSER_PATH)

libparser_clean:
	@$(MAKE_EXTERNAL) $(PARSER_PATH) clean

valgrind: $(NAME)
	$(VALGRIND) ./$(NAME) $(RUN_ARGS)

re:	fclean all

clean: libft_clean libmlx_clean libtuple_clean libcanvas_clean libmatrix_clean libray_clean libmaterial_clean liblight_clean libworld_clean
	@$(REMOVE) $(OBJECTS_PATH)

archives_clean:
	@$(REMOVE) $(ARCHIVES_PATH)

fclean: clean archives_clean
	@$(REMOVE) $(NAME)

TEST_SRC += tests/munit/munit.c
TEST_SRC += tests/main.c
TEST_SRC += tests/test_tuples.c
TEST_SRC += tests/test_matrix.c
TEST_SRC += tests/test_canvas.c
TEST_SRC += tests/test_matrix_transform.c
TEST_SRC += tests/test_ray.c
TEST_SRC += tests/test_sphere.c
TEST_SRC += tests/test_materials.c
TEST_SRC += tests/test_world.c
TEST_SRC += tests/test_camera.c
TEST_SRC += tests/test_shapes.c
TEST_SRC += tests/test_planes.c
TEST_SRC += tests/test_cylinders.c

test: re $(ALL_LIBS)
	$(CC) -w -g $(TEST_SRC) -L$(ARCHIVES_PATH) -I$(INCLUDES_PATH) -o ./test_bin $(INTERNAL_LIBS) -lm
	./test_bin # || ./test_bin --no-fork
