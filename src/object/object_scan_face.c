/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_scan_face.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:35:46 by tde-los-          #+#    #+#             */
/*   Updated: 2024/08/14 19:34:07 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void allocate_new_face(t_face **temp, t_face **new_face, t_face *lst)
{
    *temp = lst;
    while ((*temp)->next)
        *temp = (*temp)->next;
    *new_face = (t_face *)ft_calloc(sizeof(t_face), 1);
    if (!(*new_face))
    {
        ft_printf("%s%s%s\n", C_RED, E_ALLOC, C_NONE);
        return;
    }
    (*new_face)->next = NULL;
}


int count_vertices(const char *str, char ***tokens)
{
	int	i;
    int	num_read;

	num_read = 0;
    *tokens = ft_split(str, ' ');
	i = 1;
	while ((*tokens)[i] != NULL)
    {
        num_read++;
        if (num_read > 3)
            break;
		i++;
    }
    return (num_read);
}


void read_indices(t_face *new_face, char **tokens, int num_read)
{
	int	i;

	i = -1;
	while (++i < num_read)
    {
        sscanf(tokens[i + 1], "%u/%u/%u",
               &new_face->vertex[i], &new_face->vertex_texture[i], &new_face->vertex_normal[i]);
    }
}

void update_num_vertices(t_face *new_face, int num_read)
{
    new_face->num_vertices = num_read;
}


void ft_scanf_face(const char *str, t_face *lst)
{
    char 	**tokens;
    t_face	*temp;
    t_face	*new_face;
    int 	num_read;

    if (!lst)
    {
        ft_printf("%s%s%s\n", C_RED, E_ALLOC, C_NONE);
        return;
    }
    allocate_new_face(&temp, &new_face, lst);
    num_read = count_vertices(str, &tokens);
    read_indices(new_face, tokens, num_read);
    generate_color(new_face);
    get_random_color(new_face->color);
    update_num_vertices(new_face, num_read);
    free_tab(tokens);
    if (num_read < 3)
    {
        ft_printf("%sErreur de format de ligne de face : %s%s\n", C_RED, str, C_NONE);
        free(new_face);
        return;
    }
    temp->next = new_face;
}
