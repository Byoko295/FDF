# include "fdf.h"
# include "get_next_line.h"
# include "libft.h"

char **parsemap(int fd)
{
    char *save;
    int length;
    //check si toutes les lignes font bien la meme taille sinon cest fucked up
    // stocker toutes les lignes dans un char* a taille malloc fix
    while(get_next_line(fd) != NULL)
    {
        save = ft_strdup(get_next_line(fd));
        length = ft_strlen(save);

    }

}