/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:00:57 by tde-los-          #+#    #+#             */
/*   Updated: 2024/05/16 23:06:21 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

/*
    TODO	Faire une fenêtre avec SDL2
	*	Apprendre à regarder les leaks sans voir les erreurs génerés automatiquement via OpenGL
	*	Faire des évènements sur la fenêtre
	*	Mettre un cube via OpenGL sur la fenêtre SDL2 
    TODO	Faire un menu avec un préaffichage des objets à visualiser
    TODO	Créer des objets 3D sur blender
    TODO	Parser les objets
	TODO	Afficher un cube fait sur blender
*/

void	ft_init_window(t_master *s_m)
{
	s_m->win = (t_win){.title = TITLE, .height = HEIGHT, .width = WIDTH};
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
    	ft_printf("%s%s%s", C_RED, E_SDL_INIT, C_NONE);
		ft_free_all(s_m);
	}
	s_m->win.window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
	if (!s_m->win.window) 
	{
    	ft_printf("%s%s%s", C_RED, E_WIN, C_NONE);
		ft_free_all(s_m);
	}
}

void	drawSquare()
{
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();
}

void	ft_sdl_loop(t_master *s_m)
{
    SDL_GLContext context = SDL_GL_CreateContext(s_m->win.window);

    bool quit = false;
    while (!quit) 
	{
        SDL_Event event;
        while (SDL_PollEvent(&event)) 
            if (event.type == SDL_QUIT) 
                quit = true;

        glClear(GL_COLOR_BUFFER_BIT);
        drawSquare();
        SDL_GL_SwapWindow(s_m->win.window);
    }
    SDL_GL_DeleteContext(context);
}

int	main(void)
{
    t_master	*s_m;

    s_m = ft_calloc(1, sizeof(t_master));
    if (!s_m)
		 return (ft_printf("%s%s%s\n", C_RED, E_ALLOC, C_NONE));
	ft_init_window(s_m);
	init_font(&s_m->font);
	ft_sdl_loop(s_m);
    ft_free_all(s_m);
    return (0);
}

// ft_test((t_win){.height = 5});
