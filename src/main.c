/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:00:57 by tde-los-          #+#    #+#             */
/*   Updated: 2024/05/08 17:41:02 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

int main(void) 
{
    t_master    *s_m;

    s_m = ft_calloc(1, sizeof(t_master));
    if (!s_m)
        return (ft_printf("%s%s%s\n", C_RED, E_ALLOC, C_NONE));
    ft_init_mlx(s_m, &s_m->win);


    for (int y = 0; y <= 300; y++)
    {
        for (int x = 0; x <= 500; x++)
            mlx_pixel_put(s_m->win.mlx, s_m->win.win, x, y, 0xF5EBEE);
    }

    ft_free_all(s_m);
    // mlx_loop(s_m->win.mlx);
    return (0);
}

// ft_free_all(s_m);
// ft_test((t_win){.height = 5});
