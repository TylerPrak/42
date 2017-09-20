/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 12:56:42 by tprak             #+#    #+#             */
/*   Updated: 2017/09/18 01:29:32 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "./libft/libft.h"

# define BUF_SIZE 21
# define ZERO_CHECK(x, y) if (!x) return (y);
# define NULL_CHECK(x, y) if (x == NULL) return (y);
# define NEG_CHECK(x, y) if (x == -1) return (y);
# define SQUARED(x) x*x
# define LETTER(i) 'A' + i

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_tetris_piece
{
	int				h;
	int				w;
	char			buf[BUF_SIZE + 1];
	char			piece[5][5];
	char			letter;
	struct s_pos	tpos[4];
	struct s_pos	zpos[4];
	struct s_pos	tranpos;
}					t_tet_piece;

typedef struct		s_varible
{
	int				fd;
	int				tpieces;
	int				size;
	int				lastret;
	char			**map;
	char			**buf;
}					t_var;

int					ft_error();
int					ft_read(t_tet_piece *tetris, t_var *vl, int i);
void				ft_hash_to_letter(char *buf, int i, char c);
int					ft_valid_lines(char *buf);
int					ft_valid_tetris(char *buf);
int					ft_check_hash_up(char *buf, int i);
int					ft_check_hash_right(char *buf, int i);
int					ft_check_hash_left(char *buf, int i);
int					ft_check_hash_down(char *buf, int i);
int					ft_count_connections(char *buf, int i);
int					ft_store(t_tet_piece *tetris, t_var *vl, int x, int i);
void				ft_store_tetpos(t_tet_piece *tet, int y, int x, int *h);
void				ft_store_zeropos(t_tet_piece *tetris, int hashes);
void				ft_store_tranpos(t_tet_piece *tet, t_var *vl, int y, int x);
void				ft_clear_tranpos(t_tet_piece *tetris);
void				ft_init_tranpos(t_tet_piece *tetris);
char				**ft_map(t_var *vl, int y, int x);
int					ft_get_min_map_size(t_var *vl);
void				ft_print_map(t_var *vl, int y, int x);
void				ft_print_mapp(t_var *vl, char **buf, int y, int x);
int					ft_solve(t_tet_piece *tetris, t_var *vl, int i, int x);
int					ft_valid_place(t_tet_piece *tet, t_var *vl, int y, int x);
int					ft_check_coords(t_tet_piece *tet, t_var *vl, int y, int x);
int					ft_check_letter(t_var *vl, int ysum, int xsum);
int					ft_place(t_tet_piece *tetris, t_var *vl, int y, int x);
int					ft_remove(t_tet_piece *tetris, t_var *vl, int y, int x);
#endif
