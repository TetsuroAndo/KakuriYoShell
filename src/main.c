/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:43:46 by teando            #+#    #+#             */
/*   Updated: 2025/02/25 13:17:09 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void print_ascii_art(void);

int main(int argc, char **argv, char **envp)
{
    t_info *info;

    (void)argc;
    (void)argv;
    if (init_signals())
        return (ft_dprintf(2, "signal setup failure\n"), 1);
    info = system_init(envp);
    // alias_update(RCFILE, info);
    print_ascii_art();
    shell_loop(info);
    system_exit(info, info->status);
}
