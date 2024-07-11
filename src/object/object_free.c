/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:40:28 by tde-los-          #+#    #+#             */
/*   Updated: 2024/07/11 15:09:36 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	ft_free_coords(t_coords *lst)
{
	t_coords	*current;
	t_coords	*next;

	if (!lst)
		return ;
	current = lst->next;
	while (current != NULL)
	{
		next = current->next;
		if (current)
			free(current);
		current = next;
	}
	if (lst)
		free(lst);
}

void	ft_free_tex(t_tex_coords *lst)
{
	t_tex_coords	*current;
	t_tex_coords	*next;

	if (!lst)
		return ;
	current = lst->next;
	while (current != NULL)
	{
		next = current->next;
		if (current)
			free(current);
		current = next;
	}
	if (lst)
		free(lst);
}

void	ft_free_face(t_face *lst)
{
	t_face	*current;
	t_face	*next;

	if (!lst)
		return ;
	current = lst->next;
	while (current != NULL)
	{
		next = current->next;
		if (current)
			free(current);
		current = next;
	}
	if (lst)
		free(lst);
}

void free_glfloat(GLfloat **vertices, int nb_vertices)
{
	int	i;

	i = -1;
    if (!vertices || nb_vertices <= 0)
        return ;
    while (++i < nb_vertices)
    {
		if (vertices[i])
       		free(vertices[i]);
        vertices[i] = NULL;
    }
	if (vertices)
    	free(vertices);
}

void	ft_free_mtl(t_mtl *mtl)
{
	if (!mtl)
		return ;
	if (!mtl->dir)
	{
		free(mtl);
		return ;
	}
	free(mtl->dir);
	free_tab(mtl->file);
	free(mtl);
}

void	ft_free_obj(t_obj *object)
{
	if (object->dir)
		free(object->dir);
	if (object->fd > 0)
		close(object->fd);
	if (object->file)
		free_tab(object->file);
	object->file = NULL;
	ft_free_mtl(object->mtl);
	ft_free_coords(object->vertices);
	ft_free_coords(object->normals);
	ft_free_tex(object->tex_coords);
	ft_free_face(object->faces);
	if (object->glpos)
	{
		free_glfloat(object->glpos->vertices, object->nb_vertex);
		free_glfloat(object->glpos->normals, object->nb_normal);
		free_glfloat(object->glpos->textures, object->nb_tex_coords);
		free(object->glpos);
	}
}
