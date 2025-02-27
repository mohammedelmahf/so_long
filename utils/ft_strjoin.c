/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:56:04 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/27 14:58:59 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

char *ft_strjoin(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    char *str;

    if (!s1 || !s2)
        return (NULL);

    str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if (!str)
        return (NULL);

    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        str[i + j] = s2[j];
        j++;
    }

    str[i + j] = '\0';

    // Avoid freeing s1 if it was not dynamically allocated or has been freed before
    if (s1)
        free(s1);

    return (str);
}
