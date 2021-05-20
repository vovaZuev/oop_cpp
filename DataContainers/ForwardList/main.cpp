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
	const int get_data() const;
	const Element* get_pnext() const;
	Element* get_pnext();
	Element(int Data, Element* pNext = nullptr);
	~Element();
	friend class ForwardList;
	friend class Iterator;
};

int Element::count = 0; // инициализация статической переменной

const int Element::get_data() const
{
	return Data;
}
const Element* Element::get_pnext() const
{
	return pNext;
}
Element* Element::get_pnext()
{
	return pNext;
}
Element::Element(int Data, Element* pNext) : Data(Data), pNext(pNext)
{
	count++;
	//cout << "ElementConstructor:\t" << this << endl;
}
Element::~Element()
{
	count--;
	//cout << "ElementDestructor:\t" << this << endl;
}

class Iterator
{
	Element* Temp;
public:
	Iterator(Element* Temp = nullptr);
	~Iterator();
	// Operators
	Iterator& operator++();
	Iterator operator++(int);
	bool operator == (const Iterator& other) const;
	bool operator != (const Iterator& other) const;
	const Element* operator -> () const;
	Element* operator -> ();
	const int& operator*() const;
	int& operator*();
};

Iterator::Iterator(Element* Temp) : Temp(Temp)
{
	cout << "IConstructor:\t" << this << endl;
}
Iterator::~Iterator()
{
	cout << "IDestructor:\t" << this << endl;
}
// Operators
Iterator& Iterator::operator++()
{
	Temp = Temp->pNext;
	return *this;
}
Iterator Iterator::operator++(int)
{
	Iterator old = *this;
	Temp = Temp->pNext;
	return old;
}
bool Iterator::operator == (const Iterator& other) const
{
	return this->Temp == other.Temp;
}
bool Iterator::operator != (const Iterator& other) const
{
	return this->Temp != other.Temp;
}
const Element* Iterator::operator -> () const
{
	return Temp;
}
Element* Iterator::operator -> ()
{
	return Temp;
}
const int& Iterator::operator*() const
{
	return Temp->Data;
}
int& Iterator::operator*()
{
	return Temp->Data;
}

class ForwardList;
ForwardList operator + (const ForwardList& left, const ForwardList& right);
ostream& operator << (ostream& os, ForwardList& obj);

class ForwardList
{
	unsigned int size;
	Element* Head; // указатель на начальный элемент списка
public:
	const unsigned int get_size() const;
	const Element* get_head() const;
	Iterator begin();
	Iterator end();
	// CONSTRUCTORS
	ForwardList();
	// Initializer list constructor
	ForwardList(const std::initializer_list<int>il);
	// Copy Constructor
	ForwardList(const ForwardList& other);
	// Move Constructor
	ForwardList(ForwardList&& other);
	~ForwardList();
	// OPERATORS
	ForwardList& operator = (const ForwardList& other);
	ForwardList& operator = (ForwardList&& other);
	int& operator [] (int index);
	// Adding elements
	void push_front(int Data);
	void push_back(int Data);
	void insert(int Data, int index);
	// Removing elements
	void pop_front();
	void pop_back();
	void erase(int index);
	// Methods
	void print() const;
};
// CONCATENATION

const unsigned int ForwardList::get_size() const
{
	return size;
}
const Element* ForwardList::get_head() const
{
	return Head;
}
Iterator ForwardList::begin()
{
	return Head;
}
Iterator ForwardList::end()
{
	return nullptr;
}
// CONSTRUCTORS
ForwardList::ForwardList()
{
	this->size = 0;
	this->Head = nullptr;
	cout << "ListConstructor:\t" << this << endl;
}
// Initializer list constructor
ForwardList::ForwardList(const std::initializer_list<int>il) : ForwardList()
{
	//cout << typeid(il.begin()).name() << endl;
	for (const int* it = il.begin(); it != il.end(); it++)
	{
		push_back(*it);
	}
	cout << "ILConstructor:\t" << this << endl;
}
// Copy Constructor
ForwardList::ForwardList(const ForwardList& other) : ForwardList()
{
	for (Element* temp = other.Head; temp; temp = temp->pNext)
	{
		push_back(temp->Data);
	}
	cout << "CopyConstructor:\t" << this << endl;
}
// Move Constructor
ForwardList::ForwardList(ForwardList&& other)
{
	this->~ForwardList();
	this->size = other.size;
	this->Head = other.Head;
	other.Head = nullptr;
	cout << "MoveConstructor:\t" << this << endl;
}
ForwardList::~ForwardList()
{
	while (Head) pop_front();
	cout << "ListDestructor:\t" << this << endl;
}
// OPERATORS
ForwardList& ForwardList::operator = (const ForwardList& other)
{
	if (this == &other) return *this;
	this->~ForwardList();
	for (Element* temp = other.Head; temp; temp = temp->pNext)
	{
		push_back(temp->Data);
	}
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
ForwardList& ForwardList::operator = (ForwardList&& other)
{
	this->~ForwardList();
	this->size = other.size;
	this->Head = other.Head;
	other.Head = nullptr;
	cout << "MoveAssignment:\t" << this << endl;
	return *this;
}
int& ForwardList::operator [] (int index)
{
	if (index < 0 || index >= Element::count) throw std::exception("Задан неверный индекс!");
	Element* temp = Head;
	for (int i = 0; i < index; i++)
	{
		temp = temp->pNext;
	}
	return temp->Data;
}
// Adding elements
void ForwardList::push_front(int Data)
{
	Head = new Element(Data, Head);
	size++;
}
void ForwardList::push_back(int Data)
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
void ForwardList::insert(int Data, int index)
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
void ForwardList::pop_front()
{
	if (Head == nullptr) return;
	Element* temp = Head;	// 1) Запоминаем адрес удаляемого элемента
	Head = Head->pNext;		// 2) Исключаем элемент из списка
	delete temp;			// 3) Удаляем элемент из памяти
	size--;
}
void ForwardList::pop_back()
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
void ForwardList::erase(int index)
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
void ForwardList::print() const
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
	/*for(Element* temp = Head; temp; temp = temp->pNext)*/
	for (Iterator temp = Head; temp != nullptr; ++temp)
	{
		//cout /*<< temp*/ << "\t" << temp->Data << "\t" << temp->pNext << endl;
		cout << *temp << '\t' << endl;

	}
	cout << endl;
	cout << "В списке " << size << " элементов." << endl;
	cout << "Общее количество элементов: " << Element::count << endl;
}

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
	ForwardList list2;
	list2 = list;
	cout << list2 << endl;
	ForwardList list3;
	list3 = { 2, 4, 6 };
	cout << list3 << endl;
	//list.print();
	// Range based for
	/*for (int i : list)
		cout << i << '\t';
	cout << endl;*/
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
	try
	{
		cout << index << "-й элемент списка равен " << list[index] << endl;
		list[2] = 99;
		cout << list << endl;
	}
	catch (std::exception e)
	{
		std::cerr << e.what() << endl;
	}*/

}