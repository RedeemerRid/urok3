#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <io.h>
#include <stdio.h>
#include <iomanip>

using namespace std;

class Reservoir
{
private:
	char* m_nameR;
	double m_width;  // ������
	double m_length; // �����
	double m_depth;  // �������
	double m_S;  // ������� �����������
	double m_V; // ����� �������
	char n[4]{ "ups" }; // ��� ������ ��� �� ���������

	void createNameR(char* nameR)
	{
		int nameRsize = strlen(nameR) + 1;
		m_nameR = new char[nameRsize];
		for (size_t i{ 0 }; i < nameRsize; i++)
		{
			m_nameR[i] = nameR[i];
		}
	}

	//friend istream& operator >> (istream& is, Reservoir& reservoir);

public:
	Reservoir() : Reservoir(n, 0, 0, 0, 0) { }
	
	Reservoir(char* nameR, double width, double length, double depth, bool type)
	{
		cout << "const " << this << endl;
		
		setnameR(nameR);
		setwidth(width);
		setlength(length);
		setdepth(depth);
	   
	}
	
	Reservoir(const Reservoir& other) 
	{
		setnameR(other.m_nameR);
		setwidth(other.m_width);
		setlength(other.m_length);
		setdepth(other.m_depth);
	}
	~Reservoir() {}
	
	void setnameR(char* nameR) 	{createNameR(nameR);}
	char* getnameR() const { return m_nameR; }
	void setwidth(double width) { m_width = width; }
	double getwidth() const { return m_width; }
	void setlength(double length) { m_length = length; }
	double getlength() const { return m_length; }
	void setdepth(double depth) { m_depth = depth; }
	double getdepth() const { return m_depth; }
				
	void addR();

	void print();
	
	double V();
	
	double S();
	
	char* getType();
	
};
/*
istream& operator >> (istream& is, Reservoir& reservoir)
{
	is >> reservoir.m_nameR;
	is >> reservoir.m_width;
	is >> reservoir.m_length;
	is >> reservoir.m_depth;
	
	return is;
}
*/
ostream& operator << (ostream& os, Reservoir& reservoir)
{
		
	os << left << setw(35) <<  reservoir.getnameR() << setw(15) << reservoir.getwidth() << setw(15) << reservoir.getlength() << setw(15) << reservoir.getdepth() << endl;
	/*
	os << "���:" << a.getfio() << "���������������:" << a.gethphon()
		<< "��������������:" << a.getwphon() << "����������������:" << a.getmphon()
		<< "����������.����.:" << a.getdopinfo();
	*/
	return os;
}

void Reservoir::addR()
{
	char nameR[20];
	cout << "������� �������� ������� : ";
	double width, length, depth;
	cin >> nameR;
	setnameR(nameR);
	cout << "������� ������ (m): ";
	cin >> width;
	setwidth(width);
	cout << "������� ����� (m):";
	cin >> length;
	setlength(length);
	cout << "������� ������� (m): ";
	cin >> depth;
	setdepth(depth);
}
void Reservoir::print() 
{
	cout << "name : " << m_nameR << endl;
	cout << "width : " << m_width << endl;
	cout << "length : " << m_length << endl;
	cout << "depth : " << m_depth << endl;
}
double Reservoir::V()
{
	m_V = m_width * m_length * m_depth;
	cout << "����� ������� # " << m_nameR << " = ";
	return m_V;
}
double Reservoir::S()
{
	m_S = m_width * m_length;
	//cout << "������� ����������� ������� # " << m_nameR << " = ";
	return m_S;
}
char* Reservoir::getType()
{
	if (m_depth <= 3 && S() <= 200) {
		char typeR[20] = "Prud-Bassein";
		int x = strlen(typeR) + 1;
		char* f = new char[x];
		for (size_t i{ 0 }; i < x; i++)
			f[i] = typeR[i];
		return f;
	}
	else if (S() >= 11500 && m_depth >= 50) {
		char typeR[20] = "Sea";
		int x = strlen(typeR) + 1;
		char* f = new char[x];
		for (size_t i{ 0 }; i < x; i++)
			f[i] = typeR[i];
		return f;
	}

	else
	{
		char typeR[20] = "Prud";
		int x = strlen(typeR) + 1;
		char* f = new char[x];
		for (size_t i{ 0 }; i < x; i++)
			f[i] = typeR[i];
		return f;
	}
}

void addR(Reservoir*& reservoir, int& sizeR)
{
	Reservoir* reserv = new Reservoir[sizeR+1];
	for (size_t i = 0; i < sizeR; i++)
	{
		reserv[i] = reservoir[i];
	}
	reserv[sizeR].addR();
	sizeR++;
	delete[] reservoir;
	reservoir=reserv;
}

