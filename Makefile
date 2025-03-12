# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/22 01:37:23 by teando            #+#    #+#              #
#    Updated: 2025/02/25 19:41:01 by teando           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= minishell
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	LFLAGS		:= -lreadline -L$(shell brew --prefix readline)/lib
	IDFLAGS		+= -I$(shell brew --prefix readline)/include
endif
ifeq ($(UNAME_S),Linux)
	LFLAGS		:= -lreadline
	IDFLAGS		+= -I/usr/include/readline
endif
RM			:= rm -rf
ROOT_DIR	:= .
OUT_DIR		:= $(ROOT_DIR)/obj
INCS_DIR	:= $(ROOT_DIR)/src/inc
LIBFT_DIR	:= $(ROOT_DIR)/src/lib/libft
LIBFT		:= $(LIBFT_DIR)/libft.a
LIBMS_DIR	:= $(ROOT_DIR)/src/lib/libms
LIBMS		:= $(LIBMS_DIR)/libms.a
IDFLAGS		:= -I$(INCS_DIR) -I$(LIBFT_DIR) -I$(LIBMS_DIR)

# モジュール別オブジェクト
OBJS_PARSER = parser/parser.o
OBJS_LEXER  = lexer/lexer.o
OBJS_BUILTINS = builtins/builtins.o
# ... コア用OBJS ...

# =======================
# == Production Build ==
# =======================
NAME = kakuriyo_shell

all: $(NAME)

$(NAME): $(OBJS_PARSER) $(OBJS_LEXER) $(OBJS_BUILTINS)
	$(CC) $(CFLAGS) $(IDFLAGS) -o $(NAME) $^ $(LFLAGS)

# =======================
# == Unit Test Builds ==
# =======================

# Parserのユニットテストを生成する例
test_parser: $(OBJS_PARSER) tests/test_parser.o
	$(CC) $(CFLAGS) -o test_parser $(OBJS_PARSER) tests/test_parser.o

# ほかにも test_lexer, test_builtins ... を追加
test_lexer: $(OBJS_LEXER) tests/test_lexer.o
	$(CC) $(CFLAGS) -o test_lexer $(OBJS_LEXER) tests/test_lexer.o

tests/test_parser.o: tests/test_parser.c parser/parser.h
	$(CC) $(CFLAGS) -c $< -o $@

tests/test_lexer.o: tests/test_lexer.c lexer/lexer.h
	$(CC) $(CFLAGS) -c $< -o $@

# ======================
# == Common Targets  ==
# ======================
clean:
	rm -f parser/*.o lexer/*.o builtins/*.o tests/*.o

fclean: clean
	rm -f $(NAME) test_parser test_lexer

re: fclean all
