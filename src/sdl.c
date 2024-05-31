/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 06:27:48 by tde-los-          #+#    #+#             */
/*   Updated: 2024/05/31 08:25:59 by tde-los-         ###   ########.fr       */
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

	gluPerspective(70.0f, 1.0f * WIDTH / HEIGHT, 1.0f, 100 * 1.0f); // FOV

    gluLookAt(5.0, 5.0, 5.0, // Position de la caméra
            0.0, 0.0, 0.0, // Point que la caméra regarde
            0.0, 1.0, 0.0); // Direction de l'axe
*/

void	draw_object(t_obj *obj)
{
    t_face	*face_list;
    int		i;
    
    face_list = obj->faces->next;
    glEnable(GL_NORMALIZE);
    while (face_list)
    {
        glColor4fv(face_list->color);
        ft_face_draw(face_list->num_vertices);
        i = -1;
        while (++i < face_list->num_vertices)
        {
            if (obj->nb_normal > 0)
                glNormal3fv(obj->glpos->normals[face_list->vertex_normal[i] - 1]);
            if (obj->nb_tex_coords > 0)
                glTexCoord2fv(obj->glpos->textures[face_list->vertex_texture[i] - 1]);
            glVertex3fv(obj->glpos->vertices[face_list->vertex[i] - 1]);
        }
        glEnd();
        face_list = face_list->next;
    }
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
			else
				ft_otherEvent(s_m, s_m->win.event);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		setup_lighting();
		ft_camera(&s_m->cam);
		draw_object(&s_m->object);
		SDL_GL_SwapWindow(s_m->win.window);
		SDL_Delay(10);
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
