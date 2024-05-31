/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 08:25:49 by tde-los-          #+#    #+#             */
/*   Updated: 2024/05/31 08:50:26 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

void    ft_key(t_master *s_m, int key)
{
    if (key == SDLK_x)
        s_m->cam.grow_shrink++;
    else if (key == SDLK_z)
        s_m->cam.grow_shrink--;
    else if (key == SDLK_w)
        s_m->cam.tra_x += 0.1f;
    else if (key == SDLK_s)
        s_m->cam.tra_x -= 0.1f;
    else if (key == SDLK_a)
        s_m->cam.tra_z -= 0.1f;
    else if (key == SDLK_d)
        s_m->cam.tra_z += 0.1f;
}

void    ft_mouse_motion(t_master *s_m, int x, int y)
{
    if (s_m->cam.mouseDown)
	{
        s_m->cam.yrot = s_m->cam.xdiff - x;
        s_m->cam.xrot = s_m->cam.ydiff - y;
    }
}

void    ft_mouse_button(t_master *s_m, int button, int state, int x, int y)
{
    if (button == SDL_BUTTON_LEFT)
	{
        if (state == SDL_PRESSED)
		{
            s_m->cam.mouseDown = 1;
            s_m->cam.xdiff = x + s_m->cam.yrot;
            s_m->cam.ydiff = y + s_m->cam.xrot;
        }
		else if (state == SDL_RELEASED)
            s_m->cam.mouseDown = 0;
    }
}

void	ft_otherEvent(t_master *s_m, SDL_Event event)
{
	if (event.type == SDL_KEYDOWN)
		ft_key(s_m, event.key.keysym.sym);
	else if (event.type == SDL_MOUSEMOTION)
		ft_mouse_motion(s_m, event.motion.x, event.motion.y);
	else if (event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP)
		ft_mouse_button(s_m, event.button.button, event.button.state, \
            event.button.x, event.button.y);
}