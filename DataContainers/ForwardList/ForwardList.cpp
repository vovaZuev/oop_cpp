#include "ForwardList.h"

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