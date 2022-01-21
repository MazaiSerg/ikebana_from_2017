#include "Game.h"
using namespace std;

int start_game[]={3,3,3,3,3};
string ikebana[]={"Красных","Желтых","Синих","Зеленых","Фиолетовых"," цветков: ","В икебане сейчас:"};
string color[]={"Красные","Желтые","Синие","Зеленые","Фиолетовые","красный","желтый",
				"синий","зеленый","фмолетовый","цветок"};

#define NUMBER_COLOR 5

void out_data()
{
	cout<<ikebana[NUMBER_COLOR+1]<<endl;
	for(int i=0;i<5;i++)
		cout<<ikebana[i]<<ikebana[NUMBER_COLOR]<<3-start_game[i]<<endl;
}

bool game_end()
{
	bool result=true;
	for(int i=0;i<NUMBER_COLOR;i++)
		if(start_game[i]!=0)
			result=false;
	return result;
}

int choose_color()
{
	char ch;
	for(;;)
	{
		out_data();
		cout<<"Введите номер строки с типом цветов, которые Вы хотите добавить"<<endl;
		cin>>ch;;
		if(ch>='1' && ch<=NUMBER_COLOR+'1')
		{
			if(start_game[ch-'1']==0)
			{
				cout<<"Использованы все цветы, выбранного типа."<<endl;
				system("pause");
				system("cls");
				continue;
			}
			else
				break;
		}
		system("cls");
		cout<<"Неверный ввод"<<endl;
		system("cls");
	}
	return ch-'1';
}

int choose_count(int col)
{
	char ch;
	for(;;)
	{
		system("cls");
		out_data();
		cout<<"Введите количество цветов, которое Вы хотите добавить (Текущие цветы: "<<color[col]<<")."<<endl;
		cout<<"Введите 0, чтобы поменять тип цветов"<<endl;
		cin>>ch;;
		if(ch>='0' && ch<='9')
		{
			if(start_game[col]-ch+'0'<0)
			{
				cout<<"Невозможно добавить выбранное количество цветов."<<endl;
				system("pause"); 
				system("cls");
				continue;
			}
			else
				break;
		}
		system("cls");
		cout<<"Неверный ввод"<<endl;
		system("cls");
	}
	return ch-'0';
}

