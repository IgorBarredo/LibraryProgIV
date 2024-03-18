#include "strings.h"

#include <stdio.h>
#include <stdlib.h>

void printStr(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		printf("%c", str[i]);
		i++;
	}
}

int length(char *str)
{
	int c = 0;
	while (*str != '\0')
	{
		c++;
		str++;
	}
	return c;
}

char* clone(char *str)
{
	
	
	int size = length(str);
	//char newStr[size+1]; // Esta memoria se libera al cerrar la }

	char * newStr = malloc((size + 1) * sizeof(char));
	
	int i = 0;
	while (str[i] != '\0')
	{
		newStr[i] = str[i];
		i++;
	}
	newStr[i] = '\0';
	return newStr;
}

void concat(char *str1, char *str2)
{
	while (*str1 != '\0')
		str1++;

	copy(str1, str2);
	//copy(&str1[length(str1)], str2);
}

void copy(char *dest, char *src)
{
	int i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}









