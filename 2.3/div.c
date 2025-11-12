// div.c
#include <stdio.h>
#include <math.h>

float Division(float arg_1, float arg_2)
{
	if (arg_2 == 0) // Проверка деления на 0
	{
		printf("Деление на ноль!\n");
		return INFINITY;
	}
	else
	{
		return arg_1 / arg_2;
	}
}
