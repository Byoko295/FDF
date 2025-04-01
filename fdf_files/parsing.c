# include "../utils/utils.h"
# include "../minilibx-linux/mlx.h"
//ITERE LES LIGNES POUR COMPTER LE NOMBRE DE LIGNES A STROCKER DANS SAVE DE LA FUNCTION GET_MAP_LINES
size_t ft_mapheight(int fd)
{
    char *save;
    int mapheight;

    mapheight = 0;
    if(fd == -1)
        return(0);
    save = get_next_line(fd);
    if(save == NULL){
        printf("file doesnt contain shit!");
        return(0);
    }
    else
        mapheight++;
    while(get_next_line(fd) != NULL)
    {
        mapheight++;
    }
    printf("mapheight is %i \n",mapheight);
    return(mapheight);
}
//COLLE TOUTES LES LIGNES DANS UNE GRANDE STRING OU LES LIGNES SONT SEPARER PAR DES /n
char *get_map_lines(int fd,size_t mapheight)
{
    char *save;

    save = get_next_line(fd);
    if(mapheight <= 0){
        printf("Map has zero lines!");
        return(0);
    }
    while(mapheight - 1)
    {
        save = ft_strjoin(save,get_next_line(fd));
        mapheight--;
    }
    return(save);
}
// cette fonction me permet de verifier luniformite de la taille des lignes et en meme temps de renvoyer la largeur de la map
size_t lines_length_uniformity(int fd, size_t mapheight)
{
    char **line;
    size_t stamp;
    size_t i;

    stamp = 0;
    line = ft_split(get_next_line(fd),' ');
        if(line == NULL)
            return(-1);
    while(line[stamp])
        stamp++;
    free(line);
    while(mapheight - 1)
    {
        i = 0;
        line = ft_split(get_next_line(fd),' ');
        if(line == NULL)
            return(0);
        while(line[i])
            i++;
        if(i != stamp)
            return(-1);
        free(line);
        mapheight--;
    }
    return(stamp);
}
//malloc un tableau de tableau de strctures
 coordinate **parsing_container(size_t mapheight,size_t mapwidth)
{
    coordinate **container;
    size_t i;

    i = 0;
    container = malloc(sizeof(coordinate) * mapheight);
    if (container == NULL){
        printf("Malloc fucked up");
        return(NULL);
    }
    while(i < mapheight)
    {
        container[i] = malloc(sizeof(coordinate) * mapwidth);
        if(container[i] == NULL)
            return(NULL);
        i++;
    }
    return(container);
}
coordinate **filling(int fd,size_t mapheight,coordinate **container)
{
    char **line;
    size_t i;
    size_t j;

    i = 0;
    while(i < mapheight)
    {
        line = ft_split(get_next_line(fd),' ');
        if(line == NULL)
            return(NULL);
        j = 0;
        while(line[j])
        { 
                container[i][j].x = i;
                container[i][j].y = j;
                //printf("X:%li Y:%li",i,j);
                color_checker(i, j, line[j], container);
                j++;
        }
    free(line);
    i++;
    }
    return(container);
}
void color_checker(int i, int j,char *line, coordinate **container)
{
    if(ft_strchr(line,','))
    {
        container[i][j].h = ft_atoi(line);
        container[i][j].c = ft_strdup(ft_strchr(line,','));
    }
    else
    {
        container[i][j].h = ft_atoi(line);
        container[i][j].c = ft_strdup("008000");
    }
    //printf("h:%ic:%s",container[i][j].h,container[i][j].c);
}

int draw_basic_line(coordinate a, coordinate b);

int main (int argc,char **argv)
{
    int fd ;
    size_t mapheight;
    size_t mapwidth;
    coordinate **container;

    if(argc < 2){
        printf("No map");
        return(0);        
    }
    fd = open(argv[1],O_RDONLY);
    mapheight = ft_mapheight(fd);
    close(fd);    
    fd = open(argv[1],O_RDONLY);
    mapwidth = lines_length_uniformity(fd,mapheight);
    printf("mapwidth :%li\n",mapwidth);
    if(!mapwidth)
        return(-1);
    close(fd);    
    fd = open(argv[1],O_RDONLY);
    container =  parsing_container(mapheight,mapwidth);
    if(container == NULL)
        return(-1);
    container = filling(fd,mapheight,container);
    if(container == NULL)
        return(-1);
    else
        printf("map all good");

    //CHECK HOW TO CREATE AN IMAAGE AND DISPLAY use drawbasicline to inut into iage buffer ()
}

    /*








            void	*mlx_ptr;
	void	*win_ptr;

    if(argc < 3)
    return(0);

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (0);
	win_ptr = mlx_new_window(mlx_ptr, ft_atoi(argv[1]), ft_atoi(argv[2]), "My first window!");
	if (win_ptr == NULL)
	{
		free(win_ptr);
		return (0);
	}
	while (1)
		;
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
        */













    //filling(container);




        


//create the **
/*
int lines_length_uniformity(char* save,int mapheight)
{
    int countton;
    int initialpos;
    char *tmp;
    int i;

    countton = 0;
    initialpos = 0;
    while(save[countton] != '\n')
    {
        countton++;
    }
    countton++;
    printf("count to %i\n",countton);
    while (mapheight)
    {
        tmp = ft_calloc(countton + 1,sizeof(char));
        if(tmp == NULL)
        {
             printf("tmp dead");
            return(0);
        }
        i = 0;
        while(i <= countton)
        {
            tmp[i] = save[initialpos + i];
            initialpos++;
            i++;
        }
    //printf("init%i\n",initialpos);
    //printf("i%i\n",i);
    tmp[i + 1] = '\0';
    initialpos=initialpos+2;
    //printf("init%i\n",initialpos);

    printf("%s\n",tmp);
    free(tmp);
    mapheight--;
    }
    return(1);
}
//MAKE THIS FUNCTION USE SPLIT INSTEAD OF COUNTING NUM OF CHARS BEFORE /N
//Keeping it just in case i need to count lines instead of 100-6nts before \n
int lines_length_uniformity(char *save,int mapheight)
{
    int initlen;
    int len;
    int i;

    i = 0;
    initlen = 0;
    while(save[i] != '\n')
    {
        initlen++;
        i++;    
    }
    while(mapheight - 1)
    {
        i++;
        len = 0;
        while(save[i] != '\n')
        {
            len ++;
            i++;
        }
        if(len != initlen)
            return(0);
        mapheight--;
    }
    return(1);
}
*/