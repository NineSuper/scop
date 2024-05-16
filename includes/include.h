/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:14:12 by tde-los-          #+#    #+#             */
/*   Updated: 2024/05/16 22:51:08 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

/*      Libft       */
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/gnl/get_next_line.h"
/*		Librairie	*/
# include <GL/gl.h>
# include <GL/glut.h>
# include <SDL2/SDL.h>
# include <stdbool.h>

# include "font.h"

/*		String		*/
# define TITLE "SCOP"
/*      Error       */
# define E_ALLOC    "Error: Memory allocation failed."
# define E_SDL_INIT "Error: SDL initialization failed."
# define E_WIN      "Error: Window initialization failed."
/*		Texture		*/

/*		Color		*/
# define C_GREEN "\033[1;32m"
# define C_RED "\033[1;41m"
# define C_NONE "\033[0m"
/*		Screen Size	 */
# ifndef WIDTH
#  define WIDTH 960
# endif

# ifndef HEIGHT
#  define HEIGHT 540
# endif

typedef struct s_coods
{
	int	x;
	int	y;
	int	w;
	int	h;
}	t_coords;

typedef	struct s_win
{
	SDL_Window	*window;
    char		*title;
    int			height;
    int			width;
}   t_win;

typedef	struct s_master
{
    t_win	win;   
	s_font	font;
}	t_master;

//			FUNCTION		//

/*		INIT	*/
void	ft_init_window(t_master *s_m);
/*		FREE	*/
void	ft_free_all(t_master *s_m);
void	free_tab(void **tab);
//			FUNCTION		//
#endif