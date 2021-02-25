#include <conio.h>
#include <iostream>
#include <fstream>

using namespace std;

#define N 8
#define INF 999999
#define INF2 0

int read_matrix(int matr[N][N]) {
	ifstream in("matrix.txt");
	if (in.is_open())
	{
		//Считаем матрицу из файла
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				in >> matr[i][j];

		//Выведем матрицу
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
				cout << matr[i][j] << "\t";
			cout << "\n";
		}

		in.close();//под конец закроем файла
		return **matr;
	}
	else
	{
		//Если открытие файла прошло не успешно
		cout << "Файл не знайдено.";
		return 0;
	}
}

int min_tree(int matr[N][N]) {
	cout << endl << "---------------------------------------------------------------" << endl;
	cout << "Пошук МIНIмального остового дерева за алгоритмом Прима" << endl;
	int weight = 0;
	int no_edge = 0;            // кількість ребер, встановлення номера ребра = 0
	int selected[N];            // створюємо масив для відстеження вибраної вершини, вибране стане істинним, інакше помилково
	int x;            //  к-ть рядків
	int y;            //  к-ть колонок
	
	memset(selected, false, sizeof(selected)); // встановити вибране false спочатку
	selected[0] = true; // вибираємо 0-ю вершину і робимо це true

	cout << " Ребро" << " : " << "Вага";
	cout << endl;
	while (no_edge < N - 1) { // число ребра в мінімальному прольотному дереві буде завжди менше (N -1), де N - кількість вершин у графі
	// Для кожної вершини множини S знаходимо всі сусідні вершини, обчислимо відстань від вершини, вибраної на кроці 1. 
	// Якщо вершина вже є в наборі S, відкиньте її інакше вибираємо іншу вершину, найближчу до вибраної вершини на кроці 1.
		int min = INF;
		x = 0;
		y = 0;

		for (int i = 0; i < N; i++) {
			if (selected[i]) {
				for (int j = 0; j < N; j++) {
					if (!selected[j] && matr[i][j]) { // не у вибраному, і є ребро
						if (min > matr[i][j]) {
							min = matr[i][j];
							x = i;
							y = j;
						}
					}
				}
			}
		}
		cout << " " << x << " - " << y << " :  " << matr[x][y] << endl;
		weight += matr[x][y];
		selected[y] = true;
		no_edge++;
	}
	cout << "Сумарна вага: " << weight << endl;
	cout << "---------------------------------------------------------------" << endl;	
	return 0;
}

int max_tree(int matr[N][N]) {
	cout << "Пошук МАКСИмального остового дерева за алгоритмом Прима" << endl;
	int weight = 0;
	int no_edge = 0;            
	int selected[N];
	int x;           
	int y;            

	memset(selected, false, sizeof(selected));

	selected[0] = true;

	cout << " Ребро" << " : " << "Вага";
	cout << endl;
	while (no_edge < N - 1) {
		int max = INF2;
		x = 0;
		y = 0;

		for (int i = 0; i < N; i++) {
			if (selected[i]) {
				for (int j = 0; j < N; j++) {
					if (!selected[j] && matr[i][j]) { 
						if (max < matr[i][j]) {
							max = matr[i][j];
							x = i;
							y = j;
						}
					}
				}
			}
		}
		cout << " " << x << " - " << y << " :  " << matr[x][y] << endl;
		weight += matr[x][y];
		selected[y] = true;
		no_edge++;
	}
	cout << "Сумарна вага: " << weight << endl;
	cout << "---------------------------------------------------------------" << endl;

	return 0;
}

void main()
{
	setlocale(LC_ALL, "Ukrainian");
	int matr[N][N];

	cout << "Кiлькiсть вершин: " << N << endl;
	cout << "Матриця ваг: " << endl;
	read_matrix(matr);
	min_tree(matr);
	max_tree(matr);

	system("pause");
}