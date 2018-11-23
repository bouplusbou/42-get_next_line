
static list

si list
	si fd == fd
		trouve le maillon du fd
		tmp = str
		str = strchr de \n dans str (mettre le ptr juste apres le \n)
		str - 1 = \0
		line = strdup(tmp)
	si 


read buffer
	si 1
		si \n
			un maillon par fd
			une structure dans chaque maillon avec "str" "fd"
			

		si pas \n
			boucle jusqu'a trouver un \n


	si -1
		"erreur de read"

	si 0
		"plus rien a read"


assigner line




int	get_next_line(const int fd, char **line)
{
}
