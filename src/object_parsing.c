/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:13:03 by tde-los-          #+#    #+#             */
/*   Updated: 2024/05/28 16:45:29 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

void	ft_scanf_vertices(char *str, t_coords **vertices, int size)
{
	vertices = realloc(vertices, sizeof(t_coords *) * size);
	vertices[size - 1] = malloc(sizeof(t_coords));
	sscanf(str, "v %f %f %f", &vertices[size - 1]->x, \
		&vertices[size - 1]->y, &vertices[size - 1]->z);
}

void	ft_scanf_normal(char *str, t_coords **normal, int size)
{
	normal = realloc(normal, sizeof(t_coords *) * size);
	normal[size - 1] = malloc(sizeof(t_coords));
	sscanf(str, "vn %f %f %f", &normal[size - 1]->x, \
		&normal[size - 1]->y, &normal[size - 1]->z);
}

void	ft_scanf_face(char *str, t_face **face, int size)
{
	face = realloc(face, sizeof(t_face *) * size);
	face[size - 1] = malloc(sizeof(t_face));
	sscanf(str, "f %u/%u/%u %u/%u/%u %u/%u/%u", \
		&face[size - 1]->vertex[0],
		&face[size - 1]->vertex_texture[0],
		&face[size - 1]->vertex_normal[0],
		&face[size - 1]->vertex[1],
		&face[size - 1]->vertex_texture[1],
		&face[size - 1]->vertex_normal[1],
		&face[size - 1]->vertex[2],
		&face[size - 1]->vertex_texture[2],
		&face[size - 1]->vertex_normal[2]);
}

void	ft_scanf_tex(char *str, t_tex_coords **tex_coords, int size)
{
	tex_coords = realloc(tex_coords, sizeof(t_tex_coords *) * size);
	tex_coords[size - 1] = malloc(sizeof(t_tex_coords));
	sscanf(str, "vt %f %f", &tex_coords[size - 1]->u, &tex_coords[size - 1]->v);
}

void	ft_read_file(t_obj *object)
{
	int	i;

	i = 0;
	while (object->file[++i])
	{
		if (!ft_strncmp(object->file[i], "v ", 2))
			ft_scanf_vertices(object->file[i], object->vertices,
				++object->nb_vertex);
		else if (!ft_strncmp(object->file[i], "vt ", 3))
			ft_scanf_tex(object->file[i], object->tex_coords,
				++object->nb_tex_coords);
		else if (!ft_strncmp(object->file[i], "vn ", 3))
			ft_scanf_normal(object->file[i], object->normals,
				++object->nb_normal);
		else if (!ft_strncmp(object->file[i], "f ", 2))
			ft_scanf_face(object->file[i], object->faces, ++object->nb_faces);
	}
	// printf("V[%u] | VT[%d] | VN[%d] | F[%d]\n", object->nb_vertex, object->nb_tex_coords, object->nb_normal, object->nb_faces);
}
