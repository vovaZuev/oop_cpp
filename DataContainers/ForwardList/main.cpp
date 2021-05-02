#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Element
{
	int Data; // значение эл-та
	Element* pNext; // указатель на следующий элемент
	static int count;
public:
	Element(int Data, Element* pNext = nullptr) : Data(Data), pNext(pNext)
	{
		count++;
		//cout << "ElementConstructor:\t" << this << endl;
	}
	~Element()
	{
		count--;
		//cout << "ElementDestructor:\t" << this << endl;
	}
	friend class ForwardList;
};

int Element::count = 0; // инициализация статической переменной

class ForwardList
{
	unsigned int size;
	Element* Head; // указатель на начальный элемент списка
public:
	ForwardList()
	{
		this->size = 0;
		this->Head = nullptr;
		cout << "ListConstructor:\t" << this << endl;
	}
	// Copy Constructor
	ForwardList(const ForwardList& other) : ForwardList()
	{
		for (Element* temp = other.Head; temp; temp = temp->pNext)
		{
			push_back(temp->Data);
		}
		cout << "CopyConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		/*Element* temp = Head;
		while (temp)
		{
			Element* del = temp;
			temp = temp->pNext;
			delete del;
		}*/
		while (Head) pop_front();
		cout << "ListDestructor:\t" << this << endl;
	}
	// Adding elements
	void push_front(int Data)
	{
		/*Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;*/
		Head = new Element(Data, Head);
		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		Element* New = new Element(Data);
		Element* temp = Head;
		while (temp->pNext != nullptr)
		{
			temp = temp->pNext;
		}
		temp->pNext = New;
		size++;
	}
	void insert(int Data, int index)
	{
		Element* temp = Head;
		if (index < 0 || index > Element::count) return;
		if (index == 0)
		{
			push_front(Data);
			return;
		}
		Element* New = new Element(Data);
		for (int i = 0; i < index - 1; i++)
		{
			temp = temp->pNext;
		}
		New->pNext = temp->pNext;
		temp->pNext = New;
		size++;
	}
	// Removing elements
	void pop_front()
	{
		if (Head == nullptr) return;
		Element* temp = Head;	// 1) Запоминаем адрес удаляемого элемента
		Head = Head->pNext;		// 2) Исключаем элемент из списка
		delete temp;			// 3) Удаляем элемент из памяти
		size--;
	}
	void pop_back()
	{
		if (Head == nullptr) return;
		if (Head->pNext == nullptr)
		{
			pop_front();
			return;
		}
		Element* temp = Head;
		while (temp->pNext->pNext != nullptr)
		{
			temp = temp->pNext;
		}
		delete temp->pNext;
		temp->pNext = nullptr;
		size--;
	}
	void erase(int index)
	{
		if (index < 0 || index >= size) return;
		if (index == 0)
		{
			pop_front();
			return;
		}
		if (index == size - 1)
		{
			pop_back();
			return;
		}
		Element* temp = Head;
		for (int i = 1; i < index; i++)
		{
			temp = temp->pNext;
		}
		Element* next = temp->pNext->pNext;
		delete temp->pNext;
		temp->pNext = next;
		size--;
	}
	// Methods
	void print() const
	{
		/*
		// Для того, чтобы ходить по списку, нужны: 1) итератор, 2) Цикл
		Element* temp = Head; // temp - это итератор - указатель, при помощи которого можно получить доступ к элементам структуры данных
		while (temp != nullptr)
		{
			cout << temp << "\t" << temp->Data << "\t" << temp->pNext << endl;
			temp = temp->pNext; // переход на следующий элемент
		}
		*/
		for(Element* temp = Head; temp; temp=temp->pNext)
			cout << temp << "\t" << temp->Data << "\t" << temp->pNext << endl;
		cout << "В списке " << size << " элементов." << endl;
		cout << "Общее количество элементов: " << Element::count << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}
	list.print();
	ForwardList list2(list);
	list2.print();
/*
	cout << "List ready" << endl;
#ifdef TEST_REMOVE
	list.pop_front();
	list.print();
	list.pop_back();
	list.print();
	int i;
	cout << "Введите индекс удаляемого элемента: "; cin >> i;
	list.erase(i);
	list.print();
#endif
#ifdef TEST_ADD
	// push_front & push_back test
	list.push_front(999);
	list.print();
	list.push_back(777);
	list.print();
	// insert test
	list.insert(999, 0);
	list.print();

	cout << "Введите размер списка: "; cin >> n;
	ForwardList list2;
	for (int i = 0; i < n; i++)
	{
		list2.push_front(rand() % 100);
	}
	list2.print();
#endif
*/
	
}