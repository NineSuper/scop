/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 08:06:40 by tde-los-          #+#    #+#             */
/*   Updated: 2024/07/11 16:31:27 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

/*	Includes	*/
# include "include.h"

typedef struct s_coords
{
	struct s_coords	*next;
	float			x;
	float			y;
	float			z;
}	t_coords;

typedef struct s_tex_coords
{
	struct s_tex_coords	*next;
	float				u;
	float				v;
}	t_tex_coords;

typedef struct s_face
{
	unsigned int	vertex[3];
	unsigned int	vertex_texture[3];
	unsigned int	vertex_normal[3];
	int				num_vertices;
	GLfloat			color[4];
	struct s_face	*next;
}	t_face;

typedef struct s_glpos
{
	GLfloat	**vertices;
	GLfloat	**textures;
	GLfloat	**normals;
}	t_glpos;

typedef struct s_mtl
{
	char	*newmtl;
	char	*dir;
	char	**file;
	float	Ns;
	float	Ka[3];
	float	Kd[3];
	float	Ks[3];
	float	Ni;
	float	d;
	int		illum;
}	t_mtl;

typedef struct s_obj
{
	t_coords		*vertices;
	t_tex_coords	*tex_coords;
	t_coords		*normals;
	t_face			*faces;
	t_glpos			*glpos;
	t_mtl			*mtl;
	char			**file;
	char			*dir;
	bool			print_tex;
	int				fd;
	int				nb_vertex;
	int				nb_normal;
	int				nb_tex_coords;
	int				nb_faces;
	GLuint			texture_id;
}	t_obj;

#endif
