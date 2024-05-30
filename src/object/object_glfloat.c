/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_glfloat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:28:53 by tde-los-          #+#    #+#             */
/*   Updated: 2024/05/30 19:56:05 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void init_gl_vert(t_coords *ref, GLfloat ***vertices, int nb_vertex)
{
    t_coords *vertices_lst;
    int i;

    i = 0;
    vertices_lst = ref->next;
    if (!vertices_lst)
    {
        ft_printf("%sError: Init GL vertex !lst%s\n", C_RED, C_NONE);
        return;
    }
    *vertices = (GLfloat **)malloc((nb_vertex + 1) * sizeof(GLfloat *));
    if (!(*vertices))
    {
        ft_printf("%s%s%s\n", C_RED, E_ALLOC, C_NONE);
        return;
    }
    while (vertices_lst)
    {
        (*vertices)[i] = (GLfloat *)malloc(3 * sizeof(GLfloat));
        (*vertices)[i][0] = vertices_lst->x;
        (*vertices)[i][1] = vertices_lst->y;
        (*vertices)[i][2] = vertices_lst->z;
        vertices_lst = vertices_lst->next;
        i++;
    }
}

void init_gl_text(t_tex_coords *ref, GLfloat ***texture, int nb_texture)
{
    t_tex_coords *texture_lst;
    int i;

    i = 0;
    texture_lst = ref->next;
    if (!texture_lst)
    {
        ft_printf("%sError: Init GL vertex !lst%s\n", C_RED, C_NONE);
        return;
    }
    *texture = (GLfloat **)malloc((nb_texture + 1) * sizeof(GLfloat *));
    if (!(*texture))
    {
        ft_printf("%s%s%s\n", C_RED, E_ALLOC, C_NONE);
        return;
    }
    while (texture_lst)
    {
        (*texture)[i] = (GLfloat *)malloc(2 * sizeof(GLfloat));
        (*texture)[i][0] = texture_lst->u;
        (*texture)[i][1] = texture_lst->v;
        texture_lst = texture_lst->next;
        i++;
    }
}

void	init_glpos(t_obj *obj)
{
	obj->glpos = (t_glpos *)malloc(sizeof(t_glpos));
	if (!obj->glpos)
	{
		ft_printf("%s%s%s\n", C_RED, E_ALLOC, C_NONE);
		return ;
	}
    if (obj->nb_vertex > 0)
	    init_gl_vert(obj->vertices, &(obj->glpos->vertices), obj->nb_vertex);
    if (obj->nb_tex_coords > 0)
	    init_gl_text(obj->tex_coords, &(obj->glpos->textures), obj->nb_tex_coords);
    if (obj->nb_normal > 0)
	    init_gl_vert(obj->normals, &(obj->glpos->normals), obj->nb_normal);
}
