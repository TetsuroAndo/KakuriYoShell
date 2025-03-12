/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:49:26 by teando            #+#    #+#             */
/*   Updated: 2025/02/25 19:33:47 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_signal.h"

volatile sig_atomic_t g_signal = 0;

static void sigint_handler(int signum)
{
    if (signum == SIGINT)
    {
        g_signal = SIGINT;
        rl_done = 1;
        rl_replace_line("", 0);
        write(STDOUT_FILENO, "\n", 1);
        rl_on_new_line();
    }
}

static void sigquit_handler(int signum)
{
    if (signum == SIGQUIT)
    {
        g_signal = SIGQUIT;
    }
}

int init_signals(void)
{
    struct sigaction sa_int;
    struct sigaction sa_quit;

    rl_event_hook = (rl_hook_func_t *)rl_noob;
    sa_int.sa_handler = sigint_handler;
    sa_int.sa_flags = SA_RESTART;
    sigemptyset(&sa_int.sa_mask);
    if (sigaction(SIGINT, &sa_int, NULL) == -1)
        return (-1);
    sa_quit.sa_handler = sigquit_handler;
    sa_quit.sa_flags = SA_RESTART;
    sigemptyset(&sa_quit.sa_mask);
    if (sigaction(SIGQUIT, &sa_quit, NULL) == -1)
        return (-1);
    return (0);
}
