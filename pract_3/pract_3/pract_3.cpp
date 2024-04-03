// var_5.cpp : 
#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

struct Date {
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

struct Record
{
	char name[17];
	char type[6];
	int area;
	unsigned short productivity;
	struct Date date;
	bool isEmpty;
};

struct node {
	Record data;
	struct node* next;
};
struct node* myHead;
int countItem = 0;

void myCentr(string s, int wLine) {

	int w = s.length();
	int delta = (wLine - w) / 2;
	cout << left;
	cout.width(delta); cout << " ";
	cout << s;
	cout.width(delta + 1); cout << " ";

}

void printDate(unsigned short day, unsigned short month, unsigned short year, int wLine) {
	int w = 10;
	int delta = (wLine - w) / 2 - 1;
	cout << left;
	cout.width(delta); cout << " ";
	if (day > 9) {
		cout << day;
	}
	else {
		cout << "0" << day;
	}
	cout << ".";
	if (month > 9) {
		cout << month;
	}
	else {
		cout << "0" << month;
	}
	cout << ".";
	cout << year;
	cout.width(delta); cout << " ";
}

void printWhithZero(int num, int width) {
	if (num > 999 and num < 10000) {
		cout.width(width + 1);
		cout << right << "00" << num;
	}
	if (num > 9999 and num < 100000) {
		cout.width(width);
		cout << right << "0" << num;
	}
}

void Draw(struct Record* records) {
	int width = 78 + 9;
	cout << endl;	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(width);  cout << left << "|Сельскохозяйственные культуры"; cout << "|" << endl;
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	cout << left << "| Наименование ";
	cout << left << "| Тип";
	cout << left << "| Посевная площадь (га)";
	cout << left << "| Урожайность (ц/га)";
	cout << left << " | Дата начала посевной ";
	cout << "|" << endl;
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	for (int i = 0; i < 10; i++) {
		if (not records[i].isEmpty) {
			cout << left << "|"; cout.width(14); cout << left << records[i].name;
			cout << left << "|"; cout.width(4); cout << left << records[i].type;
			cout << left << "|";  printWhithZero(records[i].area, 17);
			cout << left << "|"; cout.width(20); cout << left << records[i].productivity;
			cout << left << "|";
			printDate(records[i].date.day, records[i].date.month, records[i].date.year, 24);
			cout << "|" << endl;
		}
	}
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(width);  cout << left << "|Примечание: возможно бесплатно получить продукт StarOffice через Internet "; cout << "|" << endl;
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
}

/// <summary>
/// Добавляет элемент в начало динамического списка
/// </summary>
/// <param name="data"> данные элемента</param>
void addItem(Record data)
{
	struct node* newItem = new node();
	newItem->data = data;
	if (countItem == 0) {
		newItem->next = NULL;
	}
	else
	{
		newItem->next = myHead;
	}
	myHead = newItem;
	countItem++;
}
/// <summary>
/// Вставка элемента в список
/// </summary>
/// <param name="index">индекс после которого вставить</param>
/// <param name="data">значение которое необходимо вставить</param>
void insertItem(int index, Record data) {
	if (not (index >= 0 and index <= countItem and countItem >= 0))
		return;
	if (index == 0) {
		addItem(data);
	}
	else {
		struct node* current = myHead;
		for (int i = 0; i < index - 1; i++) {
			current = current->next;
		}
		struct node* newItem = new node();
		newItem->data = data;
		newItem->next = current->next;
		current->next = newItem;
		countItem++;
	}
}
/// <summary>
/// Изменить элемент списка
/// </summary>
/// <param name="index">индекс изменяемого элемента</param>
/// <param name="data">значение на которое нужно изменить</param>
void editItem(int index, Record data) {
	if (index >= 0 and index < countItem and countItem>0) {
		struct node* current = myHead;
		for (int i = 0; i < index; i++) {
			current = current->next;
			//cout << "+" << current->data;
		}
		current->data = data;
	}
	else {
		cout << endl << "Ошибка индекс не в диапазоне";
	}
}
/// <summary>
/// Функция для удаления элемента из динамического списка
/// </summary>
/// <param name="index">Индекс удаляемого элемента</param>
void deleteItem(int index) {
	if (index >= 0 and index < countItem and countItem>0) {
		struct node* current = myHead;
		struct node* old;
		if (index == 0) {
			old = myHead;
			myHead = current->next;
			delete old;
			countItem--;
		}
		else {
			int i = 0;
			while (current) {
				if (i == index - 1) {
					old = current->next->next;
					delete current->next;
					current->next = old;
					countItem--;
					break;
				}
				i++;
				current = current->next;
			}
		}
	}
}
void printMyList() {
	struct node* current = myHead;
	cout << endl;
	while (current) {
		cout << " " << current->data.name;
		current = current->next;
	}
}
void DrawWithList() {
	cout << endl; cout.width(79); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(78); cout << left << "|Сельскохозяйственные культуры"; cout << "|"
		<< endl;
	cout.width(79); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	cout << left << "| Наименование ";
	cout << left << "| Тип";
	cout << left << "| Посевная площадь (га)";
	cout << left << "| Урожайность (ц/га)";
	cout << left << " | Дата начала посевной ";
	cout << "|" << endl;
	cout.width(79); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	struct node* current = myHead;
	while (current) {
		cout << left << "|"; cout.width(16); cout << left << current->data.name;
		cout << left << "|"; cout.width(11); cout << left << current->data.type;
		cout << left << "|+"; cout.width(10); cout << left << current->data.area;
		std::cout.precision(2);
		cout << left << "|"; cout.width(11); cout << left << fixed << current->data.productivity;
		cout << left << "|";
		printDate(current->data.date.day, current->data.date.month, current->data.date.year, 26);
		cout << "|" << endl;
		current = current->next;
	}
	cout.width(79); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(78); cout << left << "|Примечание: возможно бесплатно получить продукт StarOffice через Internet "; cout << " | " << endl;
	cout.width(79); cout.fill('-'); cout << "-" << endl;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Record records[10];

	records[0] = { "Соя", "Б", 0013000, 45, {11,01,2011},0 };
	records[1] = { "Чумиза", "З", 8000, 17, {21,10,2012},0 };
	records[2] = { "Рис", "З",  0025650, 24, {21,10,2020},0 };
	Draw(records);

	cout << endl << "Вариант задания : Добавить новую запись(элемент массива структур), содержащие максимальные числовые значения в столбцах";
	records[3] = { "МАКС", "М",  9999, 99, {31,12,2023},0 };
	cout << "Данные по варианту задания:" << endl;
	Draw(records);

	// Практика 3 Динамический список
	cout << "Практика 3 Динамический список" << endl;
	//system("mspaint");
	addItem(records[0]);
	addItem(records[1]);
	addItem(records[2]);
	DrawWithList();
	struct Record newRecord = { "Кукуруза", "З",  0026400, 36, {26,03,2015},0 };
	insertItem(1, newRecord);
	DrawWithList();
	deleteItem(3);
	DrawWithList();
	struct Record editRecord = { "Овес", "З",  0016773, 63, {16,04,2016},0 };
	editItem(1, editRecord);
	DrawWithList();

}