void delR(Reservoir*& reservoir, int& sizeR) {
	
	char* f = new char[20];
	int q = 0;
	cout << "��������� ������ ������� �������� ������� : ";
	cin.ignore();
	cin.getline(f, 20);
	for (size_t i = 0; i < sizeR; i++)
	{
		if (strcmp(f, reservoir[i].getnameR()) == 0)
		{
			q = i;
			for (size_t i = q; i < sizeR - 1; i++)
			{
				reservoir[i] = reservoir[i + 1];
			}
			sizeR--;
			i--;
		}
	}
	Reservoir* reserv = new Reservoir[sizeR+1];

	for (size_t i = 0; i < sizeR; i++)
		reserv[i] = reservoir[i];
	delete[] reservoir;
	
	reservoir = reserv;
	
	
	delete[] f;

	system("pause");
}

void printR(Reservoir*& reservoir, int& sizeR)
{
	for (size_t i{ 0 }; i < sizeR; i++)
	{
		
		cout << "������ #_" << reservoir[i].getnameR() << " : " << endl;
		reservoir[i].print();
		//cout << endl;
	}
		
	system("pause");
}

void getV(Reservoir*& reservoir, int&sizeR)
{
	cout << "������� �������� �������  : ";
	char f[20];
	cin >> f;
	for (size_t i{ 0 }; i < sizeR; i++)
	{
		if (strcmp(f, reservoir[i].getnameR()) == 0)
		{
			cout << reservoir[i].V() << endl;
		}
	}
	system("pause");
}

void getS(Reservoir* reservoir, int& sizeR)
{
	cout << "������� �������� �������  : ";
	char f[20];
	cin >> f;
	for (size_t i{ 0 }; i < sizeR; i++)
	{
		if (strcmp(f, reservoir[i].getnameR()) == 0)
		{
			cout << "������� ����������� ������� # " << reservoir[i].getnameR() << " = " << reservoir[i].S() << endl;
		}
	}
	system("pause");
}


char** compareTypeR(Reservoir*& reservoir, int& sizeR)
{
		
	char* t2 = new char[20];
	char* t1 = new char[20];
	string i1, i2;

	cout << "������� �������� ������� : ";
	char name11[20];
	cin >> name11;
	char* name1 = new char[strlen(name11)+1];
	strcpy_s(name1, strlen(name11) + 1, name11);
	for (size_t i{ 0 }; i < sizeR; i++)
	{
		if (strcmp(name1, reservoir[i].getnameR()) == 0) {
			int x1 = strlen(reservoir[i].getType())+1;
			delete[] t1;
			t1 = new char[x1];
			strcpy_s(t1, x1, reservoir[i].getType());
			i1 = to_string(i);
		}
	}
	cout << "������� �������� ������� c ������� �������� : ";
	char name22[20];
	cin >> name22;
	char* name2 = new char[strlen(name22) + 1];
	strcpy_s(name2, strlen(name22) + 1, name22);
	for (size_t i{ 0 }; i < sizeR; i++)
	{
		if (strcmp(name2, reservoir[i].getnameR()) == 0) {
			int x2 = strlen(reservoir[i].getType())+1;
			delete[] t2;
			t2 = new char[x2];
			strcpy_s(t2, x2, reservoir[i].getType());
			i2 = to_string(i);

		}
	}
	cout << "������ # " << name1 << " ��������� � ���� : " << t1 << endl;
	cout << "������ # " << name2 << " ��������� � ���� : " << t2 << endl;
	if (strcmp(t1, t2) == 0)
		cout << "���������� ���" << endl;
	else
		cout << "������ ����" << endl;
	
	delete[] name1;
	delete[] name2;
	system("pause");
	cout << "������ ENTER ��� �����������" << endl;
	char** arr = new char* [4];
	for (int i = 0; i < 4; i++) {
		arr[i] = new char[20];
	}
	strcpy_s(arr[0], 20, t1);
	strcpy_s(arr[1], 20, t2);
	strcpy_s(arr[2], 20, i1.c_str());
	strcpy_s(arr[3], 20, i2.c_str());

	
	
	return arr;

}

void compareStypeR(Reservoir*& reservoir, int& sizeR)
{
	char** t = new char* [4];
	for (int i = 0; i < 2; i++) {
		t[i] = new char[20];
	}
	t = compareTypeR(reservoir, sizeR);
	int i1 = atoi(t[2]);
	int i2 = atoi(t[3]);
	cout << t[0] << " : " << t[1] << endl;
	if (strcmp(t[0], t[1]) == 0)
	{
		if (reservoir[i1].S() > reservoir[i2].S())
			cout << "������� ����������� ������� # " << reservoir[i1].getnameR() << " > " << "������� ����������� ������� # " << reservoir[i2].getnameR() << endl;
		else if (reservoir[i1].S() < reservoir[i2].S())
			cout << "������� ����������� ������� # " << reservoir[i1].getnameR() << " < " << "������� ����������� ������� # " << reservoir[i2].getnameR() << endl;
		else
			cout << "������� ����������� ������� # " << reservoir[i1].getnameR() << " = " << "������� ����������� ������� # " << reservoir[i2].getnameR() << endl;

	}
	else
		cout << "������ ����" << endl;
		
	

	for (int i = 0; i < 2; i++) {
		delete[] t[i];
	}
	delete[] t;
	
	system("pause");
}

