/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:40:28 by tde-los-          #+#    #+#             */
/*   Updated: 2024/05/28 16:41:03 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

void	ft_free_coods(t_coords **coords, int size)
{
	int	i;

	i = -1;
	if (!size || !coords || !*coords)
		return ;
	while (++i < size)
	{
		if (coords[i])
			free(coords[i]);
	}
	free(coords);
}

void	ft_free_tex(t_tex_coords **coords, int size)
{
	int	i;

	i = -1;
	if (!size || !coords || !*coords)
		return ;
	while (++i < size)
	{
		if (coords[i])
			free(coords[i]);
	}
	free(coords);
}

void	ft_free_face(t_face **face, int size)
{
	int	i;

	i = -1;
	if (!size || !face || !*face)
		return ;
	while (++i < size)
	{
		if (face[i])
			free(face[i]);
	}
	free(face);
}

void	ft_free_obj(t_obj *object)
{
	if (object->dir)
		free(object->dir);
	if (object->fd)
		close(object->fd);
	if (object->file)
		free_tab(object->file);
	ft_free_coods(object->vertices, object->nb_vertex);
	ft_free_coods(object->normals, object->nb_normal);
	ft_free_tex(object->tex_coords, object->nb_tex_coords);
	ft_free_face(object->faces, object->nb_faces);
}