/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 06:31:22 by tde-los-          #+#    #+#             */
/*   Updated: 2024/06/13 10:28:48 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

/*
	V = Definition des Sommets (Vertices)
	Vt = coordoneees de terture (Texture Vertices)
	Vn = Definition des normales (Normales Vertex)
	f = Definitions des faces qui peuvent utiliser des sommets, \
		coordonees de textures et des normales
	mtllib = Definition des materiaux 
	usemtl = Definition des materiaux
	s on/off : Indique le lissage  
*/

void	ft_read_obj(t_obj *object)
{
	char	*temp;
	char	buff[4096];
	int		size;
	char	*old_temp;

	temp = ft_calloc(1, 1);  // Initialisation correcte
	while ((size = read(object->fd, buff, sizeof(buff))) > 0)
	{
		old_temp = temp;
		buff[size] = '\0';
		temp = ft_strjoin(temp, buff);
		free(old_temp);
	}
	if (object->fd > 0)
		close(object->fd);
	if (temp)
	{
		object->file = ft_split(temp, '\n');
		free(temp);
	}
}

void	ft_init_obj(t_obj *object)
{
	object->vertices = ft_calloc(sizeof(t_coords), 1);
	object->normals = ft_calloc(sizeof(t_coords), 1);
	object->faces = ft_calloc(sizeof(t_face), 1);
	object->tex_coords = ft_calloc(sizeof(t_tex_coords), 1);
	object->nb_vertex = 0;
	object->nb_normal = 0;
	object->nb_tex_coords = 0;
	object->nb_faces = 0;
}

int	ft_parse_obj(t_obj *object)
{
	object->fd = open(object->dir, O_RDONLY);
	if (object->fd < 0 || read(object->fd, 0, 0) < 0)
		return (ft_printf("\n%s%s%s%s\n", C_RED, C_OPEN, object->dir, C_NONE));
	ft_read_obj(object);
	ft_init_obj(object);
	ft_read_file(object);
	return (0);
}