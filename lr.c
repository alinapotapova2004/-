#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <signal.h>
#include "lr.h"

#define N 10
#define K 3 
#define N 4 

unsigned long reverseBitsWithMask(unsigned long n, unsigned long mask)
{
	unsigned long reversed = 0;
	for (int i = 0; i < 64; ++i) 
	{
		if ((n & (mask >> i)) > 0) 
		{
			reversed |= (1 << (63 - i));
		}
	}
	return reversed;
}
// Определение структуры Data, которая может хранить данные разных типов 
typedef struct {
	int type; // Переменная для хранения типа данных: 0 - int, 1 - float, 2 - char 
	union {
		int i;
		float f;
		char c;
	} value; // Объединение для хранения значения соответствующего типа 
} Data;

int laba1()
{
	float V = 0;
	float V1 = 0;
	float V2 = 0;
	float t = 0;
	printf("V=");
	scanf("%f", &V);
	printf("V1=");
	scanf("%f", &V1);
	printf("V2=");
	scanf("%f", &V2);
	if (V1 > V2) { t = V / (V1 - V2); }
	else { printf("error"); }
	printf("t=%f\n", t);
	return 0;
}

int laba2()
{
		float s = 0;
		float n = 1;
		float a = 1;
		float b = 1;
		float eps;
		printf("eps=");
		scanf("%f", &eps);
		while (n > eps)
		{
			s = s + n;
			a = a + 2;
			b = b + 3;
			n = n * (a / b);
		}
		printf("s=%f\n", s);

	return 0;
}

int laba3()
{
		char str[100]; // Объявление массива символов для хранения введенной строки
		int count = 0; // Счетчик для подсчета количества серий цифр и букв
		int length = 0; // Переменная для хранения длины текущей серии
		int prevLength = 0; // Переменная для хранения длины предыдущей серии
		int i = 0; // Индекс для обхода массива
		int c; // Переменная для хранения текущего введенного символа

		printf("Enter a string: ");  // Вывод запроса на ввод строки

		while ((c = getchar()) != '\n' && c != EOF) // Чтение строки до символа новой строки или конца файла
		{  
			str[i++] = c;
		}
		str[i] = '\0';    // Добавление завершающего нулевого символа в строку
		for (i = 0; str[i] != '\0'; i++) 
{    // Обход строки для анализа символов
			if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')) {         // Проверка, является ли символ буквой или цифрой
				length++;
			}
			else {
				if (length > 0) {             // Если серия не пустая
					if (count == 0) {                 // Первая серия
						prevLength = length;
					}
					else {
						if (length != prevLength) { // Проверка на совпадение длины текущей серии с предыдущей
							printf("No\n");
							return 0;
						}
					}
					count++;
					length = 0;
				}
			}
		}

		if (length > 0 && length != prevLength) {    // Проверка последней серии, если она не завершена символом новой строки
			printf("No\n");
			return 0;
		}
		printf("yes\n");
		return 0;
	}

void remove_numbers(char* str) {
	char* src = str, * dst = str; // Инициализация указателей на начало строки
	while (*src) { // Цикл, пока не достигнут конец строки
		if (*src < '0' || *src > '9') { // Если символ не является цифрой
			*dst++ = *src; // Копирование символа в новый буфер
		}
		src++; // Переход к следующему символу в исходной строке
	}
	*dst = '\0'; // Завершение строки нулевым символом
}

int laba4()
{
		char line[1000]; // Объявление массива символов для хранения строки
		fgets(line, sizeof(line), stdin); // Чтение строки из стандартного ввода
		remove_numbers(line); // Вызов функции для удаления цифр из строки
		printf("%s", line); // Вывод отредактированной строки на экран

		return 0; // Завершение работы программы
}

