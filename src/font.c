/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:44:59 by tde-los-          #+#    #+#             */
/*   Updated: 2024/05/18 08:14:28 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
# include "../includes/include.h"

void    font_create(t_font *font, char *file)
{
    t_font  *temp;

    if (!file)
    {
        printf("Font error: 'NULL' ❌\n");
        return ;
    }
    temp = font_next(font);
    if (!temp)
        printf("error\n");
    temp->name = ft_strdup(file);
    temp->font = TTF_OpenFont(file, 24);
    if (!temp->font)
    {
        printf("Font error: %s can\'t be load ❌\n", file);
        return ;
    }
    printf("Font loaded successfully: %s ✅\n", temp->name);
}

t_font  *get_font(t_font *font, char *name)
{
    t_font  *temp = font->next;

    while (temp)
    {
        if (!ft_strncmp(temp->name, name, strlen(name)))
            return (temp);
        temp = temp->next;
    }
    return (NULL);
}

void	free_font(t_font *lst)
{
    t_font	*current;
    t_font	*next;

	printf("\n\t[Free font 🖍️ ]\n\n");
	if (!lst)
		return ;
	current = lst->next;
    while (current != NULL)
	{
        next = current->next;
		if (current->name && current->font)
			ft_printf("Font successfully free: %s ⬜\n", current->name);
		if (current->name)
            free(current->name);
		if (current->font)
            TTF_CloseFont(current->font);
        free(current);
        current = next;
    }
}

void    font_lib(t_font *font)
{
    printf("\n\t[Loading font 🖍️ ]\n\n");
    font_create(font, ARIAL);
    font_create(font, CARNIVAL);
	font_create(font, FRANCHISE);
    font_create(font, MAGIC_RETRO);
    font_create(font, NAMECAT);
    font_create(font, SUPER_RETRO);
	font_create(font, NULL);
    font_create(font, "TEST_ERROR");
}

void	init_font(t_font *font)
{
	TTF_Init();
    font->next = NULL;
    font->id = 0;
    font_lib(font);
}

// *	Fonction ajoute un font en fin de liste (struct font->next)

t_font	*font_next(t_font *lst)
{
	t_font	*new;
	t_font	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	new = (t_font *)ft_calloc(sizeof(t_font), 1);
	*new = (t_font){.font = NULL, .id = temp->id + 1, .name = NULL};
	if (!new)
		return (NULL);
	new->next = NULL;
	temp->next = new;
	return (new);
}
*/