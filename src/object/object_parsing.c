/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:13:03 by tde-los-          #+#    #+#             */
/*   Updated: 2024/06/07 15:57:31 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	ft_scanf_vertices(const char *str, t_coords *lst)
{
	t_coords	*temp;
	t_coords	*new;

	if (!lst)
	{
		ft_printf("%s%s%s\n", C_RED, E_ALLOC, C_NONE);
		return ;
	}
	temp = lst;
	while (temp->next)
		temp = temp->next;
	new = (t_coords *)ft_calloc(sizeof(t_coords), 1);
	if (!new)
	{
		ft_printf("%s%s%s\n", C_RED, E_ALLOC, C_NONE);
		return ;
	}
	new->next = NULL;
	sscanf(str, "v %f %f %f", &new->x, &new->y, &new->z);
	temp->next = new;
}

void	ft_scanf_normal(const char *str, t_coords *lst)
{
	t_coords	*temp;
	t_coords	*new;

	if (!lst)
	{
		ft_printf("%s%s%s\n", C_RED, E_ALLOC, C_NONE);
		return ;
	}
	temp = lst;
	while (temp->next)
		temp = temp->next;
	new = (t_coords *)ft_calloc(sizeof(t_coords), 1);
	if (!new)
	{
		ft_printf("%s%s%s\n", C_RED, E_ALLOC, C_NONE);
		return ;
	}
	new->next = NULL;
	sscanf(str, "vn %f %f %f", &new->x, &new->y, &new->z);
	temp->next = new;
}


void	ft_scanf_tex(const char *str, t_tex_coords *lst)
{
	t_tex_coords	*temp;
	t_tex_coords	*new;

	if (!lst)
	{
		ft_printf("%s%s%s\n", C_RED, E_ALLOC, C_NONE);
		return ;
	}
	temp = lst;
	while (temp->next)
		temp = temp->next;
	new = (t_tex_coords *)ft_calloc(sizeof(t_tex_coords), 1);
	if (!new)
	{
		ft_printf("%s%s%s\n", C_RED, E_ALLOC, C_NONE);
		return ;
	}
	new->next = NULL;
	sscanf(str, "vt %f %f", &new->u, &new->v);
	temp->next = new;
}

void	ft_read_file(t_obj *object)
{
	int	i;

	i = 0;
	while (object->file[++i])
	{
		if (!ft_strncmp(object->file[i], "v ", 2) && ++object->nb_vertex)
			ft_scanf_vertices(object->file[i], object->vertices);
		else if (!ft_strncmp(object->file[i], "vn ", 3) && ++object->nb_normal)
			ft_scanf_normal(object->file[i], object->normals);
		else if (!ft_strncmp(object->file[i], "f ", 2) && ++object->nb_faces)
			ft_scanf_face(object->file[i], object->faces);
		else if (!ft_strncmp(object->file[i], "vt ", 3) && \
			++object->nb_tex_coords)
			ft_scanf_tex(object->file[i], object->tex_coords);
	}
	free_tab(object->file);
	object->file = NULL;
	printf("[V][%d] [VN][%d] [F][%d] [VT][%d]\n", object->nb_vertex, object->nb_normal, object->nb_faces, object->nb_tex_coords);
}
