/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:37:07 by tde-los-          #+#    #+#             */
/*   Updated: 2024/05/08 17:30:53 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	ft_init_mlx(t_master *s_m, t_win *win)
{
    *win = (t_win){.title = TITLE, .width = WIDTH, .height = HEIGHT};
    win->mlx = mlx_init();
    if (!win->mlx)
    {
        ft_printf("%s%s%s\n", C_RED, E_MLX, C_NONE);
        ft_free_all(s_m);
    }
    win->win = mlx_new_window(win->mlx, win->width, win->height, win->title);
    if (!win->win)
    {
        ft_printf("%s%s%s\n", C_RED, E_WIN, C_NONE);
        ft_free_all(s_m);
    }
}
