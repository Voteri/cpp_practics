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

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Record records[10];

	records[0] = { "Соя", "Б", 0013000, 45, {11,01,2011},0};
	records[1] = { "Чумиза", "З", 8000, 17, {21,10,2012},0};
	records[2] = { "Рис", "З",  0025650, 24, {21,10,2020},0};
	Draw(records);


	records[3] = { "МАКС", "М",  9999, 99, {31,12,2023},0};

	Draw(records);
	cout << endl << "Практическая № 2 (Динамические массивы):" << endl;
	Record* A;
	int n = 3;
	A = (Record*)malloc(n * sizeof(Record));
	//A = (Record*)calloc(n, sizeof(Record)); 
	for (int i = 0; i < n; i++) {
		strcpy_s(A[i].name, records[i].name);
		strcpy_s(A[i].type, records[i].type);
		//A[i].surName = records[i].surName;
		/*A[i].year, records[i].year;*/
		//A[i].surName.assign(records[i].surName.c_str());
		//	*(B[i]) = records[i];
		//basic_string<char>
	}

	Record** B;
	B = (Record**) new Record * [10];
	for (int i = 0; i < 10; i++) {
		B[i] = (Record*) new Record;
		*(B[i]) = records[i];
	}

	//
	A = (Record*)realloc(A, 10 * sizeof(Record));
	// 
	//Record ** B;
	//B = (Record**) new Record * [10];
	//for (int i = 0; i < 10; i++) {
	//	B[i] = (Record*) new Record;
	//	*(B[i]) = A[i];
	//	//B[i].surName = A[i].surName;
	//	//*(B[i])->surName = A[i]->surName;
	//	
	//}

	//адрес а[i], значение a[i]->строковое_поле, адрес в[i], значение в[i]->строковое_поле.
	for (int i = 0; i < 3; i++) {
		cout << endl << "адрес A[i] " << &A[i] << " a[i]->name " << A[i].name;
		//cout << endl << "адрес B[i] " << &B[i] << " B[i]->surName " << B[i]->surName;
	}

	//for (int i = 0; i < 10; i++) {
	//	delete B[i];
	//}
	//delete[]B;
	//free(A);
}