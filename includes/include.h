/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:14:12 by tde-los-          #+#    #+#             */
/*   Updated: 2024/05/30 14:39:03 by tde-los-         ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "object.h"
# include "keyboard.h"

/*		String		*/
# define TITLE "SCOP"
/*      Error       */
# define E_ALLOC    "Error: Memory allocation failed."
# define E_SDL_INIT "Error: SDL initialization failed."
# define E_WIN      "Error: Window initialization failed."
# define C_OPEN      "Error: Can\'t open: "
# define B_ARG		"./Scop <file>.obj"
/*		Texture		*/

/*		Color		*/
# define C_GREEN "\033[1;32m"
# define C_RED "\033[1;41m"
# define C_NONE "\033[0m"
/*		Screen Size	 */
# ifndef WIDTH
#  define WIDTH 1280
# endif

# ifndef HEIGHT
#  define HEIGHT 720
# endif

typedef struct s_win
{
	SDL_GLContext	context;
	SDL_Window		*window;
	SDL_Event		event;
	char			*title;
	int				height;
	int				width;
}	t_win;

typedef struct s_master
{
	t_win	win;
	t_obj	object;
	bool	quit;
}	t_master;

//			FUNCTION		//

//	INIT
void	ft_init_window(t_master *s_m);
void	ft_sdl_loop(t_master *s_m);
int		ft_parse_obj(t_obj *object);
void	init_glpos(t_obj *obj);
//	FREE
void	ft_free_all(t_master *s_m);
void	free_tab(char **tab);
void	ft_free_obj(t_obj *object);
void	free_glfloat(GLfloat **vertices, int nb_vertices);
// PARSING
void	ft_read_file(t_obj *object);
//			FUNCTION		//

#endif