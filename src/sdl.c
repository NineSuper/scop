/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 06:27:48 by tde-los-          #+#    #+#             */
/*   Updated: 2024/05/27 16:44:40 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

/*
	TODO	Créer des objets 3D sur blender
	TODO	Parser les objets
	TODO	Faire une fenêtre avec SDL2
	*	Apprendre à regarder les leaks sans voir les erreurs génerés \
		automatiquement via OpenGL
	*	Faire des évènements sur la fenêtre
	*	Mettre un cube via OpenGL sur la fenêtre SDL2 
	TODO	Afficher un cube fait sur blender
	TODO	Faire un HUD
*/

void	draw_square(void)
{
	glBegin(GL_QUADS);
	glColor3f(1.0f, 2.0f, 1.0f);
	glVertex2f(-2.5f, -0.5f);
	glVertex2f(1.5f, -0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(-0.5f, 0.5f);
	glEnd();
}

void	ft_sdl_loop(t_master *s_m)
{
	s_m->win.context = SDL_GL_CreateContext(s_m->win.window);
	s_m->quit = false;
	while (!s_m->quit)
	{
		while (SDL_PollEvent(&s_m->win.event))
			if (s_m->win.event.type == SDL_QUIT)
				s_m->quit = true;
		glClear(GL_COLOR_BUFFER_BIT);
		draw_square();
		SDL_GL_SwapWindow(s_m->win.window);
	}
	SDL_GL_DeleteContext(s_m->win.context);
}

void	ft_init_window(t_master *s_m)
{
	s_m->win = (t_win){.title = TITLE, .height = HEIGHT, .width = WIDTH};
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		ft_printf("%s%s%s", C_RED, E_SDL_INIT, C_NONE);
		ft_free_all(s_m);
	}
	s_m->win.window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, \
		SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
	if (!s_m->win.window)
	{
		ft_printf("%s%s%s", C_RED, E_WIN, C_NONE);
		ft_free_all(s_m);
	}
}
