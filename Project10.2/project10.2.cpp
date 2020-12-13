#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void PrintTXT(char* fname) // виведення файлу на екран
{
	ifstream fin("t1.txt"); // відкрили файл для зчитування
	string s; // прочитаний рядок
	while (getline(fin, s)) // поки можна прочитати рядок
	{
		cout << s << endl; // виводимо його на екран
	}
	cout << endl;
}
bool Condition(char sym, char previous_sym)
{
	if (sym == ' ' && previous_sym == '.')
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Change(char* sym, bool* condition)
{
	if (*sym == ' ')
	{
		// залишаємо без змін для наступного символу
	}
	else if ((*sym >= 'a' && *sym <= 'z') || (*sym >= 'а' && *sym <= 'я'))
	{
		*sym = toupper(*sym);
		*condition = false;
	}
	else
	{
		*condition = false;
	}
}
void ProcessTXT2(char* fname, char* tname) // обчислення кількості слів,
{ // відокремлених пробілами
	ifstream fin("t1.txt"); // відкрили файл для зчитування
	ofstream fout("t2.txt");
	char sym; // прочитаний рядок
	char previous_sym = NULL;
	bool condition = false;
	while (fin.get(sym)) // поки можна прочитати символ
	{
        if(condition == false)
		{
			condition = Condition(sym, previous_sym);
			previous_sym = sym;
		}
		else
		{
			Change(&sym, &condition);
		}
			fout << sym; // записать sym => fout
	}
	cout << "Copy result: OK!" << endl;
	fin.close(); // закрыть оба файла
	fout.close();
}
void PrintTXT2(char* tname) // виведення файлу на екран
{
	ifstream fin("t2.txt"); // відкрили файл для зчитування
	string s; // прочитаний рядок
	while (getline(fin, s)) // поки можна прочитати рядок
	{
		cout << s << endl; // виводимо його на екран
	}
	cout << endl;
}
int main()
{
	// text files
	char fname[100]; // ім'я першого файлу
	char tname[100];
	PrintTXT(fname); // вивели вміст першого файлу на екран
	ProcessTXT2(fname, tname);
	PrintTXT2(tname);
	return 0;
}