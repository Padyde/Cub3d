#include "all.h"

void    free_all(t_datas_global *all_datas)
{
    if (!all_datas)
        return ;
    if (all_datas->player_datas)
        free(all_datas->player_datas);
    if (all_datas->map_datas->east_wall)
        free(all_datas->map_datas->east_wall);
    if (all_datas->map_datas->north_wall)
        free(all_datas->map_datas->north_wall);
    if (all_datas->map_datas->west_wall)
        free(all_datas->map_datas->west_wall);
    if (all_datas->map_datas->south_wall)
        free(all_datas->map_datas->south_wall);
    if (all_datas->map_datas->map)
        ft_free_mat(all_datas->map_datas->map);
    if (all_datas->map_datas)
        free(all_datas->map_datas);
    if (all_datas->tmp)
        free(all_datas->tmp);
    if (all_datas->tmp1)
        ft_free_mat(all_datas->tmp1);
}

void    malloc_all(t_datas_global *all_datas)
{
    all_datas->map_datas = malloc(sizeof(t_datas_map));
    if (!all_datas->map_datas)
        ft_print_error("Error: Malloc doesn't work\n", all_datas);
    all_datas->player_datas = malloc(sizeof(t_datas_player));
    if (!all_datas->player_datas)
        ft_print_error("Error: Malloc doesn't work\n", all_datas);
    all_datas->map_datas->north_wall = malloc(sizeof(t_datas_wall));
    if (!all_datas->map_datas->north_wall)
        ft_print_error("Error: Malloc doesn't work\n", all_datas);
    all_datas->map_datas->south_wall = malloc(sizeof(t_datas_wall));
    if (!all_datas->map_datas->south_wall)
        ft_print_error("Error: Malloc doesn't work\n", all_datas);
    all_datas->map_datas->east_wall = malloc(sizeof(t_datas_wall));
    if (!all_datas->map_datas->east_wall)
        ft_print_error("Error: Malloc doesn't work\n", all_datas);
    all_datas->map_datas->west_wall = malloc(sizeof(t_datas_wall));
    if (!all_datas->map_datas->west_wall)
        ft_print_error("Error: Malloc doesn't work\n", all_datas);

    all_datas->map_datas->sky = -1;
    all_datas->map_datas->floor = -1;
    all_datas->map_datas->south_wall->ptr = NULL;
    all_datas->map_datas->east_wall->ptr = NULL;
    all_datas->map_datas->north_wall->ptr = NULL;
    all_datas->map_datas->west_wall->ptr = NULL;
    all_datas->tmp = NULL;
    all_datas->tmp1 = NULL;
    all_datas->map_datas->map = NULL;

    all_datas->player_datas->start = -1;
    all_datas->mlx_ptr = mlx_init();
    all_datas->win_ptr = mlx_new_window(all_datas->mlx_ptr, 800, 600, "cub3d");
}

int main (int argc, char **argv)
{
    t_datas_global all_datas;
    int fd;
    int tmp;
    
    //first check
    fd = first_tests(argv, argc);


    //alloue toute la memoire
    malloc_all(&all_datas);

    //convertit les donnees du fichier
    convert_datas(fd, &all_datas);
    
    //verifie que la map existe
    if (!all_datas.map_datas->map)
        ft_print_error("Error: Not map in file\n", &all_datas);

    //verifie l'integrite du fichier
    tmp = check_map(&all_datas);
    if (tmp == -1)
        ft_print_error("Error: Wrong char in map\n", &all_datas);
    else if (tmp == -2)
        ft_print_error("Error: Wrong position of char in map\n", &all_datas);

    printf("North        -> %d\n",all_datas.map_datas->north_wall->size_x);
    printf("East         -> %d\n",all_datas.map_datas->east_wall->size_x);
    printf("South        -> %d\n",all_datas.map_datas->south_wall->size_x);
    printf("West         -> %d\n",all_datas.map_datas->west_wall->size_x);
    printf("Floor        -> %d\n",all_datas.map_datas->floor);
    printf("Sky          -> %d\n",all_datas.map_datas->sky);
    printf("Player x     -> %f\n",all_datas.player_datas->x);
    printf("Player x     -> %f\n",all_datas.player_datas->y);
    printf("Player View  -> %d\n",all_datas.player_datas->start);

    printf("Map:\n");
    int x = -1;
    while (++x < ft_matrixlen(all_datas.map_datas->map))
        printf("%s\n",all_datas.map_datas->map[x]);
    close(fd);
    free_all(&all_datas);
}