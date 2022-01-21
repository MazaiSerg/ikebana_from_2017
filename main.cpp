#include<iostream>
#include<string>
#include <stdlib.h>
#include "Game.h"
using namespace std;

#define ERROR_INPUT 3
#define Number_setting_menu 3
const int Number_menu=3;
string menu[]={"Играть","Настройка","Выход","Неверный ввод"};
int settings[]={5,1}; 

int main_menu();
int setting();
int choose_setting();
void set_dificalt();
void set_turn();

int main()
{
	system("cls");
	setlocale(LC_ALL, "Russian");
	int Number=0;
	for(;;)
	{
		Number=main_menu();
		switch(Number)
		{
		case 1:
			Play(settings[0],settings[1]);
			break;
		
		case 2:
			setting();
			break;
		default:
			break;
		}
		if (Number==Number_menu)
			break;
	}
	
	return 0;
}

int main_menu()
{
	char ch;
	for(;;)
	{
		for(int i=0;i<Number_menu;i++)
			cout<<i+1<<" "<<menu[i]<<endl;
		cin>>ch;;
		if(ch>='1' && ch<=Number_menu+1+'0')
			break;
		system("cls");
		cout<<menu[ERROR_INPUT]<<endl;
	}
	return ch-'0';
}

int choose_setting()
{
	system("cls");
	char ch;
	string setting_menu[]={"Сложность","Очередность ходов","Закончить.","(Текущая: "};
	for(;;)
	{
		cout<<1<<"."<<setting_menu[0]<<setting_menu[3]<<settings[0]<<")."<<endl;
		cout<<2<<"."<<setting_menu[0]<<setting_menu[3];
		switch (settings[1])
		{
		case -1:
			cout<<"Вы ходите первым";
			break;		
		case 0:
			cout<<"компьютер ходит первым";
			break;
		default:
			cout<<"очередность выбирается случайно";
			break;
		}
		cout<<")."<<endl;
		cout<<3<<"."<<setting_menu[2]<<endl;
		
		cin>>ch;;
		if(ch>='1' && ch<=Number_setting_menu+'0')
			break;
		system("cls");
		cout<<menu[ERROR_INPUT]<<endl;
	}
	return ch-'0';
}

void set_difficalt()
{
	system("cls");
	char ch;
	for(;;)
	{
		cout<<"Ведите новую сложность от 1 до 5 (текущая сложность: "<<settings[0]<<")."<<endl;
		
		cin>>ch;;
		if(ch>='1' && ch<='5')
			break;
		system("cls");
		cout<<menu[ERROR_INPUT]<<endl;;
	}
	settings[0]=ch-'0';
}	

void set_turn()
{
	system("cls");
	string turn[]={"Первым ходить будите Вы.","Первым ходить будет компьтер.",
		"Очередность ходов выбереться случайно","Текущая очередность ходов: "};
	char ch;
	for(;;)
	{
		for(int i=0;i<3;i++)
			cout<<i+1<<"."<<turn[i]<<endl;;
		cout<<turn[3];
		switch (settings[1])
		{
		case -1:
			cout<<"Вы ходите первым";
			break;		
		case 0:
			cout<<"компьютер ходит первым";
			break;
		default:
			cout<<"очередность выбирается случайно";
			break;
		}
		cout<<"."<<endl;
		
		cin>>ch;;
		if(ch>='1' && ch<='3')
			break;
		system("cls");
		cout<<menu[ERROR_INPUT]<<endl;
	}
	settings[1]=ch-'2';
}

int setting()
{
	int Number =0;
	while(true)
	{
		int Number=choose_setting();
		switch(Number)
		{
		case 1:
			set_difficalt();
			break;
			
		case 2:
			set_turn();
			break;
			
		default:
			Number=Number_setting_menu;
			break;
		}
		if (Number==Number_setting_menu)
			break;
	}
	return 0;
}
