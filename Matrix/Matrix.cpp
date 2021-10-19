/*Задание 1. Написать функцию, добавляющую столбец
двухмерному массиву в указанную позицию.

Задание 2. Написать функцию, удаляющую столбец двух-
мерного массива по указанному номеру.

Задание 3. Дана матрица порядка M×N (M строк, N столб-
цов). Необходимо заполнить ее значениями и написать
функцию, осуществляющую циклический сдвиг строк
и/или столбцов массива указанное количество раз и в ука-
занную сторону.*/
#include <iostream>
#include<Windows.h>
#include<time.h>
#include <stdlib.h>

using namespace std;

void RandArray(int Array[], int SIZE, int begin, int end)//Заполнение масива случайными числами
{
    for (size_t i = 0; i < SIZE; i++)
        Array[i] = rand() % (end - begin + 1) + begin;
}

void PrintArray(const int array[], size_t size)
{
    for (size_t i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}


void AddArray(int** array, size_t* length, size_t position, int element)
{
    ++(*length);
    int* arr = *array;
    int* tmp = new int[*length];
    size_t j = 0;
    for (size_t i = 0; i < *length; i++)
    {
        if (i == position - 1)
        {
            tmp[i] = element;
            j--;
        }
        else
            tmp[i] = (*array)[j];
        ++j;
    }

    *array = tmp;
    tmp = arr;
    delete[] tmp;
}

void DelArray(int** array, size_t* length, size_t position)
{
    (*length)--;
    int* arr = *array;
    int* tmp = new int[*length];
    size_t j = 0;
    for (size_t i = 0; i < *length; i++)
    {
        if (i == position - 1)
        {
            j++;
        }
        tmp[i] = (*array)[j];
        ++j;
    }

    *array = tmp;
    tmp = arr;
    delete[] tmp;
}

void AddMatrixRown(int** matrix, size_t* rowns, size_t columns, size_t position)
{
    int* arr = new int[columns];
    AddArray(matrix, rowns, position, *arr);
}


void ShiftArray(int** array, size_t length, int Shift)
{
    int shift = Shift / length <= 1 ? Shift % length : Shift;
    int tmp0;
    if (shift >= 0)
    {
        for (size_t i = 0; i < shift; i++)
        {
            tmp0 = (*array)[length - 1];
            for (size_t j = 0; j < length; j++)
            {
                int tmp = (*array)[j];
                (*array)[j] = tmp0;
                tmp0 = tmp;
            }
        }
    }
    else
    {
        shift = shift * (-1);
        int tmp;
        for (size_t i = 0; i < shift; i++)
        {
            int tmp = (*array)[0];
            for (size_t j = 0; j < length - 1; j++)
            {
                (*array)[j] = (*array)[j + 1];
            }
            (*array)[length - 1] = tmp;
        }
    }
}

void PrintMatrix(int** matrix, size_t rows, size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            cout << matrix[i][j] << " ";

        }
        cout << endl;
    }
    cout << endl;
}

void RandMatrix(int** Matrix, size_t rows, size_t columns, int begin, int end)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            Matrix[i][j] = rand() % (end - begin + 1) + begin;

        }
    }
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    size_t rows;
    cout << "Введите колличество строк матрицы: ";
    cin >> rows;
    size_t columns;
    cout << "Введите колличество столбцов матрицы: ";
    cin >> columns;
    int** matrix = new int* [rows];
    for (size_t i = 0; i < rows; i++)
        matrix[i] = new int[columns];
    int end;
    int begin;
    cout << "Введите начало и конец заполняемого диапазона чисел лля матрицы : ";
    cin >> begin;
    cin >> end;

    RandMatrix(matrix, rows, columns, begin, end);
    PrintMatrix(matrix, rows, columns);
    PrintArray(*matrix, rows);

    //AddMatrixRown(matrix, &rows, columns, 2);
    PrintMatrix(matrix, rows, columns);


    for (size_t i = 0; i < rows; i++)
        delete matrix[i];
    delete[] matrix;
    return 0;
}