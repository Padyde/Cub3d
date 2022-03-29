#ifndef LIB_H
# define LIB_H

# include "all_inc.h"

int	ft_isspace(char c);
int	ft_strlcpy(char *dst, const char *src, int siz);
int	ft_matrixlen(char **m);
int	ft_strcmp(char *s1, char *s2);
int	ft_atoi(const char *str);
int	ft_isdigit(int c);
int	ft_strlen(const char *str);
int ft_all_space(char *input);

char	**ft_matrixlcpy(char **matrix_in, int nb_line);
char	**ft_split(char const *s, char c);
char	**ft_split_up(char *s);

void    ft_free_mat(char **mat);

#endif