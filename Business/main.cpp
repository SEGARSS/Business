#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

/*list // вывести текущий список дел
умыться
выгулять собаку

insert // добавляет дело
Введите дело: сходить в магазин
Добавлено.
list 
умыться
выгулять собаку
сходить в магазин

done // удалить из списка дел
Введите номер дела: 1
Выполнено. 


list
выгулять собаку
сходить в магазин
clear // удалить все дела
Очищено. 

sort // отсортировать дела по алфавиту
Готово.*/

int main()
{
	setlocale(LC_ALL, "ru");

	std::vector <std::string> business;

	std::string history_name = "history.txt";
	std::string sprav = "sprav.txt";

	//чтение
	std::ifstream i_sprav(sprav);
	if (i_sprav.is_open())
	{
		while(!i_sprav.eof()) // Пока не дошли до конца файл цикл работает.
		{
			std::string business_;
			std::getline(i_sprav, business_);

			//Чтоб пустые строчки не шли в расчёт.
			if (business_.empty()) // empty - пустой. Если пусто, то продолжаем дальше(пропускаем).
			{
				continue;
			}

			business.push_back(business_);
		}
	}
	i_sprav.close();

	while (true)
	{
		std::string cod;

		std::cout << "Введите команду: - ";
		std::cin >> cod;
		std::cin.ignore();

		if (cod == "insert")
		{
			std::cout << "Введите дело: - ";
			std::string delo;
			std::getline(std::cin, delo);

			business.push_back(delo);
			std::cout << "Дело добавлено." << std::endl;
		}
		else if(cod == "list")
		{
			for (int i = 0; i < business.size(); i++)
			{
				std::cout << i + 1 << " " << business[i] << std::endl;
			}
		}
		else if (cod == "delete")
		{
			std::cout << "Введите дело: - ";
			int delo;
			std::cin >> delo;

			business.erase(business.begin() + (delo - 1));//-1 - так ка при создании прибавляем +1.
			std::cout << "delete - удаленно дело.";
		}
		else if (cod == "clear")
		{
			business.clear();
			std::cout << "Список очищен.";
		}
		else if (cod == "sort")
		{
			std::sort(business.begin(), business.end());
			std::cout << "sort - Список отсортирован по алфавиту.\n";
		}
		else if (cod == "exit")
		{
			std::cout << "Выход из программы.";
			break;
		}
		else
		{
			std::cout << "Неверная команда!\n";
		}
	}

	//Запись
	std::ofstream o_sprav(sprav);
	for (auto &info : business)
	{
		o_sprav << info << std::endl;
	}
	o_sprav.close();

	return 0;
}