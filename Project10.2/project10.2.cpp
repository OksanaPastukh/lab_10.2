#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void PrintTXT(char* fname) // ��������� ����� �� �����
{
	ifstream fin("t1.txt"); // ������� ���� ��� ����������
	string s; // ���������� �����
	while (getline(fin, s)) // ���� ����� ��������� �����
	{
		cout << s << endl; // �������� ���� �� �����
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
		// �������� ��� ��� ��� ���������� �������
	}
	else if ((*sym >= 'a' && *sym <= 'z') || (*sym >= '�' && *sym <= '�'))
	{
		*sym = toupper(*sym);
		*condition = false;
	}
	else
	{
		*condition = false;
	}
}
void ProcessTXT2(char* fname, char* tname) // ���������� ������� ���,
{ // ������������ ��������
	ifstream fin("t1.txt"); // ������� ���� ��� ����������
	ofstream fout("t2.txt");
	char sym; // ���������� �����
	char previous_sym = NULL;
	bool condition = false;
	while (fin.get(sym)) // ���� ����� ��������� ������
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
			fout << sym; // �������� sym => fout
	}
	cout << "Copy result: OK!" << endl;
	fin.close(); // ������� ��� �����
	fout.close();
}
void PrintTXT2(char* tname) // ��������� ����� �� �����
{
	ifstream fin("t2.txt"); // ������� ���� ��� ����������
	string s; // ���������� �����
	while (getline(fin, s)) // ���� ����� ��������� �����
	{
		cout << s << endl; // �������� ���� �� �����
	}
	cout << endl;
}
int main()
{
	// text files
	char fname[100]; // ��'� ������� �����
	char tname[100];
	PrintTXT(fname); // ������ ���� ������� ����� �� �����
	ProcessTXT2(fname, tname);
	PrintTXT2(tname);
	return 0;
}