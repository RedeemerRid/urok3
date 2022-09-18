#include <iostream>

using namespace std;

class Reservoir
{
private:
	char* m_nameR;
	int m_width;  // ������
	int m_length; // �����
    int m_depth;  // �������
	//double m_surface;  // ������� �����������
	//static int m_sizeR;
	void createNameR(char* nameR) 
	{
		int nameRsize = strlen(nameR) + 1;
		m_nameR = new char[nameRsize];
		for (int i{ 0 }; i < nameRsize; i++)
		{
			m_nameR[i] = nameR[i];
		}
	}
public:
	Reservoir() : m_nameR{ nullptr }, m_width{0}, m_length{0}, m_depth{0} { }
	
	Reservoir(char* nameR, int width, int length, int depth)
	{
		createNameR(nameR);
		setnameR(nameR);
		setwidth(width);
		setlength(length);
		setdepth(depth);
		
	}
	
	Reservoir(const Reservoir& other) //: m_nameR{ new char[strlen(other.m_nameR) + 1]},
		//m_width{ other.m_width }, m_length{ other.m_length }, m_depth{ other.m_depth }
	{
		createNameR(other.m_nameR);
		setnameR(other.m_nameR);
		setwidth(other.m_width);
		setlength(other.m_length);
		setdepth(other.m_depth);
		//strcpy_s(m_nameR, strlen(other.m_nameR) + 1, other.m_nameR);

		
	}
	
	~Reservoir()
	{

		//delete[] m_nameR;
		
	}
	
	void setnameR(char* nameR) 
	{		
		
		delete[] m_nameR;
		createNameR(nameR);
		
	}
	char* getnameR() const { return m_nameR; }
	void setwidth(int width) { m_width = width; }
	int getwidth() const { return m_width; }
	void setlength(int length) { m_length = length; }
	int getlength() const { return m_length; }
	void setdepth(int depth) { m_depth = depth; }
	int getdepth() const { return m_depth; }
		
	void addR()
	{
		char nameR[20];
		
		cout << "������� �������� ������� : ";
		cin.ignore();
		cin.getline(nameR, 20);
		createNameR(nameR);
		cout << "������� ������ (m): ";
		cin >> m_width;
		cout << "������� ����� (m):";
		cin >> m_length;
		cout << "������� ������� (m): ";
		cin >> m_depth;
	}
	
	void print() const
	{
		
		cout << "name : " << getnameR() << endl;
		cout << "width : " << getwidth() << endl;
		cout << "length : " << getlength() << endl;
		cout << "depth : " <<  getdepth() << endl;
	}

};

void addR(Reservoir* reservoir, int& sizeR)
{
		
	Reservoir reserv;
	reserv.addR();
	reservoir[sizeR] = reserv;
	sizeR++;
	
		
}

void delR(Reservoir* reservoir, int& sizeR) {

	char* f = new char[20];

	int q = 0;

	cout << "��������� ������ ������� �������� ������� : ";
	cin.ignore();

	cin.getline(f, 20);

	for (int i = 0; i < sizeR; i++)
	{
		if (strcmp(f, reservoir[i].getnameR()) == 0)
		{
			q = i;
			for (int i = q; i < sizeR - 1; i++)
			{
				reservoir[i] = reservoir[i + 1];
			}
			sizeR--;
			i--;
		}
	}
	system("pause");
	delete[] f;
}

void printR(Reservoir* reservoir, int& sizeR)
{
	for (int i{ 0 }; i < sizeR; i++)
	{
		
		cout << "������ #_" << reservoir[i].getnameR() << " : " << endl;
		reservoir[i].print();
		//cout << endl;
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
		}
	} while (exit != 0);
			
	
		
			delete[] reservoir;
		
	return 0;
}