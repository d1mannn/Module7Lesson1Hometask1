#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <iostream>
#include "Header.h"
using namespace std;
int task;

void TaskNumber()
{	
	setlocale(LC_ALL, "Rus");
	do
	{
		cout << "Введиет номер задания - ";
		cin >> task;
		switch (task)
		{
			case 1:
			{	
				/*1.	Написать функцию, которая проверяет, является ли переданное 
					ей число простым ? Число называется простым, если оно
					делится без остатка только на себя и на единицу.*/
				int numb;
				cout << "Введите число - ";
				cin >> numb;
				SimpleNumb(&numb);
			} break;

			case 2:
			{
				/*2.	Написать функцию, реализующую алгоритм 
					линейного поиска заданного ключа в одномерном массиве.*/
				int size = sizeOfArr();
				arrFilling(size, &task);
			} break;

			case 3:
			{
				/*3.	Написать функцию, реализующую алгоритм бинарного поиска заданного ключа в одномерном массиве.*/
				int size = sizeOfArr();
				arrFilling(size, &task);
			} break;

			case 4:
			{
				/*4.	Написать игру «Быки и коровы».Программа "загадывает" четырёхзначное число и 
					играющий должен угадать его.После ввода пользователем числа программа сообщает,
					сколько цифр числа угадано(быки) и сколько цифр угадано и стоит на нужном месте(коровы).
					После отгадывания числа на экран необходимо вывести количество сделанных пользователем попыток.*/
				cout << "Давай сыграем в игру Быки и Коровы!!!\nПрограмма \"загадывает\" четырёхзначное число, а Вы должны угадать его" << endl;
				cout << "После ввода числа программа сообщит сколько цифр числа угадано(быки)\nИ сколько цифр угадано и стоит на нужном месте(коровы)." << endl;
				srand(time(NULL));
				int NumbOfGame = 1000 + rand() % 8999;
				int a = NumbOfGame / 1000;
				int d = NumbOfGame % 10;
				int c = (NumbOfGame % 100) / 10;
				int b = (NumbOfGame / 100) % 10;
				//cout << NumbOfGame << endl; 
				CowsAndBulls(&NumbOfGame, &a, &b, &c, &d);

			} break;
		}
	} while (task > 0);
	
}

void CowsAndBulls(int *NumbOfGame, int *a, int *b, int *c, int *d)
{
	
	int m[4] = { *a, *b, *c, *d }, cow = 0, bull = 0, count = 0, numb, a2, b2, c2, d2;
	do
	{	
		cow = 0;
		bull = 0;
		count++;
		cout << "Введите число - ";
		cin >> numb;
		a2 = numb / 1000;
		d2 = numb % 10;
		c2 = (numb % 100) / 10;
		b2 = (numb / 100) % 10;
		int m2[4] = { a2, b2, c2, d2 };
		for (int i = 0; i < 4; i++)
		{	
			if (m[i] == m2[i])
				cow++;
			for (int j = 0; j < 4; j++)
			{
				if (m[i] == m2[j])
					bull++;
			}
		}
		cout << "Кол-во быков - " << bull << "\nКол-во коров - " << cow << endl;

	} while (numb != *NumbOfGame);
	cout << "Кол-во попыток было - " << count << endl;

}

int sizeOfArr()
{	
	int size;
	do
	{
		cout << "Введите размерность массива в диапозоне от 1 до 50 - ";
		cin >> size;
	} while (size < 1 || size > 50);
	return size;
}

void arrFilling(int size, int *task)
{	
	srand(time(0));
	int arr[50];
	for (int i = 0; i < size; i++)
	{
		arr[i] = -100 + rand() % 200;
		cout << arr[i] << endl;
	}
	if (*task == 2)
		NumbSearchArr(arr, size);
	if (*task == 3)
		BinNumbSearchArr(arr, size);
}

void NumbSearchArr(int *arr, int size)
{	
	
	int numb;
	cout << "Введите любое целое число - ";
	cin >> numb;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == numb)
		{
			cout << "ЕСТЬ ТАКОЕ ЧИСЛО!!!!" << endl;
			break;
		}
		else if(i == size - 1)
			cout << "НЕТ ТАКОГО ЧИСЛА!!!!" << endl;
	}
}

void BinNumbSearchArr(int*arr, int size)
{
	int temp, count = 0, numb;
	cout << "Введите любое целое число - ";
	cin >> numb;
	for (int i = 0; i < size; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (arr[j - 1] > arr[j])
			{
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	} for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}

	int left = 0;
	int right = size - 1;
	int isSeatch = -1;

	while (left <= right)
	{
		count++;
		int mid = (left + right) / 2;
		if (numb == arr[mid])
		{
			isSeatch = mid;
			break;
		}

		if (numb < arr[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}

	if (isSeatch == -1)
		cout << "Элемент не найден!!" << endl;
	else 
		cout << " arr[" << isSeatch << "]=" << arr[isSeatch] << " найден за " << count << " проходов" << endl;
	cout << endl;
}

void SimpleNumb(int *a)
{
	if (*a % *a == 0 && *a % 1 == 0)
		cout << "Число " << *a << " простое число" << endl;
	else
		cout << "Число " << *a << " НЕпростое число" << endl;
}


void NumbSearch(int m, int size, int *a)
{
	for (int i = 0; i < size; i++)
	{
		if (m[&i] == *a)
		{
			cout << "Число " << *a << " было найдено с " << i << " попытки" << endl;
			break;
		}
	}
	cout << "Число " << *a << " НЕ было найдено" << endl;
}

