  /*<Fan Crontoller, control a fan based on the current temperature>
    Copyright (C) <2016>  <Carlos Acosta,Jesus Flores, Rodrigo Galeano,Roberto Guerrero >

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.*/
#include <stdio.h>

#include "temperatura.h"

int leeTemp()
{
	FILE *fd;
	char temp[2];
	int real;

	fd = fopen(TEMP, "r");

	if (!fd)
	{
		printf("no existe el archivo\n");
		return -1;		
	}

	// obteniendo digitos del archivo
	temp[0] = fgetc(fd);
	temp[1] = fgetc(fd);

	// convirtiendo string a entero
	real = (temp[0] - '0') * 10 + (temp[1] - '0');
	fclose(fd);
	return real;
}
