/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:13:03 by tde-los-          #+#    #+#             */
/*   Updated: 2024/05/30 10:37:31 by tde-los-         ###   ########.fr       */
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

void	ft_scanf_face(const char *str, t_face *lst)
{
	t_face	*temp;
	t_face	*new;

	if (!lst)
	{
		ft_printf("%s%s%s\n", C_RED, E_ALLOC, C_NONE);
		return ;
	}
	temp = lst;
	while (temp->next)
		temp = temp->next;
	new = (t_face *)ft_calloc(sizeof(t_face), 1);
	if (!new)
	{
		ft_printf("%s%s%s\n", C_RED, E_ALLOC, C_NONE);
		return ;
	}
	new->next = NULL;
	sscanf(str, "f %u/%u/%u %u/%u/%u %u/%u/%u", \
		&new->vertex[0], &new->vertex_texture[0], &new->vertex_normal[0], \
		&new->vertex[1], &new->vertex_texture[1], &new->vertex_normal[1], \
		&new->vertex[2], &new->vertex_texture[2], &new->vertex_normal[2]);
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
		if (!ft_strncmp(object->file[i], "v ", 2))
			ft_scanf_vertices(object->file[i], object->vertices);
		else if (!ft_strncmp(object->file[i], "vn ", 3))
			ft_scanf_normal(object->file[i], object->normals);
		else if (!ft_strncmp(object->file[i], "f ", 2))
			ft_scanf_face(object->file[i], object->faces);
		else if (!ft_strncmp(object->file[i], "vt ", 3))
			ft_scanf_tex(object->file[i], object->tex_coords);
	}
}