void copyR(Reservoir*& reservoir, int& sizeR)
{
	Reservoir* reserv = new Reservoir[sizeR + 1];
	char name[20];
	
	for (size_t i{ 0 }; i < sizeR; i++)
	{
		cout << "������ #_" << reservoir[i].getnameR() <<  endl;
	}
	cout << "�������� �������� ������� ��� �� ����������� : ";
	cin >> name;
	char* nameR = new char[strlen(name) + 1];
	strcpy_s(nameR, strlen(name) + 1, name);
	for (size_t i{ 0 }; i < sizeR; i++)
	{
		if (strcmp(nameR, reservoir[i].getnameR()) == 0) {
			Reservoir reserv1(reservoir[i]);
			for (size_t j = 0; j < sizeR; j++)
			{
				reserv[j] = reservoir[j];
			}
			reserv[sizeR] = reserv1;
			sizeR++;
			delete[] reservoir;
			reservoir = reserv;
			
			break;
		}
	}
	
	
	
	system("pause");
}

void savedR(Reservoir*& reservoir, int& nameR)
{
	fstream fs;
	fs.open("Reservoir.txt", fstream::out);
	if (!fs.is_open())
	{
		cout << "������ ��������" << endl;
	}
	else
	{
		cout << "���� ������" << endl;
		fs << left << setw(20) << "�������� �������" << setw(10) << "������" << setw(10) << "�����" << setw(10) << "�������" << endl << endl;
		for (int i = 0; i < nameR; i++)
		{
			
			fs << reservoir[i] << "\n";
		}
	}
	fs.close();

}

void savedR_bin(Reservoir*& reservoir, int& sizeR)
{
	FILE* file;
	const char* filename = "Reservoir_bin.txt";
	fopen_s(&file, filename, "wb");
	fwrite(&reservoir[0], sizeof(Reservoir), sizeR, file);
	fclose(file);
}

void loadR(Reservoir* reservoir, int& sizeR)
{
	string line;
	ifstream myfile("example.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << '\n';
		}
		myfile.close();
	}

	else cout << "Unable to open file";

	system("pause");
	
}

int main()
{
	setlocale(LC_ALL, "rus");
	
		
	setlocale(LC_ALL, "");
	bool exit = true;
	int sizeR = 0;
	int press;
	Reservoir* reservoir = new Reservoir[sizeR];
	
	do
	{
		cout << "1 - �������� ������ ��������" << endl;
		cout << "2 - ������� ����� ������" << endl;
		cout << "3 - ������� ����� ������" << endl;
		cout << "4 - �������� � ����" << endl;
		cout << "5 - ������ � �����" << endl;
		cout << "6 - ����������� ������" << endl;
		cout << "7 - ����������� ������ �������" << endl;
		cout << "8 - ����������� ������� ����������� �������" << endl;
		cout << "9 - ����������� �����  �������" << endl;
		cout << "10 - ��������� ������� �������� ������ ����" << endl;
		cout << "11 - �������� � ���� ��������" << endl;

		cout << "0 - �����" << endl;
		cout << "    �������� �� ������ ��� �� ������ ������� : ";

		while (!isdigit(char(cin.peek())))
		{
			system("cls");

			cin.ignore();

			cout << "1 - �������� ������ ��������" << endl;
			cout << "2 - ������� ����� ������" << endl;
			cout << "3 - ������� ����� ������" << endl;
			cout << "4 - �������� � ����" << endl;
			cout << "5 - ������ � �����" << endl;
			cout << "6 - ����������� ������" << endl;
			cout << "7 - ����������� ������ �������" << endl;
			cout << "8 - ����������� ������� ����������� �������" << endl;
			cout << "9 - ����������� �����  �������" << endl;
			cout << "10 - ��������� ������� �������� ������ ����" << endl;
			cout << "11 - �������� � ���� ��������" << endl;
			cout << "0 - �����" << endl;
			cout << "    �������� �� ������ ��� �� ������ ������� : ";
		}
		cin >> press;
		switch (press)
		{
		case 0://0
			cout << "�� �������, ��� ������ �����? --  ����� = 0, ���������� = 1 : ";
			cin >> exit;
			break;
		case 1://1
			printR(reservoir, sizeR);
			break;
		case 2://2
			
			addR(reservoir, sizeR);
			
			break;
			
		case 3://2
			delR(reservoir, sizeR);
			break;
			
		case 4://2
			savedR(reservoir, sizeR);
			break;
		case 5://2
			loadR(reservoir, sizeR);
			break;
		case 6://2
			copyR(reservoir, sizeR);
			break;
		case 7 :
			getV(reservoir, sizeR);
			break;
		case 8:
			getS(reservoir, sizeR);
			break;
		case 9:
			compareTypeR(reservoir, sizeR);
			break;
		case 10:
			compareStypeR(reservoir, sizeR);
			break;
		case 11://2
			savedR_bin(reservoir, sizeR);
			break;

		}
	} while (exit != 0);
			
	
		
	delete[] reservoir;
		
	return 0;
}