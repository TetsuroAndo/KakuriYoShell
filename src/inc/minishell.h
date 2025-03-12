/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:40:22 by teando            #+#    #+#             */
/*   Updated: 2025/02/25 19:30:10 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include "core.h"
#include "ms_signal.h"

typedef struct s_shell
{
    char *source_line;
    t_list *token_list;
    t_ast *ast;
    t_list *env_map;
    char *env_spc[128];
    int stdin_backup;
    int stdout_backup;
    char cwd[PATH_MAX];
    t_status status;
} t_shell;

#endif