int laba5()
{
		// Объявление массива x размером N и переменной i
		int x[N];
		int i;
		// Объявление переменных для хранения сумм четных и нечетных элементов
		int sum_even = 0, sum_odd = 0;

		// Цикл для ввода элементов массива и подсчета суммы четных и нечетных элементов
		for (i = 0; i < N; i++) {
			scanf("%d", &x[i]);
			if (i % 2 == 0) {
				// Если индекс элемента четный, добавляем его к sum_even
				sum_even += x[i];
			}
			else {
				// Иначе добавляем его к sum_odd
				sum_odd += x[i];
			}
		}

		// Цикл для проверки условий и обнуления элементов массива
		for (i = 0; i < N; i++) {
			// Если индекс четный и сумма четных элементов меньше суммы нечетных,
			// или индекс нечетный и сумма четных элементов больше или равна сумме нечетных,
			// то обнуляем элемент массива
			if ((i % 2 == 0 && sum_even < sum_odd) || (i % 2 != 0 && sum_even >= sum_odd)) {
				x[i] = 0;
			}
		}

		// Цикл для вывода элементов массива
		for (i = 0; i < N; i++) {
			printf("%d ", x[i]);
		}
		printf("\n");

		// Возвращаем 0, что означает успешное завершение программы
		return 0;
}

int laba6()
{
		int x[K][N]; // Объявление двумерного массива размером K на N
		int aver_global; // Переменная для хранения глобального среднего арифметического
		int aver_row; // Переменная для хранения среднего арифметического каждой строки
		int i, j, k; // Объявление переменных-счетчиков

		// Цикл для ввода элементов массива
		for (i = 0; i < K; i++) {
			for (j = 0; j < N; j++) {
				scanf("%d", &x[i][j]); // Ввод элемента массива
			}
		}

		// Вычисление глобального среднего арифметического значения
		aver_global = 0;
		for (i = 0; i < K; i++) {
			for (j = 0; j < N; j++) {
				aver_global += x[i][j]; // Суммирование всех элементов массива
			}
		}
		aver_global /= (K * N); // Расчет среднего арифметического

		// Цикл для обнуления строк, среднее арифметическое которых меньше глобального
		for (i = 0; i < K; i++) {
			aver_row = 0;
			for (j = 0; j < N; j++) {
				aver_row += x[i][j]; // Суммирование элементов текущей строки
			}
			aver_row /= N; // Расчет среднего арифметического текущей строки

			if (aver_row < aver_global) { // Проверка условия
				for (k = 0; k < N; k++) {
					x[i][k] = 0; // Обнуление элементов строки
				}
			}
		}

		// Вывод обновленного массива
		for (i = 0; i < K; i++) {
			for (j = 0; j < N; j++) {
				printf("%4d ", x[i][j]); // Вывод элемента массива
			}
			printf("\n"); // Переход на новую строку после вывода строки массива
		}

		return 0;
	}

int laba7()
{
 {
		unsigned long n, mask;
		printf("Vvedite chislo: ");
		scanf("%llu", &n);
		printf("Введите маску: ");
		scanf("%llu", &mask);
		unsigned long reversed = reverseBitsWithMask(n, mask);
		printf("Chislo s perevernytimy bitami v maske: %llu\n", reversed);
		return 0;
 }
}

int dopzd1()
{


	return 0;
}

int dopzd2()
{
	int i;
	float s = 0;
	float n = 1;
	float a = 1;
	float b = 1;
	float eps;
	printf("eps=");
	scanf("%f", &eps);
	for (i = 0; i < 10; i++)
	{
		s = s + n;
		a = a + 2;
		b = b + 3;
		n = n * (a / b);
	}
	printf("s=%f\n", s);
	return 0;
}

