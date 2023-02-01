/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:43:07 by jnoh              #+#    #+#             */
/*   Updated: 2022/01/27 11:22:46 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_game
{
	char	**input_board;
	int		**result_board;
	char	charset[3];
	int		x;
	int		y;
	int		find_eof;
	int		ans[3];
}	t_game;

int		**ft_malloc_int_array(int x, int y);
void	ft_free_all(t_game *game);
void	ft_init(t_game *game);
char	*ft_read_first_line(int fd);
int		ft_first_line(t_game *game, int fd);
char	*ft_get_one_line_first(t_game *game, int fd);
char	*ft_get_one_line_other(t_game *game, int fd);
char	*ft_get_one_line(t_game *game, int fd);
int		ft_open_file(t_game *game, char *file_name, int mode);
void	ft_putstr(char *str);
void	ft_print_ans(t_game *game, int x, int y);
void	ft_print_board(t_game *game);
void	ft_error_map(t_game *game, void *to_free);
void	ft_reset_print(void);
int		ft_min(int a, int b, int c);
int		ft_get(int x, int y);
void	ft_search(void);
void	ft_do_logic(t_game *game);
int		ft_is_overlap(char *str);
int		ft_strlen(char *str);
void	ft_strcpy(char *dest, char *str, int size);
char	*ft_strdup(char *src);
void	ft_strcpy_add_one(char *dest, char *str, int size, char chr);
char	*ft_strdup_add_one(char *src, char chr);
char	*ft_read_line(int fd, int now_line);
int		ft_read_file(char *file_name, int mode);
void	ft_start(char *filename, int mode);
int		ft_is_numeric(char c);
int		ft_is_all_number(char *str, char finish_chr);
int		ft_atoi(char *str);
int		ft_first_line_valid(char *check_charset);
int		ft_check_first_line_empty(t_game *game, char *buf, int read_size);
int		ft_check_line_length(t_game *game, char *buf);
int		ft_check_line_char(t_game *game, char *buf, int i);
#endif