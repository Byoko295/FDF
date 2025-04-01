#ifndef FDF_H
# define FDF_H


# include "../utils/utils.h"

size_t ft_mapheight(int fd);
char *get_map_lines(int fd,size_t mapheight);
size_t lines_length_uniformity(int fd, size_t mapheight);
coordinate **parsing_container(size_t mapheight,size_t mapwidth);
coordinate **filling(int fd,size_t mapheight,coordinate **container);
void color_checker(int i, int j,char *line, coordinate **container);

#endif
