# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 19:19:40 by vwildner          #+#    #+#              #
#    Updated: 2022/07/30 20:35:32 by vwildner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt

CC := $(shell ./scripts/set_compiler.sh)
CFLAGS = -Wall -Wextra

EXTERNAL_LIBS = -lm
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
LBFT_NAME = libft.a
LBFT_DIR = $(LIBS_PATH)/libft
LBFT_LIB = $(LBFT_DIR)/$(LBFT_NAME)
LBFT_ARCHIVE = $(ARCHIVES_PATH)/$(LBFT_NAME)

ifeq (run,$(firstword $(MAKECMDGOALS)))
  # use the rest as arguments for "run"
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  # ...and turn them into do-nothing targets
  $(eval $(RUN_ARGS):;@:)
endif


all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER) libft
	@$(CC) $(CFLAGS) \
	-w -g $(OBJECTS) \
	-o $(NAME) \
	-L $(ARCHIVES_PATH) \
	-I $(INCLUDES_PATH) $(INTERNAL_LIBS) $(EXTERNAL_LIBS)

$(OBJECTS_PATH)/%.o: $(SOURCES_PATH)/%.c $(HEADER)
	@$(SAFE_MKDIR) $(OBJECTS_PATH)
	@$(CC) $(CFLAGS) -g -I $(INCLUDES_PATH) -o $@ -c $<

libft: $(LBFT_ARCHIVE)

$(LBFT_ARCHIVE): $(LBFT_LIB)
	@$(SAFE_MKDIR) $(ARCHIVES_PATH)
	@$(COPY) $(LBFT_DIR)/libft.a $(ARCHIVES_PATH)

$(LBFT_LIB):
	@$(MAKE_EXTERNAL) $(LBFT_DIR)

valgrind: $(NAME)
	$(VALGRIND) ./$(NAME) $(RUN_ARGS)

re:	fclean all

archives_clean:
	$(REMOVE) $(ARCHIVES_PATH)

clean:
	$(REMOVE) $(OBJECTS_PATH)
	@$(MAKE) fclean -C $(LBFT_DIR)

fclean: clean archives_clean
	$(REMOVE) $(NAME)
	$(RM) $(ARCHIVES_PATH)/$(LBFT_NAME)

.PHONY: all run valgrind re fclean clean archives_clean libft_clean
