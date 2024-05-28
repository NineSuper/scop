/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 06:31:22 by tde-los-          #+#    #+#             */
/*   Updated: 2024/05/28 15:02:41 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

/*
	V = Definition des Sommets (Vertices)
	Vt = coordoneees de terture (Texture Vertices)
	Vn = Definition des normales (Normales Vertex)
	f = Definitions des faces qui peuvent utiliser des sommets, coordonees de textures et des normales
	mtllib = Definition des materiaux 
	usemtl = Definition des materiaux
	s on/off : Indique le lissage  
*/

void	ft_read_obj(t_obj *object)
{
	char	*temp;
	char	buff[1];
	int		size;

	size = 1;
	temp = ft_calloc(sizeof(char), 1);
	while (size != 0)
	{
		size = read(object->fd, buff, 1);
		if (size)
			temp = gnl_ft_strjoin(temp, buff);
	}
	if (object->fd)
		close(object->fd);
	if (temp)
	{
		object->file = ft_split(temp, '\n');
		free(temp);
	}
}

void	ft_init_obj(t_obj *object)
{
	object->vertices = NULL;
	object->normals = NULL;
	object->faces = NULL;
	object->nb_vertex = 0;
	object->nb_normal = 0;
	object->nb_tex_coords = 0;
	object->nb_faces = 0;
}

void	ft_read_file(t_obj *object)
{
	int	i;

	i = 0;
	while (object->file[++i])
	{
		if (!ft_strncmp(object->file[i], "v ", 2))
		{
			object->nb_vertex++;
		}
		else if (!ft_strncmp(object->file[i], "vt ", 3))
		{
			object->nb_tex_coords++;
		}
		else if (!ft_strncmp(object->file[i], "vn ", 3))
		{
			object->nb_normal++;
		}
		else if (!ft_strncmp(object->file[i], "f ", 2))
		{
			object->nb_faces++;
		}
	}
	printf("V[%u] | VT[%d] | VN[%d] | F[%d]\n", object->nb_vertex, object->nb_tex_coords, object->nb_normal, object->nb_faces);
}

int	ft_parse_obj(t_obj *object)
{
	object->fd = open(object->dir, O_RDONLY);
	if (object->fd < 0 || read(object->fd, 0, 0) < 0)
		return (ft_printf("%s%s%s%s\n", C_RED, C_OPEN, object->dir, C_NONE));
	ft_read_obj(object);
	ft_init_obj(object);
	ft_read_file(object);
	return (0);
}
// une fois fini free(object->file);
