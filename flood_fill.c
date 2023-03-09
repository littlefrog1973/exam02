#include "flood_fill.h"


void	do_flood(char **tab, t_point size, int x, int y)
{
	if (x < 0 || y < 0)
		return ;
	if (x + 1 > size.x || y + 1 > size.y)
		return ;
	if (tab[y][x] == '0' || tab[y][x] == 'F')
		return ;
	if (tab[y][x] != 'F' && tab[y][x] != '0' && tab[y][x] != '\0')
	{
		tab[y][x] = 'F';
	}
	do_flood(tab, size, x - 1, y);
	do_flood(tab, size, x + 1, y);
	do_flood(tab, size, x, y - 1);
	do_flood(tab, size, x, y + 1);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	do_flood(tab, size, begin.x, begin.y);
}
