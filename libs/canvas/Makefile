# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 17:23:23 by vwildner          #+#    #+#              #
#    Updated: 2022/08/07 15:36:58 by vwildner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INTERNAL_LIBS = -lft
# EXTERNAL_LIBS = -lm

# --------------------------------------------------------------------------------------------------

FOLDER_NAME = $(shell ls . | grep .c$ | cut -d '_' -f 1 | head -1)
NAME = lib$(FOLDER_NAME).a

CC := $(shell ../../scripts/set_compiler.sh)
CFLAGS = -Wall -Wextra

SOURCES_PATH = .
SOURCES = $(shell ls . | grep .c$)

OBJECTS_PATH = ../../objects/$(FOLDER_NAME)
OBJECTS = $(addprefix $(OBJECTS_PATH)/,$(subst .c,.o,$(SOURCES)))

INCLUDES_PATH = ../../includes

ARCHIVES_PATH = ../../archives

ARCHIVE_SOURCE = $(ARCHIVES_PATH)/$(NAME)

RM = rm -f
SAFE_MKDIR = mkdir -p

all: $(ARCHIVE_SOURCE)

$(ARCHIVE_SOURCE): $(OBJECTS)
	@ar -rcs $(NAME) $(OBJECTS)
	@$(SAFE_MKDIR) $(ARCHIVES_PATH)
	@mv $(NAME) $(ARCHIVES_PATH)

$(OBJECTS_PATH)/%.o: $(SOURCES_PATH)/%.c
	@$(SAFE_MKDIR) $(OBJECTS_PATH)
	@$(CC) $(CFLAGS) -g -I $(INCLUDES_PATH) -o $@ -c $< -L $(ARCHIVES_PATH) $(INTERNAL_LIBS) $(EXTERNAL_LIBS)

clean:
	@$(RM) $(OBJECTS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
