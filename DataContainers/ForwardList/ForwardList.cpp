#include "ForwardList.h"

template <typename T> const unsigned int ForwardList<T>::get_size() const
{
	return size;
}
template <typename T> const Element<T>* ForwardList<T>::get_head() const
{
	return Head;
}
template <typename T> Iterator<T> ForwardList<T>::begin()
{
	return Head;
}
template <typename T> Iterator<T> ForwardList<T>::end()
{
	return nullptr;
}
// CONSTRUCTORS
template <typename T> ForwardList<T>::ForwardList()
{
	this->size = 0;
	this->Head = nullptr;
	cout << "ListConstructor:\t" << this << endl;
}
// Initializer list constructor
template <typename T> ForwardList<T>::ForwardList(const std::initializer_list<T>il) : ForwardList()
{
	//cout << typeid(il.begin()).name() << endl;
	for (const T* it = il.begin(); it != il.end(); it++)
	{
		push_back(*it);
	}
	cout << "ILConstructor:\t" << this << endl;
}
// Copy Constructor
template <typename T> ForwardList<T>::ForwardList(const ForwardList& other) : ForwardList()
{
	for (Element<T>* temp = other.Head; temp; temp = temp->pNext)
	{
		push_back(temp->Data);
	}
	cout << "CopyConstructor:\t" << this << endl;
}
// Move Constructor
template <typename T> ForwardList<T>::ForwardList(ForwardList&& other)
{
	this->~ForwardList<T>();
	this->size = other.size;
	this->Head = other.Head;
	other.Head = nullptr;
	cout << "MoveConstructor:\t" << this << endl;
}
template <typename T> ForwardList<T>::~ForwardList()
{
	while (Head) pop_front();
	cout << "ListDestructor:\t" << this << endl;
}
// OPERATORS
template <typename T> ForwardList<T>& ForwardList<T>::operator = (const ForwardList<T>& other)
{
	if (this == &other) return *this;
	this->~ForwardList();
	for (Element<T>* temp = other.Head; temp; temp = temp->pNext)
	{
		push_back(temp->Data);
	}
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
template <typename T> ForwardList<T>& ForwardList<T>::operator = (ForwardList<T>&& other)
{
	this->~ForwardList();
	this->size = other.size;
	this->Head = other.Head;
	other.Head = nullptr;
	cout << "MoveAssignment:\t" << this << endl;
	return *this;
}
template <typename T> T& ForwardList<T>::operator [] (int index)
{
	if (index < 0 || index >= Element<T>::count) throw std::exception("Задан неверный индекс!");
	Element<T>* temp = Head;
	for (int i = 0; i < index; i++)
	{
		temp = temp->pNext;
	}
	return temp->Data;
}
// Adding elements
template <typename T> void ForwardList<T>::push_front(T Data)
{
	Head = new Element<T>(Data, Head);
	size++;
}
template <typename T> void ForwardList<T>::push_back(T Data)
{
	if (Head == nullptr)
	{
		push_front(Data);
		return;
	}
	Element<T>* New = new Element<T>(Data);
	Element<T>* temp = Head;
	while (temp->pNext != nullptr)
	{
		temp = temp->pNext;
	}
	temp->pNext = New;
	size++;
}
template <typename T> void ForwardList<T>::insert(T Data, int index)
{
	Element<T>* temp = Head;
	if (index < 0 || index > Element<T>::count) return;
	if (index == 0)
	{
		push_front(Data);
		return;
	}
	Element<T>* New = new Element<T>(Data);
	for (int i = 0; i < index - 1; i++)
	{
		temp = temp->pNext;
	}
	New->pNext = temp->pNext;
	temp->pNext = New;
	size++;
}
// Removing elements
template <typename T> void ForwardList<T>::pop_front()
{
	if (Head == nullptr) return;
	Element<T>* temp = Head;	// 1) Запоминаем адрес удаляемого элемента
	Head = Head->pNext;		// 2) Исключаем элемент из списка
	delete temp;			// 3) Удаляем элемент из памяти
	size--;
}
template <typename T> void ForwardList<T>::pop_back()
{
	if (Head == nullptr) return;
	if (Head->pNext == nullptr)
	{
		pop_front();
		return;
	}
	Element<T>* temp = Head;
	while (temp->pNext->pNext != nullptr)
	{
		temp = temp->pNext;
	}
	delete temp->pNext;
	temp->pNext = nullptr;
	size--;
}
template <typename T> void ForwardList<T>::erase(int index)
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
	Element<T>* temp = Head;
	for (int i = 1; i < index; i++)
	{
		temp = temp->pNext;
	}
	Element<T>* next = temp->pNext->pNext;
	delete temp->pNext;
	temp->pNext = next;
	size--;
}
// Methods
template <typename T> void ForwardList<T>::print() const
{
	for (Iterator<T> temp = Head; temp != nullptr; ++temp)
	{
		cout << *temp << '\t' << endl;

	}
	cout << endl;
	cout << "В списке " << size << " элементов." << endl;
	cout << "Общее количество элементов: " << Element::count << endl;
}
// CONCATENATION

template <typename T> ForwardList<T> operator + (const ForwardList<T>& left, const ForwardList<T>& right)
{
	ForwardList<T> result = left;
	for (const Element<T>* temp = right.get_head(); temp; temp = temp->get_pnext())
	{
		result.push_back(temp->get_data());
	}
	return result;
}
// OSTREAM
template <typename T> ostream& operator << (ostream& os, ForwardList<T>& obj)
{
	for (const Element<T>* temp = obj.get_head(); temp; temp = temp->get_pnext())
	{
		os << temp->get_data() << " ";
	}
	return os;
}