/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:43:49 by tde-los-          #+#    #+#             */
/*   Updated: 2024/05/18 07:22:29 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

void	free_tab(void **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	ft_free_obj(t_obj *object)
{
	if (object->file)
		free(object->file);
	if (object->fd)
		close(object->fd);
}

void	ft_free_sdl(t_win *win, t_master *s_m)
{
	if (win->window)
	{
		SDL_DestroyWindow(win->window);
		free_font(&s_m->font);
		SDL_Quit();
	}
}

void	ft_free_all(t_master *s_m)
{
	ft_free_sdl(&s_m->win, s_m);
	ft_free_obj(&s_m->object);
	free(s_m);
	exit (0);
}
