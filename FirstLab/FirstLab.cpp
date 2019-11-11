// FirstLab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "Session.h"

#include <iostream>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	carNode* headNode = nullptr;
	carNode* B = 0; //Плохие оценки
	carLineUpNode* carLineUp = nullptr;
	carNode* search = 0;
	carNode* person = new carNode;
	carNode* bad = new carNode; // = new node;

	int menu_vibor, count_node = -1;
	bool flag = 0, error = 0;
	menu();
	while (true) {
		cout << "\n\nДальнейший выбор: ";
		cin >> menu_vibor;
		switch (menu_vibor) {
		case 1: // "1) Cоздание списка из n узлов"
			do {
				cout << "Введите число узлов: ";
				cin >> count_node;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(32000, '\n');
					cerr << "Число узлов должно быть числового формата \n Повторите ввод \n";
					error = true;
					continue;
				}
				if (count_node <= 0) {
					error = true;
					cout << "Введите число узлов больше 0: ";
				}
				else {
					error = false;
					createList(headNode, person, count_node);
				}
			} while (error);
			break;
		case 2: // 2) Вывод списка
			showList(headNode);
			break;
		case 3: // 2) Вывод списка
			formCarLineUp(headNode, carLineUp);
			break;
		case 4: // 2) Вывод списка
			formCarLineUp(headNode, carLineUp);
			deleteBrandCars(headNode, carLineUp);
			break;
			//case 3: // 3) Поиск узла с заданным значением
			//	search = search_node(L);
			//	if (search != nullptr) {
			//		cout << setw(15) << "№ Зачетки" << setw(15) << "№ группы" << setw(15) << "Оценка" << endl;
			//		/*cout << setw(15) << search->info.num_zach << setw(15) << search->info.num_group << setw(15) << search->info.mark << endl;*/
			//	}
			//	else
			//		cout << "Студента с такой зачеткой нет" << endl;
			//	break;
			//case 4: // 4) Вставить новый узел
			//	add_node_task(L, person);
			//	break;
			//case 5: // 5) Удалить узлы с указанным номером группы
			//	cout << "Введите номер группы для удаления" << endl;
			//	delete_node(L);
			//	show_list(L);
			//	break;
			//case 6: // 6) Сформировать новый список из исходного, включив в него узлы с оценкой неуд, исключив их при этом из исходного списка
			//	flag = 0;
			//	cr_list_BadMarks(L, B, bad, flag);
			//	cout << "Сдавшие экзамен" << endl;
			//	show_list(L);
			//	if (flag) {
			//		cout << "\nПересдача" << endl;
			//		show_list(B);
			//	}
			//	break;
		default: //Для выхода введите символ не равный номерам меню
			std::system("pause");
			return 0;
		}
	}
}
