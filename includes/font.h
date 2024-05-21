/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:41:18 by tde-los-          #+#    #+#             */
/*   Updated: 2024/05/18 08:13:58 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#ifndef FONT_H
# define  FONT_H

/	Fonts
# define ARIAL "assets/fonts/arial.ttf"
# define CARNIVAL "assets/fonts/Carnival.ttf"
# define FRANCHISE "assets/fonts/Franchise.ttf"
# define MAGIC_RETRO "assets/fonts/Magic_retro.ttf"
# define NAMECAT "assets/fonts/Namecat.ttf"
# define SUPER_RETRO "assets/fonts/Super_retro.ttf"
/	Includes	
# include "include.h"
# include <SDL2/SDL_ttf.h>


typedef	struct  s_text
{
	SDL_Color		color;
	SDL_Surface		*textSurface;
	SDL_Texture		*textTexture;
	SDL_Rect		textRect;
}	s_text;

typedef struct s_font
{
	int				id;
	char			*name;
	TTF_Font		*font;
	struct s_font	*next;
}	t_font;


/			FUNCTION
void    font_create(t_font *font, char *file);
void    font_lib(t_font *font);
void	init_font(t_font *font);
t_font	*font_next(t_font *lst);
t_font  *get_font(t_font *font, char *name);
void	free_font(t_font *lst);

#endif
*/