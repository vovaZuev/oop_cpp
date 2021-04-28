#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Element
{
	int Data; // значение эл-та
	Element* pNext; // указатель на следующий элемент
public:
	Element(int Data, Element* pNext = nullptr) : Data(Data), pNext(pNext)
	{
		cout << "ElementConstructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "ElementDestructor:\t" << this << endl;
	}
	friend class List;
};

class List
{
	Element* Head; // указатель на начальный элемент списка
public:
	List()
	{
		this->Head = nullptr;
		cout << "ListConstructor:\t" << this << endl;
	}
	~List()
	{
		cout << "ListDestructor:\t" << this << endl;
	}
	// Adding elements
	void push_front(int Data)
	{
		Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;
	}
	void push_back(int Data)
	{
		Element* New = new Element(Data);
		Element* temp = Head;
		while (temp != nullptr)
		{
			if (temp->pNext != nullptr)
				temp = temp->pNext; // переход на следующий элемент
			else
				break;
		}
		temp->pNext = New;
	}
	// Methods
	void print() const
	{
		// Для того, чтобы ходить по списку, нужны: 1) итератор, 2) Цикл
		Element* temp = Head; // temp - это итератор - указатель, при помощи которого можно получить доступ к элементам структуры данных
		while (temp != nullptr)
		{
			cout << temp << "\t" << temp->Data << "\t" << temp->pNext << endl;
			temp = temp->pNext; // переход на следующий элемент
		}
	}
};

int main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер списка: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}
	list.print();
	list.push_front(999);
	list.print();
	list.push_back(777);
	list.print();
}