/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:11:11 by teando            #+#    #+#             */
/*   Updated: 2025/02/25 19:29:53 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_STRUCTS_H
#define MS_STRUCTS_H

#include "libft.h"
#include <limits.h>

typedef enum e_status
{
    E_NONE = 0,
    E_ALLOCATE = 1,
    E_ENV_KEY = 1,
    E_SYNTAX = 1,
    E_PIPE = 1,
    E_FILE,
    E_ARGUMENT,
    E_NOT_BUITIN_CMD = -2,
    E_COMMAND_NOT_FOUND = 127,
    E_SIGINT = 130,
    E_SIGQUIT = 131,
} t_status;

typedef struct s_lexical_token
{
    t_token_type type;
    char *value;
} t_lexical_token;

typedef enum e_token_category
{
    CMD_ARG = 0x1000,
    CONNECT = 0x2000,
    REDIRECT = 0x1200,
    PAREN = 0x500,
    ERROR = 0x000
} t_token_category;

typedef enum e_token_type
{
    /* Command and Arguments */
    TT_WORD = 0x1101,

    /* Pipe */
    TT_PIPE = 0x302,

    /* Redirections */
    TT_REDIR_IN = 0x1201,
    TT_APPEND = 0x1202,
    TT_REDIR_OUT = 0x1203,
    TT_HEREDOC = 0x1204,

    /* Parentheses */
    TT_LPAREN = 0x501,
    TT_RPAREN = 0x502,

    /* Control Operators */
    TT_AND_AND = 0x2001,
    TT_OR_OR = 0x2002,
    TT_SEMICOLON = 0x2003,

    /* Special Tokens */
    TT_EOF = 0x2004,
    TT_ERROR = 0x002
} t_token_type;

typedef enum e_ntype
{
    NT_CMD,
    NT_PIPE,
    NT_EOF,
    NT_AND,
    NT_OR
} t_ntype;

typedef struct s_args
{
    char path[PATH_MAX];
    char **cargv;
    t_list *argv;
    t_list *redr;
    int fds[2];
    pid_t pid;
} t_args;

typedef struct s_ast
{
    struct s_ast *left;
    struct s_ast *right;
    t_ntype ntype;
    t_args *args;
} t_ast;

#endif
