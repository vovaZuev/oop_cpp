#include <iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

template <typename T> class Iterator;
template <typename T> class ForwardList;
template <typename T>
class Element
{
	T Data; // значение эл-та
	Element* pNext; // указатель на следующий элемент
	static int count;
public:
	const T get_data() const
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
	Element(T Data, Element* pNext = nullptr) : Data(Data), pNext(pNext)
	{
		count++;
		//cout << "ElementConstructor:\t" << this << endl;
	}
	~Element()
	{
		count--;
		//cout << "ElementDestructor:\t" << this << endl;
	}
	friend class ForwardList<T>;
	friend class Iterator<T>;
};

template <typename T>
int Element<T>::count = 0; // инициализация статической переменной

template <typename T>
class Iterator
{
	Element<T>* Temp;
public:
	Iterator(Element<T>* Temp = nullptr) : Temp(Temp)
	{
		cout << "IConstructor:\t" << this << endl;
	}
	~Iterator()
	{
		cout << "IDestructor:\t" << this << endl;
	}
	// Operators
	Iterator& operator++()
	{
		Temp = Temp->pNext;
		return *this;
	}
	Iterator operator++(int)
	{
		Iterator old = *this;
		Temp = Temp->pNext;
		return old;
	}
	bool operator == (const Iterator& other) const
	{
		return this->Temp == other.Temp;
	}
	bool operator != (const Iterator& other) const
	{
		return this->Temp != other.Temp;
	}
	const Element<T>* operator -> () const
	{
		return Temp;
	}
	Element<T>* operator -> ()
	{
		return Temp;
	}
	const T& operator*() const
	{
		return Temp->Data;
	}
	T& operator*()
	{
		return Temp->Data;
	}
};

template <typename T>
class ForwardList
{
	unsigned int size;
	Element<T>* Head; // указатель на начальный элемент списка
public:
	const unsigned int get_size() const
	{
		return size;
	}
	const Element<T>* get_head() const
	{
		return Head;
	}
	Iterator<T> begin()
	{
		return Head;
	}
	Iterator<T> end()
	{
		return nullptr;
	}
	// CONSTRUCTORS
	ForwardList()
	{
		this->size = 0;
		this->Head = nullptr;
		cout << "ListConstructor:\t" << this << endl;
	}
	// Initializer list constructor
	ForwardList(const std::initializer_list<T>il) : ForwardList()
	{
		//cout << typeid(il.begin()).name() << endl;
		for (const T* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
		cout << "ILConstructor:\t" << this << endl;
	}
	// Copy Constructor
	ForwardList(const ForwardList& other) : ForwardList()
	{
		for (Element<T>* temp = other.Head; temp; temp = temp->pNext)
		{
			push_back(temp->Data);
		}
		cout << "CopyConstructor:\t" << this << endl;
	}
	// Move Constructor
	ForwardList(ForwardList&& other)
	{
		this->~ForwardList<T>();
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
	ForwardList<T>& operator = (const ForwardList<T>& other)
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
	ForwardList<T>& operator = (ForwardList<T>&& other)
	{
		this->~ForwardList();
		this->size = other.size;
		this->Head = other.Head;
		other.Head = nullptr;
		cout << "MoveAssignment:\t" << this << endl;
		return *this;
	}
	T& operator [] (int index)
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
	void push_front(T Data)
	{
		Head = new Element<T>(Data, Head);
		size++;
	}
	void push_back(T Data)
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
	void insert(T Data, int index)
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
	void pop_front()
	{
		if (Head == nullptr) return;
		Element<T>* temp = Head;	// 1) Запоминаем адрес удаляемого элемента
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
		Element<T>* temp = Head;
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
		/*for(Element* temp = Head; temp; temp = temp->pNext)*/
		for (Iterator<T> temp = Head; temp != nullptr; ++temp)
		{
			//cout /*<< temp*/ << "\t" << temp->Data << "\t" << temp->pNext << endl;
			cout << *temp << '\t' << endl;
			
		}
		cout << endl;
		cout << "В списке " << size << " элементов." << endl;
		cout << "Общее количество элементов: " << Element::count << endl;
	}
};
// CONCATENATION

template <typename T>
ForwardList<T> operator + (const ForwardList<T>& left, const ForwardList<T>& right)
{
	ForwardList<T> result = left;
	for (const Element<T>* temp = right.get_head(); temp; temp = temp->get_pnext())
	{
		result.push_back(temp->get_data());
	}
	return result;
}
// OSTREAM
template <typename T>
ostream& operator << (ostream& os, ForwardList<T>& obj)
{
	for (const Element<T>* temp = obj.get_head(); temp; temp = temp->get_pnext())
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

	ForwardList<int> list = {3, 5, 8, 13, 21};
	//list.print();
	// Range based for
	for (int i : list)
		cout << i << '\t';
	cout << endl;
	cout << delim << endl;

	ForwardList<double> dfl = { 2.4, 3.7, 5.2, 2.9, 6.7 };
	for (double i : dfl) cout << i << '\t'; cout << endl;
	//cout << dfl << endl;
	cout << delim << endl;

	ForwardList<std::string> stih = {"Хорошо", "живет", "на", "свете", "Винни", "Пух"};
	for (std::string i : stih) cout << i << '\t'; cout << endl;
	//cout << stih << endl;
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