/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:43:49 by tde-los-          #+#    #+#             */
/*   Updated: 2024/05/08 16:58:49 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void    ft_free_mlx(t_win *win)
{
    if (win->win)
		mlx_destroy_window(win->mlx, win->win);
	if (win->mlx)
	{
		mlx_destroy_display(win->mlx);
		mlx_loop_end(win->mlx);
	}
    free(win->mlx);
}

void	ft_free_all(t_master *s_m)
{
	ft_free_mlx(&s_m->win);
	free(s_m);
	exit (0);
}