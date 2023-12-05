# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 13:20:01 by maiboyer          #+#    #+#              #
#    Updated: 2023/12/04 12:45:14 by maiboyer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define_module = $(addprefix $(1)/, $(2))

BUILD_DIR		=	build
SRC_DIR			=	src
INCLUDE_DIR		=	include
LIBS_DIR		=	.

SRC_FILES		=	

NAME			=	libmestd.a
LIB_NAME		=	
TARGET			=	$(NAME)
CC				=	clang
CFLAGS			=	-Wall -Wextra -Werror -g2 -L$(BUILD_DIR)
BONUS_FILES		=	
LIBS_NAME		=	
SUBJECT_URL		= 

BONUS			=	$(addsuffix .c,$(addprefix $(SRC_DIR)/,$(BONUS_FILES)));
SRC				=	$(addsuffix .c,$(addprefix $(SRC_DIR)/,$(SRC_FILES)))
BONUS_OBJ		=	$(addsuffix .o,$(addprefix $(BUILD_DIR)/,$(BONUS_FILES)))
OBJ				=	$(addsuffix .o,$(addprefix $(BUILD_DIR)/,$(SRC_FILES)))
LIBS			=	$(addprefix $(LIBS_DIR)/,$(LIBS_NAME))
INCLUDES		=	$(addprefix -I,$(INCLUDE_DIR) $(addsuffix /include,$(LIBS)))

COL_GRAY		=	\\e[90m
COL_WHITE		=	\\e[37m
COL_GREEN		=	\\e[32m
COL_BOLD		=	\\e[1m
COL_RESET		=	\\e[0m

.PHONY: all
.PHONY: libs_build
.PHONY: bonus
.PHONY: clean
.PHONY: fclean
.PHONY: re
.PHONY: format
.PHONY: subject
.PHONY: submit
.PHONY: so

all: $(NAME)

get_lib:
	@printf $(LIB_NAME)$(NAME)

$(NAME): $(OBJ) libs_build
	@printf \\n$(COL_GRAY)Building\ Output\ $(COL_WHITE)$(COL_BOLD)%-28s$(COL_RESET)\  \
		$(BUILD_DIR)$(NAME)
	@#cc $(OBJ) libft/libft.a
	@ar rcs $(LIB_NAME)$(NAME) $(OBJ)
	@printf $(COL_GREEN)done$(COL_RESET)\\n

libs_build:
	@- $(foreach LIB,$(LIBS),\
		printf \\n; \
		printf $(COL_GRAY)Building\ library\ $(COL_RESET); \
		printf $(COL_WHITE)$(COL_BOLD)%-25s$(COL_RESET)\\n $(LIB); \
		make LIB_NAME=$(LIB)/ BUILD_DIR=$(realpath $(BUILD_DIR)) -C $(LIB) --no-print-directory all; \
		printf \\n; \
	)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@printf $(COL_GRAY)Building\ $(COL_BOLD)$(COL_WHITE)%-35s\  $(LIB_NAME)$<
	@$(CC) $(CFLAGS) $(WERROR) $(INCLUDES) -c $< -o $@
	@printf $(COL_RESET)$(COL_GREEN)done$(COL_RESET)\\n

clean:
	@- $(foreach LIB,$(LIBS), \
		make clean LIB_NAME=$(LIB)/ BUILD_DIR=$(realpath $(BUILD_DIR)) -C $(LIB) --no-print-directory;\
	)
	@- $(if $(LIB_NAME),,\
		printf $(COL_WHITE)Clearing\ Artefacts\ ; \
		printf $(COL_GRAY)\%-25s$(COL_RESET)\  \($(BUILD_DIR)\); \
		rm -rf $(BUILD_DIR); \
		printf $(COL_GREEN)done$(COL_RESET)\\n; \
	)
	@echo >/dev/null

fclean: clean
	@- $(foreach LIB,$(LIBS), \
		make fclean LIB_NAME=$(LIB)/ BUILD_DIR=$(realpath $(BUILD_DIR)) -C $(LIB) --no-print-directory;\
	)
	@printf $(COL_WHITE)Clearing\ Output\ $(COL_GRAY)%-28s$(COL_RESET)\  \
		\($(LIB_NAME)$(NAME)\)
	@rm -f $(BUILD_DIR)$(NAME)
	@printf $(COL_GREEN)done$(COL_RESET)\\n

re: fclean all

format:
	@c_formatter_42 $(SRC) $(BONUS) $(patsubst %.c,%.h,$(addprefix $(INCLUDE_DIR)/ft/,$(SRC_FILES) $(BONUS_FILES))) | grep -vF "Writing to" || true


subject: subject.txt
	@bat --plain subject.txt

subject.txt:
	@curl $(SUBJECT_URL) | pdftotext -layout -nopgbrk - subject.txt

fuck_raphael:
	@echo "Oui"

submit: format
	@./submit.sh

bonus: $(BONUS_OBJ) $(OBJ)
	@printf \\n$(COL_GRAY)Building\ Output\ $(COL_WHITE)$(COL_BOLD)%-28s$(COL_RESET)\  \
		$(LIB_NAME)$(NAME)
	@ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)
	@printf $(COL_GREEN)done$(COL_RESET)\\n
