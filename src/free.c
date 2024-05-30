/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:43:49 by tde-los-          #+#    #+#             */
/*   Updated: 2024/05/30 13:48:30 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	if (!tab)
	{
		ft_printf("\n\n\nOH\n\n\n");
		return ;
	}
	while (tab[++i])
	{
		if (tab[i])
			free(tab[i]);
	}
	free(tab);
}

void	ft_free_sdl(t_win *win, t_master *s_m)
{
	if (win->window)
	{
		SDL_DestroyWindow(win->window);
		SDL_Quit();
	}
	(void)s_m;
}

void	ft_free_all(t_master *s_m)
{
	ft_free_sdl(&s_m->win, s_m);
	ft_free_obj(&s_m->object);
	free(s_m);
	exit (0);
}
