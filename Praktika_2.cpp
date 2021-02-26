#include <iostream>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include <conio.h>


using namespace std;

void SetColor(int text, int background)
{
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

struct Player
{
	string name;
	int HP;
	int udar;
	int cell;
};


void nPlayer(Player &p)
{
	cout << "Введи своё имя боец" << endl;
	SetColor(2,0);
	cin >> p.name;
	p.HP = 10;
}

void nBot(Player &bot)
{
	SetColor(14,0);
	cout << "Введи имя своего опонента" << endl;
	SetColor(4,0);
	cin >> bot.name;
	bot.HP = 10;
}


bool cheatName(Player p)
{
	if (p.name == "Хабиб" || p.name == "хабиб")
		return true;
	else 
		return false;
}

bool cheatGOD(Player p)
{
	if (p.name == "god000" )
		return true;
	else 
		return false;		
}


void hodPlayer (Player &p, Player &bot)
{
	int d;
	srand(time(NULL));
	cout << "Ударь своего опонента!" << endl;
	do
	d = getch();
	while (d != 75 && d != 77 && d != 72 && d != 80);
	switch (d)
	{
		case 75: p.udar = 1;
		break;
		case 77: p.udar = 2;
		break;
		case 72: p.udar = 3;
		break;
		case 80: p.udar = 4;
		break;
	}
	p.cell = rand() % (12 + 1);
	if (p.cell < 5)
	{
		cout << "Ты бьёшь опонента, но промахиваешься" << endl;
		SetColor(15,0);
		cout << "Твои HP: " << p.HP << ", HP опонента: " << bot.HP << endl;
	}
	else if ((p.cell >= 5 && p.cell <= 8))
		if (p.udar == 1 || p.udar == 2)
		{
			if (p.udar == 1)
			{
				cout << "Ты бьёшь опонента левой рукой" << endl;
				bot.HP -= p.udar;
			}
			else
			{
				cout << "Ты бьёшь опонента правой рукой" << endl;
				bot.HP -= p.udar;
			}
		SetColor(15,0);
		cout << "Твои HP: " << p.HP << ", HP опонента: " << bot.HP << endl;
		}
		else
			cout << "Ты не можешь ударить ногой или поставить блок" << endl;
	else if ((p.cell >=9) && (p.cell <= 11))
		{
			if (p.udar == 1)
			{
				cout << "Ты бьёшь опонента левой рукой" << endl;
				bot.HP -= p.udar;
			}
			else if (p.udar == 2)
			{
				cout << "Ты бьёшь опонента правой рукой" << endl;
				bot.HP -= p.udar;
			}
			else if (p.udar == 3)
			{
				cout << "Ты бьёшь опонента ногой" << endl;
				bot.HP -= p.udar;
			}
			else
				cout << "Ты поставил блок" << endl;
		SetColor(15,0);
		cout << "Твои HP: " << p.HP << ", HP опонента: " << bot.HP << endl;
		}
	else if (p.cell == 12)
	{
		cout << "У тебя критический удар";
		if (p.udar == 1)
		{
			 cout << " левой рукой" << endl;
			 bot.HP -= p.udar + 1;
		}
		else if (p.udar == 2)
		{
			cout << " правой рукой" << endl;
			bot.HP -= p.udar + 1;
		}
		else if (p.udar == 3)
		{
			cout << " ногой" << endl;
			bot.HP -= p.udar + 1;
		}
	cout << "Твои HP: " << p.HP << ", HP опонента: " << bot.HP << endl;
	}
	else if (p.cell == 12 && bot.udar == 4)
	{
		cout << "Опонент поставил блок, но твой критический удар пробивает его!!" << endl;
		bot.HP -=p.udar;
		SetColor(15,0);
		cout << "Твои HP: " << p.HP << ", HP опонента: " << bot.HP << endl;
	}	
}

void hodBot (Player &bot, Player &p)
{
	srand(time(NULL));
	cout << bot.name <<" бьёт тебя!" << endl;
	bot.udar = rand() % (4 + 1);
	bot.cell = rand() % (12 + 1); 
	if (bot.cell < 5)
	{
		cout << "Опонент бьёт тебя, но промахивается" << endl;
		SetColor(15,0);
		cout << "Твои HP: " << p.HP << ", HP опонента: " << bot.HP << endl;
	}
	else if ((bot.cell >= 5 && bot.cell <= 8))
		if (bot.udar == 1 || bot.udar == 2)
		{
			if (bot.udar == 1)
			{
				cout << "Опонент бьёт тебя левой рукой" << endl;
				p.HP -= bot.udar;
			}
			else
			{
				cout << "Опонент бьёт тебя правой рукой" << endl;
				p.HP -= bot.udar;
			}
		SetColor(15,0);
		cout << "Твои HP: " << p.HP << ", HP опонента: " << bot.HP << endl;
		}
		else
			cout << "Опонент не может ударить ногой или поставить блок" << endl;
	else if ((bot.cell >=9) && (bot.cell <= 11))
		{
			if (bot.udar == 1)
			{
				cout << "Опонент бьёт тебя левой рукой" << endl;
				p.HP -= bot.udar;
			}
			else if (bot.udar == 2)
			{
				cout << "Опонент бьёт правой рукой" << endl;
				p.HP -= bot.udar;
			}
			else if (bot.udar == 3)
			{
				cout << "Опонент бьёт ногой" << endl;
				p.HP -= bot.udar;
			}
			else
				cout << "Опонент поставил блок" << endl;
		SetColor(15,0);
		cout << "Твои HP: " << p.HP << ", HP опонента: " << bot.HP << endl;
		}
	else if (bot.cell == 12)
	{
		if (bot.udar == 1)
		{
			 cout << "У опонента критический удар левой рукой" << endl;
			 p.HP -= bot.udar + 1;
		}
		else if (bot.udar == 2)
		{
			cout << "У опонента критический удар правой рукой" << endl;
			p.HP -= bot.udar + 1;
		}
		else if (bot.udar == 3)
		{
			cout << "У опонента критический удар ногой" << endl;
			p.HP -= bot.udar + 1;
		}
	SetColor(15,0);
	cout << "Твои HP: " << p.HP << ", HP опонента: " << bot.HP << endl;
	}
	else if (bot.cell == 12 && p.udar == 4)
	{
		cout << "Ты поставил блок, но критический удар опонента пробивает его!!" << endl;
		p.HP -=bot.udar;
		SetColor(15,0);
		cout << "Твои HP: " << p.HP << ", HP опонента: " << bot.HP << endl;
	}	
}


void pobeda()
{
	string s;
	ifstream f1("pobeda.txt");
	while (!f1.eof())
	{
		getline(f1,s);
		cout << s << endl;
	}
	f1.close();
}

bool checkPobeditel (Player &p, Player &bot)
{
	if (p.HP <= 0)
	{
		SetColor(4,0);
		cout << "Вы проиграли";
		for (int i = 1; i <= 3; i++)
			cout << endl;
		pobeda();
		return false;
	}
	else if (bot.HP <= 0)
	{
		SetColor(2,0);
		cout << "Опонент повержен!!!";
		for (int i = 1; i <= 3; i++)
			cout << endl;
		pobeda();
		return false;
	}
	else 
		return true;
}

void pravila()
{
	string s;
	ifstream f("pravila boec.txt");
	while (!f.eof())
	{
		getline(f,s);
		cout << s << endl;
	}
	f.close();
}





int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Player p;
	Player bot;
	SetColor(15,0);
	cout << "Вас приветствует консольная игра 'Боец'" << endl;
	cout << "Нажмите пробел - для просмотра правил, чтобы начать игру нажмите любую другую кнопку" << endl;
	SetColor(15,0);
	int a;
	SetColor(14,0);
	a = getche();
	if (a == 32)
	{
		pravila();
	}
	nPlayer(p);
	nBot(bot);
	cheatName(p);
	bool game = true;
	if (cheatName(p))
	{
		SetColor(2,0);
		cout << "Вы ввели чит-имя, вы победили." << endl;
	}
	else
	{
		SetColor(15,0);
		cout << "Бой начинается!!" << endl;
	}
	while (game)
	{	if (cheatGOD(p))
		{
			p.HP = 999999999;
			SetColor(2,0);
			cout << "Вы ввели чит-имя, активирован GOD-mode" << endl;
		}
		SetColor(2, 0);
		hodPlayer(p, bot);
		SetColor(4, 0);
		hodBot(bot,p);
		cout << endl;
		if (!checkPobeditel(p,bot))
			break;
	}
	SetColor(15,0);
}
