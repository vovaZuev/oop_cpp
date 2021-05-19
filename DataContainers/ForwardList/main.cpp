#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

class Element
{
	int Data; // значение эл-та
	Element* pNext; // указатель на следующий элемент
	static int count;
public:
	const int get_data() const
	{
		return Data;
	}
	const Element* get_pnext() const
	{
		return pNext;
	}
	Element* get_pnext()
	{
		return pNext;
	}
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
	// Operators
	Element* operator ++()
	{
		return pNext;
	}
	friend class ForwardList;
};

int Element::count = 0; // инициализация статической переменной

class ForwardList
{
	unsigned int size;
	Element* Head; // указатель на начальный элемент списка
public:
	const unsigned int get_size() const
	{
		return size;
	}
	const Element* get_head() const
	{
		return Head;
	}
	// CONSTRUCTORS
	ForwardList()
	{
		this->size = 0;
		this->Head = nullptr;
		cout << "ListConstructor:\t" << this << endl;
	}
	// Initializer list constructor
	ForwardList(const std::initializer_list<int>il) : ForwardList()
	{
		cout << typeid(il.begin()).name() << endl;
		for (const int* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
		cout << "ILConstructor:\t" << this << endl;
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
	// Move Constructor
	ForwardList(ForwardList&& other)
	{
		this->~ForwardList();
		this->size = other.size;
		this->Head = other.Head;
		other.Head = nullptr;
		cout << "MoveConstructor:\t" << this << endl;
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
	// OPERATORS
	ForwardList& operator = (const ForwardList& other)
	{
		if (this == &other) return *this;
		this->~ForwardList();
		for (Element* temp = other.Head; temp; temp = temp->pNext)
		{
			push_back(temp->Data);
		}
		cout << "CopyAssignment:\t" << this << endl;
	}
	ForwardList& operator = (ForwardList&& other)
	{
		this->~ForwardList();
		this->size = other.size;
		this->Head = other.Head;
		other.Head = nullptr;
		cout << "MoveAssignment:\t" << this << endl;
	}
	int& operator [] (int index)
	{
		if (index < 0 || index >= Element::count)
		{
			cout << "Задан неверный индекс!" << endl;
			exit(EXIT_FAILURE);
		}
		int i = 0;
		for (Element* temp = Head; temp; temp = temp->pNext)
		{
			if (i == index)
				return temp->Data;
			i++;
		}
		exit(EXIT_FAILURE);
	}
	// Adding elements
	void push_front(int Data)
	{
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
		for(Element* temp = Head; temp; ++temp)
			cout << temp << "\t" << temp->Data << "\t" << temp->pNext << endl;
		cout << "В списке " << size << " элементов." << endl;
		cout << "Общее количество элементов: " << Element::count << endl;
	}
};
// CONCATENATION

ForwardList operator + (const ForwardList& left, const ForwardList& right)
{
	ForwardList result = left;
	for (const Element* temp = right.get_head(); temp; temp = temp->get_pnext())
	{
		result.push_back(temp->get_data());
	}
	return result;
}
// OSTREAM
ostream& operator << (ostream& os, ForwardList& obj)
{
	for (const Element* temp = obj.get_head(); temp; temp = temp->get_pnext())
	{
		os << temp->get_data() << " ";
	}
	return os;
}

#define delim "-----------------------------------------------------"

int main()
{
	setlocale(LC_ALL, "");
	/*int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list1;
	for (int i = 0; i < n; i++)
	{
		list1.push_front(rand() % 100);
	}
	list1.print();
	cout << delim << endl;
	ForwardList list2;
	for (int i = 0; i < n; i++)
	{
		list2.push_front(rand() % 50);
	}
	list2.print();
	cout << delim << endl;
	ForwardList list3 = list1 + list2;
	list3.print();
	cout << delim << endl;
	cout << list3 << endl;*/

	ForwardList list = {3, 5, 8, 13, 21};
	list.print();
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
	/*int index{};
	cout << "Введите индекс элемента списка для вывода: "; cin >> index;
	if(list[index] != -1)
		cout << index << "-й элемент списка равен " << list[index] << endl;
	list[2] = 99;
	cout << list << endl;*/
}