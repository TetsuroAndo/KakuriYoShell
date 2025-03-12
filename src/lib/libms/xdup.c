/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xdup.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:18:09 by teando            #+#    #+#             */
/*   Updated: 2025/02/25 19:42:32 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

char *xdup(char *str)
{
    char *dup;

    dup = (char *)xmalloc(sizeof(char) * (ft_strlen(str) + 1));
    if (!dup)
        return (NULL);
    ft_memcpy(dup, str, ft_strlen(str));
    dup[ft_strlen(str)] = '\0';
    return (dup);
}

char *xdup2(char *str)
{
    char *dup;

    dup = (char *)xmalloc(sizeof(char) * (ft_strlen(str) + 1));
    if (!dup)
        return (NULL);
    ft_memcpy(dup, str, ft_strlen(str));
    dup[ft_strlen(str)] = '\0';
    return (dup);
}
