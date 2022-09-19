#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <io.h>
#include <stdio.h>

using namespace std;

class Reservoir
{
private:
	char* m_nameR;
	double m_width;  // ������
	double m_length; // �����
    double m_depth;  // �������
	double m_S;  // ������� �����������
	double m_V;
	bool m_type;
	char n[4]{ "ups" };
	
	void createNameR(char* nameR) 
	{
		int nameRsize = strlen(nameR) + 1;
		m_nameR = new char[nameRsize];
		for (size_t i{ 0 }; i < nameRsize; i++)
		{
			m_nameR[i] = nameR[i];
		}
		
	}
	
public:
	
	Reservoir() : Reservoir( n, 0, 0, 0, 0) { }
	
	Reservoir(char* nameR, double width, double length, double depth, bool m_type)
	{
		//createNameR(nameR);
		
		setnameR(nameR);
		setwidth(width);
		setlength(length);
		setdepth(depth);
		settype(type);
		
	}
	
	Reservoir(const Reservoir& other) //: m_nameR{ new char[strlen(other.m_nameR) + 1]},
		//m_width{ other.m_width }, m_length{ other.m_length }, m_depth{ other.m_depth }
	{
		//createNameR(other.m_nameR);
		
		setnameR(other.m_nameR);
		setwidth(other.m_width);
		setlength(other.m_length);
		setdepth(other.m_depth);
		settype(other.type);
		//strcpy_s(m_nameR, strlen(other.m_nameR) + 1, other.m_nameR);

		
	}
	
	
	
	void setnameR(char* nameR) 
	{
		//m_nameR = new char[strlen(nameR) + 1];
		//strcpy_s(m_nameR, strlen(nameR) + 1, nameR);
		//createNameR(nameR);
		
		//delete[] m_nameR;
		createNameR(nameR);
		
	}
	char* getnameR() { return m_nameR; }
	void setwidth(double width) { m_width = width; }
	double getwidth() { return m_width; }
	void setlength(double length) { m_length = length; }
	double getlength() { return m_length; }
	void setdepth(double depth) { m_depth = depth; }
	double getdepth() { return m_depth; }
	bool settype(bool type)

			
	void addR()
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

		//delete[] nameR;
		
	}
	
	void print() const
	{
		
		cout << "name : " << m_nameR << endl;
		cout << "width : " << m_width << endl;
		cout << "length : " << m_length << endl;
		cout << "depth : " <<  m_depth << endl;
		
	}

	double V()
	{
		m_V = m_width * m_length * m_depth;
		cout << "����� ������� # " << m_nameR << " = ";
		return m_V;
	}

	double S()
	{
		m_S = m_width * m_length;
		cout << "������� ����������� ������� # " << m_nameR << " = ";
		return m_S;
	}



	/*
	~Reservoir()
	{
		cout << " destr : " << endl;
		delete[] m_nameR;

	}
	*/
};


void addR(Reservoir*& reservoir, int& sizeR)
{
	
	
	Reservoir* reserv = new Reservoir[sizeR+1];
	for (size_t i = 0; i < sizeR+1; i++)
	{
		reserv[i] = reservoir[i];
		
	}
	reserv[sizeR].addR();
	sizeR++;
	delete[] reservoir;
	reservoir=reserv;
	
	
	
	
	/*
	Reservoir reserv;
	reserv.addR();
	reservoir[sizeR] = reserv;
	sizeR++;
	*/
		
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
			

			//i--;
		}
	
	}
	Reservoir* reserv = new Reservoir[sizeR];

	for (size_t i = 0; i < sizeR+1; i++)
		reserv[i] = reservoir[i];
	delete[] reservoir;
	
	reservoir = reserv;
	
	
	delete[] f;

	system("pause");
}

void printR(Reservoir* reservoir, int& sizeR)
{
	for (size_t i{ 0 }; i < sizeR; i++)
	{
		
		cout << "������ #_" << reservoir[i].getnameR() << " : " << endl;
		reservoir[i].print();
		//cout << endl;
	}
		
	system("pause");
}

void getV(Reservoir* reservoir, int&sizeR)
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
			cout << reservoir[i].S() << endl;
		}
	}
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
		cout << "6 - ����� �� �������� �������" << endl;
		cout << "7 - ����������� �� ��������" << endl;
		cout << "8 - ����������� ������ �������" << endl;
		cout << "9 - ����������� ������� ����������� �������" << endl;
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
			cout << "6 - ����� �� �������� �������" << endl;
			cout << "7 - ����������� �� ��������" << endl;
			cout << "8 - ����������� ������ �������" << endl;
			cout << "9 - ����������� ������� ����������� �������" << endl;
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
			/*
		case 4://2
			savedR(reservoir, m);
			break;
		case 5://2
			loaddR(reservoir, m);
			break;
		case 6://2
			searchR(reservoir, m);
			break;
		case 7://2
			sortR(reservoir, m);
			break;
		*/
		case 8 :
			getV(reservoir, sizeR);
			break;
		case 9:
			getS(reservoir, sizeR);
			break;
		}
	} while (exit != 0);
			
	
		
		//	delete[] reservoir;
		
	return 0;
}