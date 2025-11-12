// main.c
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void Result(const char* libname, const char* func, float arg_1, float arg_2)
{
    void *handle;
	float (*result_ptr)(float, float);
	char *error;
	
	handle = dlopen(libname, RTLD_LAZY);
	if (!handle)
	{
	    fputs(dlerror(), stderr);
	    exit(1);
	}
	
	result_ptr = dlsym(handle, func);
	if ((error = dlerror()) != NULL)
	{
	    fprintf (stderr, "%s\n", error);
	    exit(1);
	}
	
	printf("Ответ: %.2f\n", (*result_ptr)(arg_1, arg_2));
	dlclose(handle);
}

void Menu()
{
	int choice = 0;
	float arg_1 = 0, arg_2 = 0;

	// Ввод функции
	printf("\nВведите номер действия: ");
	scanf("%d", &choice);
	if (choice < 1 || choice > 7)
	{
	    // Проверка на корректность ввода
	    printf("Неккоретный ввод!\n"); 
	    return;
	}
	if (choice == 7) exit(0); // Выход

	// Ввод аргументов
	printf("Введите первый аргумент: ");
	scanf("%f", &arg_1);
	printf("Введите второй аргумент: ");
	scanf("%f", &arg_2);
	
	switch (choice)
	{
	    case 1:
	        Result("./libadd.so", "Addition", arg_1, arg_2);
	        break;
	    
	    case 2:
	        Result("./libsub.so", "Subtraction", arg_1, arg_2);
	        break;
	        
	    case 3:
	        Result("./libmult.so", "Multiplication", arg_1, arg_2);
	        break;
	        
	    case 4:
	        Result("./libdiv.so", "Division", arg_1, arg_2);
	        break;
	        
	    case 5:
	        Result("./libmax.so", "Max", arg_1, arg_2);
	        break;
	        
	    case 6:
	        Result("./libmin.so", "Min", arg_1, arg_2);
	        break;
	}
}

int main()
{
	printf("Задание 6.3: калькулятор с динамическими библиотеками\n");
	printf("Доступные действия:\n1 - сложение\n2 - вычитание\n3 - умножение\n4 - деление\n5 - max\n6 - min\n7 - выход\n");

	while (1)
	{
		Menu();
	}
}
