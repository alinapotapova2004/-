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
// ����������� ��������� Data, ������� ����� ������� ������ ������ ����� 
typedef struct {
	int type; // ���������� ��� �������� ���� ������: 0 - int, 1 - float, 2 - char 
	union {
		int i;
		float f;
		char c;
	} value; // ����������� ��� �������� �������� ���������������� ���� 
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
		char str[100]; // ���������� ������� �������� ��� �������� ��������� ������
		int count = 0; // ������� ��� �������� ���������� ����� ���� � ����
		int length = 0; // ���������� ��� �������� ����� ������� �����
		int prevLength = 0; // ���������� ��� �������� ����� ���������� �����
		int i = 0; // ������ ��� ������ �������
		int c; // ���������� ��� �������� �������� ���������� �������

		printf("Enter a string: ");  // ����� ������� �� ���� ������

		while ((c = getchar()) != '\n' && c != EOF) // ������ ������ �� ������� ����� ������ ��� ����� �����
		{  
			str[i++] = c;
		}
		str[i] = '\0';    // ���������� ������������ �������� ������� � ������
		for (i = 0; str[i] != '\0'; i++) 
{    // ����� ������ ��� ������� ��������
			if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')) {         // ��������, �������� �� ������ ������ ��� ������
				length++;
			}
			else {
				if (length > 0) {             // ���� ����� �� ������
					if (count == 0) {                 // ������ �����
						prevLength = length;
					}
					else {
						if (length != prevLength) { // �������� �� ���������� ����� ������� ����� � ����������
							printf("No\n");
							return 0;
						}
					}
					count++;
					length = 0;
				}
			}
		}

		if (length > 0 && length != prevLength) {    // �������� ��������� �����, ���� ��� �� ��������� �������� ����� ������
			printf("No\n");
			return 0;
		}
		printf("yes\n");
		return 0;
	}

void remove_numbers(char* str) {
	char* src = str, * dst = str; // ������������� ���������� �� ������ ������
	while (*src) { // ����, ���� �� ��������� ����� ������
		if (*src < '0' || *src > '9') { // ���� ������ �� �������� ������
			*dst++ = *src; // ����������� ������� � ����� �����
		}
		src++; // ������� � ���������� ������� � �������� ������
	}
	*dst = '\0'; // ���������� ������ ������� ��������
}

int laba4()
{
		char line[1000]; // ���������� ������� �������� ��� �������� ������
		fgets(line, sizeof(line), stdin); // ������ ������ �� ������������ �����
		remove_numbers(line); // ����� ������� ��� �������� ���� �� ������
		printf("%s", line); // ����� ����������������� ������ �� �����

		return 0; // ���������� ������ ���������
}

int laba5()
{
		// ���������� ������� x �������� N � ���������� i
		int x[N];
		int i;
		// ���������� ���������� ��� �������� ���� ������ � �������� ���������
		int sum_even = 0, sum_odd = 0;

		// ���� ��� ����� ��������� ������� � �������� ����� ������ � �������� ���������
		for (i = 0; i < N; i++) {
			scanf("%d", &x[i]);
			if (i % 2 == 0) {
				// ���� ������ �������� ������, ��������� ��� � sum_even
				sum_even += x[i];
			}
			else {
				// ����� ��������� ��� � sum_odd
				sum_odd += x[i];
			}
		}

		// ���� ��� �������� ������� � ��������� ��������� �������
		for (i = 0; i < N; i++) {
			// ���� ������ ������ � ����� ������ ��������� ������ ����� ��������,
			// ��� ������ �������� � ����� ������ ��������� ������ ��� ����� ����� ��������,
			// �� �������� ������� �������
			if ((i % 2 == 0 && sum_even < sum_odd) || (i % 2 != 0 && sum_even >= sum_odd)) {
				x[i] = 0;
			}
		}

		// ���� ��� ������ ��������� �������
		for (i = 0; i < N; i++) {
			printf("%d ", x[i]);
		}
		printf("\n");

		// ���������� 0, ��� �������� �������� ���������� ���������
		return 0;
}

int laba6()
{
		int x[K][N]; // ���������� ���������� ������� �������� K �� N
		int aver_global; // ���������� ��� �������� ����������� �������� ���������������
		int aver_row; // ���������� ��� �������� �������� ��������������� ������ ������
		int i, j, k; // ���������� ����������-���������

		// ���� ��� ����� ��������� �������
		for (i = 0; i < K; i++) {
			for (j = 0; j < N; j++) {
				scanf("%d", &x[i][j]); // ���� �������� �������
			}
		}

		// ���������� ����������� �������� ��������������� ��������
		aver_global = 0;
		for (i = 0; i < K; i++) {
			for (j = 0; j < N; j++) {
				aver_global += x[i][j]; // ������������ ���� ��������� �������
			}
		}
		aver_global /= (K * N); // ������ �������� ���������������

		// ���� ��� ��������� �����, ������� �������������� ������� ������ �����������
		for (i = 0; i < K; i++) {
			aver_row = 0;
			for (j = 0; j < N; j++) {
				aver_row += x[i][j]; // ������������ ��������� ������� ������
			}
			aver_row /= N; // ������ �������� ��������������� ������� ������

			if (aver_row < aver_global) { // �������� �������
				for (k = 0; k < N; k++) {
					x[i][k] = 0; // ��������� ��������� ������
				}
			}
		}

		// ����� ������������ �������
		for (i = 0; i < K; i++) {
			for (j = 0; j < N; j++) {
				printf("%4d ", x[i][j]); // ����� �������� �������
			}
			printf("\n"); // ������� �� ����� ������ ����� ������ ������ �������
		}

		return 0;
	}

