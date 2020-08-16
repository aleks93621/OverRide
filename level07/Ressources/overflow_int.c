#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int nbr;
	int	decalage;

	nbr = atoi(av[1]);
	decalage = atoi(av[2]);	
	printf("nbr: %d  --------  nbr >> %d = %d\n", nbr, decalage, nbr >> decalage);
	printf("(%d * 4) + 114 = %d\n", nbr, (nbr * 4) + 114);

	return 0;
}