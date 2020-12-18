#include <iostream>
#include <Windows.h>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;

typedef int inform;
struct Spusok
{
	Spusok* link1,
		* link2;
	inform inf;
};

int Start(ifstream& file_load, Spusok*& first, Spusok*& last);
void Print(Spusok*& first, Spusok*& T, const int N);
void Process(Spusok*& top1, Spusok* T, Spusok* G, const int N);

int main(void)
{
	srand((unsigned)time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Spusok* first = NULL;
	Spusok* last = NULL;

	char fname[51];
	cout << "Введіть назву файлу для зчитування чисел: "; cin >> fname; cout << endl;

	int kilkist;
	inform value;

	ifstream file_load;
	file_load.open(fname);
	kilkist = Start(file_load, first, last);
	file_load.close();

	cout << "Сформований список за допомогою зчитування з текстового файлу: " << endl << endl;
	Spusok* T = first;
	Print(first, T, kilkist);

	cout << "Сформований стек 'після перетворення': " << endl << endl;
	T = first;
	Spusok* G = first;
	Process(first, T, G, kilkist);

	T = first;
	Print(first, T, kilkist);

	return 0;
}

int Start(ifstream& file_load, Spusok*& first, Spusok*& last)
{
	inform i;
	int kilkist = 0;

	while (!file_load.eof())
	{
		file_load >> i;
		Spusok* tmp = new Spusok;
		tmp->inf = i;
		tmp->link1 = NULL;
		tmp->link2 = NULL;
		if (first == NULL)
			first = tmp;
		else
		{
			last->link1 = tmp;
			tmp->link2 = last;
		}
		last = tmp;
		kilkist++;
	}
	return kilkist;
}

void Print(Spusok*& first, Spusok*& T, const int N)
{
	inform i;
	int index = 0;

	while (index < N)
	{
		i = T->inf;
		cout << i << "   ";
		T = T->link1;
		index++;
	}
	cout << endl << endl;
}

void Process(Spusok*& top1, Spusok* T, Spusok* G, const int N)
{
	inform x, y;
	int zmina, zmina_l = 1;       // 0(оголошення двох змінних)
	inform min_x;

	for (int i = 0; i < N; i++)
	{
		x = G->inf;               // 1(змінна 'x' отримає значення від елемента(інформаційного поля))
		min_x = x;                // 2(вважаємо що значення 'x' є максимальним ---> 'max_x')

		zmina = 0;                // 3('zmina' отримує значення 0)
		while (zmina < zmina_l)
		{
			T = T->link1;         // 4(вказівник 'T' переходить на нову позицію)
			zmina++;              // 5('zmina' змінює своє значення)
		}

		while (T != NULL)
		{
			x = T->inf;           // 6(змінна 'x' отримує значення елемента стека)
			if (min_x > x)
				min_x = x;        // 7(змінна 'max_x' отримує нового, більшого значення за попереднє від змінної 'x')
			T = T->link1;         // 8(вказівник 'T' переходить на нову позицію елемента стеку)
		}

		T = top1;                 // 9(вказівник 'T' отримує адрусу вказівника 'top')
		x = G->inf;               // 10(змінна 'x' отримую значення елемента стеку)

		zmina = 0;                // 11('zmina' отримує значення 0)
		while (zmina < zmina_l)
		{
			T = T->link1;         // 12(вказівник 'T' переходить на нову позицію)
			zmina++;              // 13('zmina' змінює своє значення)
		}

		while (T != NULL)
		{
			y = T->inf;           // 14(змінна 'y' отримує значення від елемента стеку)
			if (y == min_x)
			{
				G->inf = min_x;   // 15(елемент отримує значення більшого елемента)
				T->inf = x;       // 16(а позиція більшого елемента замінюється значення елемнта поточної позиції(елемнта на який вказує вказівник 'G'))

				break;
			}
			T = T->link1;         // 17(вказівник 'T' переходить на нову позицію)
		}

		zmina_l++;                // 18(змінна 'zmina_l' збільшує своє значення на одиницю)

		T = top1;                 // 19(вказівник 'T' отримує значення адреси яке містить вказівник 'top1')
		G = G->link1;             // 20(вказівник 'G' переходить на нову позицію)
	}
}