void AI_move(int difficult)
{
	cout<<endl;
	const int l=55;
	int counter=0;
	int memory[l][3];
	
	for(int k=1;k<=difficult;k++)
	{
		int arr[3],a[3];
		for(int i=0;i<3;i++)
			arr[i]=0;
		for(;;)
		{
			arr[0]++;
			for(int i=0;i<2;i++)
				if(arr[i]>k)
				{
					arr[i]=0;
					arr[i+1]++;
				}
			if(arr[2]>k)
				break;
			int sum=0;
			for(int i=0;i<3;i++)
				sum+=arr[i];
			if(sum!=k)
				continue;
			else
			{
				bool flag=true;
				if(k!=1)
				{
					flag=false;
					for(int i=0;i<6;i++)
					{
						bool correct=true;
						switch(i)
						{
						case 0:
							if(arr[0]==0)
							{
								correct=false;
								break;
							}
							a[0]=arr[0]-1;
							a[1]=arr[1];
							a[2]=arr[2];
							break;
						case 1:
							if(arr[1]==0)
							{
								correct=false;
								break;
							}
							a[0]=arr[0];
							a[1]=arr[1]-1;
							a[2]=arr[2];
							break;
						case 2:
							if(arr[2]==0)
							{
								correct=false;
								break;
							}
							a[0]=arr[0];
							a[1]=arr[1];
							a[2]=arr[2]-1;
							break;
						case 3:
							if(arr[1]==0)
							{
								correct=false;
								break;
							}
							a[0]=arr[0]+1;
							a[1]=arr[1]-1;
							a[2]=arr[2];
							break;
						case 4:
							if(arr[2]==0)
							{
								correct=false;
								break;
							}
							a[0]=arr[0];
							a[1]=arr[1]+1;
							a[2]=arr[2]-1;
							break;
						case 5:
							if(arr[2]==0)
							{
								correct=false;
								break;
							}
							a[0]=arr[0]+1;
							a[1]=arr[1];
							a[2]=arr[2]-1;
							break;
						default:
							break;
						}
						
						if(correct)
						{
							bool flag2=true;
							for(int j=0;j<counter;j++)
							{
								int sum=0;
								for(int d=0;d<3;d++)
									if(a[d]==memory[j][d])
										sum++;
								if(sum==3)
								{
									flag2=false;
									break;
								}
							}
							if(flag2)
							{
								flag=true;
								break;
							}
						}
					}
				}
				if(flag)
				{
					for(int i=0;i<3;i++)
						memory[counter][i]=arr[i];
					counter++;
				}
			}
			
		}
	}
	
	int possition[3];
	for(int i=0;i<3;i++)
		possition[i]=0;
	for(int i=0;i<NUMBER_COLOR;i++)
		if(start_game[i]>0)
			possition[start_game[i]-1]++;

	int turn=-1;
	for(int i=0;i<6;i++)
	{
		int a[3];
		bool correct=true;
		switch(i)
		{
		case 0:
			if(possition[0]==0)
			{
				correct=false;
				break;
			}
			a[0]=possition[0]-1;
			a[1]=possition[1];
			a[2]=possition[2];
			break;
		case 1:
			if(possition[1]==0)
			{
				correct=false;
				break;
			}
			a[0]=possition[0];
			a[1]=possition[1]-1;
			a[2]=possition[2];
			break;
		case 2:
			if(possition[2]==0)
			{
				correct=false;
				break;
			}
			a[0]=possition[0];
			a[1]=possition[1];
			a[2]=possition[2]-1;
			break;
		case 3:
			if(possition[1]==0)
			{
				correct=false;
				break;
			}
			a[0]=possition[0]+1;
			a[1]=possition[1]-1;
			a[2]=possition[2];
			break;
		case 4:
			if(possition[2]==0)
			{
				correct=false;
				break;
			}
			a[0]=possition[0];
			a[1]=possition[1]+1;
			a[2]=possition[2]-1;
			break;
		case 5:
			if(possition[2]==0)
			{
				correct=false;
				break;
			}
			a[0]=possition[0]+1;
			a[1]=possition[1];
			a[2]=possition[2]-1;
			break;
		default:
			break;
		}
		
		if(correct)
		{
			bool flag=true;
			for(int j=0;j<counter;j++)
			{
				int sum=0;
				for(int d=0;d<3;d++)
					if(a[d]==memory[j][d])
						sum++;
				if(sum==3)
				{
					flag=false;
					break;
				}
			}
			if(flag)
			{
				turn=i;
				break;
			}
		}
	}
	
	if(turn<0)
	{
		int max=0;
		for(int i=0;i<NUMBER_COLOR;i++)
			if(start_game[max]<start_game[i])
				max=i;
		start_game[max]--;
		cout<<"Компьютер добавил к икебане 1 "<<color[NUMBER_COLOR+max]<<" "<<color[2*NUMBER_COLOR]<<"."<<endl;
	}
	else
	{
		int max=0;
		switch(turn)
		{
		case 0:
			for(int i=0;i<NUMBER_COLOR;i++)
				if(1==start_game[i])
					max=i;
			start_game[max]--;
			cout<<"Компьютер добавил к икебане 1 "<<color[NUMBER_COLOR+max]<<" "<<color[2*NUMBER_COLOR]<<"."<<endl;
			break;
		case 1:
			for(int i=0;i<NUMBER_COLOR;i++)
				if(2==start_game[i])
					max=i;
			start_game[max]-=2;
			cout<<"Компьютер добавил к икебане 2 "<<color[max]<<" цветка."<<endl;
			break;
		case 2:
			for(int i=0;i<NUMBER_COLOR;i++)
				if(3==start_game[i])
					max=i;
			start_game[max]-=3;
			cout<<"Компьютер добавил к икебане 3 "<<color[max]<<" цветка."<<endl;
			break;
		case 3:
			for(int i=0;i<NUMBER_COLOR;i++)
				if(2==start_game[i])
					max=i;
			start_game[max]--;
			cout<<"Компьютер добавил к икебане 1 "<<color[NUMBER_COLOR+max]<<" "<<color[2*NUMBER_COLOR]<<"."<<endl;
			break;
		case 4:
			for(int i=0;i<NUMBER_COLOR;i++)
				if(3==start_game[i])
					max=i;
			start_game[max]--;
			cout<<"Компьютер добавил к икебане 1 "<<color[NUMBER_COLOR+max]<<" "<<color[2*NUMBER_COLOR]<<"."<<endl;
			break;
		default:
			for(int i=0;i<NUMBER_COLOR;i++)
				if(3==start_game[i])
					max=i;
			start_game[max]-=2;
			cout<<"Компьютер добавил к икебане 2 "<<color[max]<<" цветка."<<endl;
			break;
		}
	}
	cout<<endl;
} 

void Play(int difficult,int turn)
{
	system("cls");
	for(int i=0;i<NUMBER_COLOR;i++)
		start_game[i]=3;
	bool now_turn;
	switch (turn)
	{
	case -1:
		now_turn=true;
		break;
	case 0:
		now_turn=false;
		break;
	default:
		srand(time(0));
		now_turn=(rand()%2)==0;
		break;
	}
	while(!game_end())
	{
		system("cls");
		if(now_turn)
		{
			int k,l;
			for(;;)
			{
				k=choose_color();
				l=choose_count(k);
				if(l!=0)
					break;
			}
			start_game[k]-=l;
			now_turn=!now_turn;
		}
		else
		{
			system("cls");
			out_data();
			AI_move(difficult);
			system("pause");
			system("cls");
			now_turn=!now_turn; 
		}		
	}	
	system("cls");
	if(now_turn)
		cout<<"Ксожалению, Вы проиграли"<<endl;
	else
		cout<<"Поздравляем с заслуженной победой!"<<endl;
	cout<<endl;
	system("pause");
}