int laba7()
{
 {
		unsigned long n, mask;
		printf("Vvedite chislo: ");
		scanf("%llu", &n);
		printf("������� �����: ");
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
		int count = 0; // ������� ������ �������� 
		int length = 0; // ����� �������� ����� �������� 
		int prevLength = 0; // ����� ����������� ����� �������� 
		int i;

		printf("Stroka: ");
		fgets(str, sizeof(str), stdin);

		for (i = 0; str[i] != '\0'; i++) {
			// ���������, �������� �� ������ ������ ��� ������ 
			if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')) {
				length++; // ����������� ����� �������� ����� �������� 
			}
			else
			{
				if (length > 0)
				{
					if (count == 0)
					{
						prevLength = length; // ���������� ����� ������� ����� �������� 
					}
					else
					{
						if (length != prevLength)
						{
							printf("���\n"); // ���� ����� ������ �� ���������, ������� "���" � ��������� ��������� 
							return 0;
						}
					}
					count++; // ����������� ������� ������ �������� 
					length = 0; // �������� ����� �������� ����� �������� 
				}
			}
			raise(SIGINT);

			return 0;

		}
	}

int dopzd5()
	 {
		Data x[N]; // ���������� ������� �������� ���� Data �������� N 
		int i;

		// ���� ��� ����� �������� � ������ 
		for (i = 0; i < N; i++) {
			printf("Enter type (0 - int, 1 - float, 2 - char): ");
			scanf("%d", &x[i].type); // ���� ���� ������ 
			switch (x[i].type) {
			case 0: // ���� ��� int 
				printf("Enter int: ");
				scanf("%d", &x[i].value.i); // ���� ������ ����� 
				break;
			case 1: // ���� ��� float 
				printf("Enter float: ");
				scanf("%f", &x[i].value.f); // ���� ����� � ��������� ������ 
				break;
			case 2: // ���� ��� char 
				printf("Enter char: ");
				scanf(" %c", &x[i].value.c); // ���� ������� 
				break;
			default: // ��� ��������� ���� 
				printf("Invalid type\n");
				i--; // ������ ����� ��� �������� ������� 
				break;
			}
		}

		// ���� ��� �������� ��������� � ��������� ��������� 
		for (i = 0; i < N; i++) {
			if (i % 2 != 0) {
				x[i].type = -1; // �������� ��������, ��������� ���� � -1 
			}
		}

		// ����� ������� ����� �������� ��������� � ��������� ��������� 
		printf("Array after removal:\n");
		for (i = 0; i < N; i++) {
			if (x[i].type != -1) { // ��������, ��� ������� �� ������ 
				switch (x[i].type) {
				case 0:
					printf("int: %d\n", x[i].value.i); // ����� ������ ����� 
					break;
				case 1:
					printf("float: %f\n", x[i].value.f); // ����� ����� � ��������� ������ 
					break;
				case 2:
					printf("char: %c\n", x[i].value.c); // ����� ������� 
					break;
				}
			}
		}

		return 0;
	 }

int dopzd6()
{
	int x[K][N]; // ���������� ���������� ������� �������� K �� N 
	int aver_global; // ���������� ��� �������� ����������� �������� ��������������� 
	int aver_row; // ���������� ��� �������� �������� ��������������� ������ ������ 
	int i, j, k; // ���������� ����������-��������� 

	// ���� ��� ����� ��������� ������� 
	for (i = 0; i < K; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &x[i][j]); // ���� �������� ������� 
		}
	}

	// ���������� ����������� �������� ��������������� �������� 
	aver_global = 0;
	for (i = 0; i < K; i++) {
		for (j = 0; j < N; j++) {
			aver_global += x[i][j]; // ������������ ���� ��������� ������� 
		}
	}
	aver_global /= (K * N); // ������ �������� ��������������� 

	// ���� ��� ��������� �����, ������� �������������� ������� ������ ����������� 
	for (i = 0; i < K; i++) {
		aver_row = 0;
		for (j = 0; j < N; j++) {
			aver_row += x[i][j]; // ������������ ��������� ������� ������ 
		}
		aver_row /= N; // ������ �������� ��������������� ������� ������ 

		if (aver_row < aver_global) { // �������� ������� 
			for (k = 0; k < N; k++) {
				x[i][k] = 0; // ��������� ��������� ������ 
			}
		}
	}

	// ����� ������������ ������� 
	for (i = 0; i < K; i++) {
		for (j = 0; j < N; j++) {
			printf("%4d ", x[i][j]); // ����� �������� ������� 
		}
		printf("\n"); // ������� �� ����� ������ ����� ������ ������ ������� 
	}

	return 0;
}
