# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 17:31:40 by vwildner          #+#    #+#              #
#    Updated: 2022/09/26 21:22:46 by vwildner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FOLDER_NAME = $(shell ls . | grep .c$ | cut -d '_' -f 1 | head -1)
NAME = lib$(FOLDER_NAME).a

SET_COMPILER = $(PWD)/scripts/set_compiler.sh
CC = $(shell $(SET_COMPILER))

SOURCES_PATH = .
SOURCES = $(shell ls . | grep .c$)

OBJECTS_PATH = $(PWD)/objects/$(FOLDER_NAME)
OBJECTS = $(addprefix $(OBJECTS_PATH)/,$(subst .c,.o,$(SOURCES)))

INCLUDES_PATH = $(PWD)/includes

ARCHIVES_PATH = $(PWD)/archives

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
	@$(CC) $(CFLAGS) -I $(INCLUDES_PATH) -o $@ -c $<

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
