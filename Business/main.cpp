#include <iostream>
#include <vector>
#include <string>

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

	std::string cod;

	

	while (true)
	{
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
			std::string delo;
			std::getline(std::cin, delo);

			bool posk = false;

			for (int i = 0; i < business.size(); i++)
			{
				if (business[i] == delo)
				{
					business[i].erase(+1);
					std::cout << "Удаленно дело. " << business[i].erase() << std::endl;
					posk = true;
				}				
			}				
			
			if (posk == false)
			{
				std::cout << "Такова дела нет." << std::endl;
			}

		}
		else
		{
			std::cout << "Неверная команда!\n";
		}
	}


	return 0;
}