int dopzd3()
	{

		char str[100];
		int count = 0; // счетчик блоков символов 
		int length = 0; // длина текущего блока символов 
		int prevLength = 0; // длина предыдущего блока символов 
		int i;

		printf("Stroka: ");
		fgets(str, sizeof(str), stdin);

		for (i = 0; str[i] != '\0'; i++) {
			// проверяем, является ли символ буквой или цифрой 
			if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')) {
				length++; // увеличиваем длину текущего блока символов 
			}
			else
			{
				if (length > 0)
				{
					if (count == 0)
					{
						prevLength = length; // запоминаем длину первого блока символов 
					}
					else
					{
						if (length != prevLength)
						{
							printf("Нет\n"); // если длины блоков не совпадают, выводим "Нет" и завершаем программу 
							return 0;
						}
					}
					count++; // увеличиваем счетчик блоков символов 
					length = 0; // обнуляем длину текущего блока символов 
				}
			}
			raise(SIGINT);

			return 0;

		}
	}

int dopzd5()
	 {
		Data x[N]; // Объявление массива структур типа Data размером N 
		int i;

		// Цикл для ввода значений в массив 
		for (i = 0; i < N; i++) {
			printf("Enter type (0 - int, 1 - float, 2 - char): ");
			scanf("%d", &x[i].type); // Ввод типа данных 
			switch (x[i].type) {
			case 0: // Если тип int 
				printf("Enter int: ");
				scanf("%d", &x[i].value.i); // Ввод целого числа 
				break;
			case 1: // Если тип float 
				printf("Enter float: ");
				scanf("%f", &x[i].value.f); // Ввод числа с плавающей точкой 
				break;
			case 2: // Если тип char 
				printf("Enter char: ");
				scanf(" %c", &x[i].value.c); // Ввод символа 
				break;
			default: // Для неверного типа 
				printf("Invalid type\n");
				i--; // Повтор ввода для текущего индекса 
				break;
			}
		}

		// Цикл для удаления элементов с нечетными индексами 
		for (i = 0; i < N; i++) {
			if (i % 2 != 0) {
				x[i].type = -1; // Удаление элемента, установка типа в -1 
			}
		}

		// Вывод массива после удаления элементов с нечетными индексами 
		printf("Array after removal:\n");
		for (i = 0; i < N; i++) {
			if (x[i].type != -1) { // Проверка, что элемент не удален 
				switch (x[i].type) {
				case 0:
					printf("int: %d\n", x[i].value.i); // Вывод целого числа 
					break;
				case 1:
					printf("float: %f\n", x[i].value.f); // Вывод числа с плавающей точкой 
					break;
				case 2:
					printf("char: %c\n", x[i].value.c); // Вывод символа 
					break;
				}
			}
		}

		return 0;
	 }

int dopzd6()
{
	int x[K][N]; // Объявление двумерного массива размером K на N 
	int aver_global; // Переменная для хранения глобального среднего арифметического 
	int aver_row; // Переменная для хранения среднего арифметического каждой строки 
	int i, j, k; // Объявление переменных-счетчиков 

	// Цикл для ввода элементов массива 
	for (i = 0; i < K; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &x[i][j]); // Ввод элемента массива 
		}
	}

	// Вычисление глобального среднего арифметического значения 
	aver_global = 0;
	for (i = 0; i < K; i++) {
		for (j = 0; j < N; j++) {
			aver_global += x[i][j]; // Суммирование всех элементов массива 
		}
	}
	aver_global /= (K * N); // Расчет среднего арифметического 

	// Цикл для обнуления строк, среднее арифметическое которых меньше глобального 
	for (i = 0; i < K; i++) {
		aver_row = 0;
		for (j = 0; j < N; j++) {
			aver_row += x[i][j]; // Суммирование элементов текущей строки 
		}
		aver_row /= N; // Расчет среднего арифметического текущей строки 

		if (aver_row < aver_global) { // Проверка условия 
			for (k = 0; k < N; k++) {
				x[i][k] = 0; // Обнуление элементов строки 
			}
		}
	}

	// Вывод обновленного массива 
	for (i = 0; i < K; i++) {
		for (j = 0; j < N; j++) {
			printf("%4d ", x[i][j]); // Вывод элемента массива 
		}
		printf("\n"); // Переход на новую строку после вывода строки массива 
	}

	return 0;
}
