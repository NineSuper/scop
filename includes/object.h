/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 08:06:40 by tde-los-          #+#    #+#             */
/*   Updated: 2024/05/21 14:13:35 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

/*	Includes	*/
# include "include.h"

typedef struct s_vertex
{
	float	x;
	float	y;
	float	z;
}	t_vertex;

typedef struct s_normal
{
	float	x;
	float	y;
	float	z;
}	t_normal;

typedef struct s_face
{
	int	vertex_indices[3];
	int	normal_indices[3];
}	t_face;

typedef struct s_obj
{
	t_vertex	*vertices;
	t_normal	*normals;
	t_face		*faces;
	char		**file;
	char		*dir;
	int			fd;
	int			nb_vertices;
	int			nb_normals;
	int			nb_faces;
}	t_obj;

#endif