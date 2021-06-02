#include <iostream>
using namespace std;

#define tab '\t'
#define delim "****************************************************\n";

class List
{
	class Element
	{
		int data;
		Element* pPrev;
		Element* pNext;
	public:
		Element(int data, Element* pNext = nullptr, Element* pPrev = nullptr)
		{
			this->data = data;
			this->pPrev = pPrev;
			this->pNext = pNext;
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor:\t" << this << endl;
		}
		friend class List;
		friend List operator + (const List& left, const List& right);
	};
	Element* Head;
	Element* Tail;
	unsigned int size;
public:
	class Iterator
	{
		Element* temp;
	public:
		Iterator(Element* temp = nullptr) : temp(temp)
		{
			cout << "ItConstructor:\t" << this << endl;
		}
		~Iterator()
		{
			cout << "ItDestructor:\t" << this << endl;
		}
		// ********************* Operators **********************************
		Iterator& operator ++ ()
		{
			temp = temp->pNext;
			cout << "PrefixIncrement:\t" << this << endl;
			return *this;
		}
		Iterator& operator ++ (int)
		{
			Iterator old = *this;
			temp = temp->pNext;
			cout << "PostfixIncrement:\t" << this << endl;
			return old;
		}
		Iterator& operator -- ()
		{
			temp = temp->pPrev;
			return *this;
		}
		Iterator& operator -- (int)
		{
			Iterator old = *this;
			temp = temp->pPrev;
			return old;
		}
		bool operator == (const Iterator& other) const
		{
			return this->temp == other.temp;
		}
		bool operator != (const Iterator& other) const
		{
			return this->temp != other.temp;
		}
		const int& operator * () const
		{
			return temp->data;
		}
		int& operator * ()
		{
			return temp->data;
		}
	};
	class ReverseIterator
	{
		Element* temp;
	public:
		ReverseIterator(Element* temp = nullptr) : temp(temp)
		{
			cout << "RevItConstructor:\t" << this << endl;
		}
		~ReverseIterator()
		{
			cout << "RevItDestructor:\t" << this << endl;
		}
		// ********************* Operators **********************************
		ReverseIterator& operator ++ ()
		{
			temp = temp->pPrev;
			cout << "RevItPrefixIncrement:\t" << this << endl;
			return *this;
		}
		ReverseIterator& operator ++ (int)
		{
			ReverseIterator old = *this;
			temp = temp->pPrev;
			cout << "RevItPostfixIncrement:\t" << this << endl;
			return old;
		}
		ReverseIterator& operator -- ()
		{
			temp = temp->pNext;
			cout << "RevItPrefixIncrement:\t" << this << endl;
			return *this;
		}
		ReverseIterator& operator -- (int)
		{
			ReverseIterator old = *this;
			temp = temp->pNext;
			cout << "RevItPostfixIncrement:\t" << this << endl;
			return old;
		}
		bool operator == (const ReverseIterator& other) const
		{
			return this->temp == other.temp;
		}
		bool operator != (const ReverseIterator& other) const
		{
			return this->temp != other.temp;
		}
		const int& operator * () const
		{
			return temp->data;
		}
		int& operator * ()
		{
			return temp->data;
		}
	};
	Iterator begin()
	{
		return Head;
	}
	const Iterator begin() const
	{
		return Head;
	}
	Iterator end()
	{
		return nullptr;
	}
	const Iterator end() const
	{
		return nullptr;
	}
	ReverseIterator rbegin()
	{
		return Tail;
	}
	const ReverseIterator rbegin() const
	{
		return Tail;
	}
	ReverseIterator rend()
	{
		return nullptr;
	}
	const ReverseIterator rend() const
	{
		return nullptr;
	}
	// ******************************* CONSTRUCTORS ******************************************
	List()
	{
		Head = Tail = nullptr;
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	List(const initializer_list<int>& il) : List()
	{
		for (const int* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
	}
	// Defined Size Constructor
	List(int size)
	{
		for (int i = 0; i < size; i++)
		{
			push_front(0);
		}
		cout << "SConstructor:\t" << this << endl;
	}
	// Copy Constructor
	List(const List& other) : List()
	{
		for (Element* temp = other.Head; temp; temp = temp->pNext)
		{
			push_back(temp->data);
		}
		cout << "CopyConstructor:\t" << this << endl;
	}
	// Move Constructor
	List(List&& other)
	{
		this->size = other.size;
		this->Head = other.Head;
		this->Tail = other.Tail;
		other.Head = other.Tail = nullptr;
		cout << "MoveConstructor:\t" << this << endl;
	}
	~List()
	{
		while (Tail) pop_back();
		cout << "LDestructor:\t" << this << endl;
	}
	// ******************************* OPERATORS ******************************************
	// Copy Assignment
	List& operator = (const List& other)
	{
		if (this == &other) return *this;
		this->~List();
		for (Element* temp = other.Head; temp; temp = temp->pNext)
		{
			push_back(temp->data);
		}
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	// Move Assignment
	List& operator = (List&& other)
	{
		this->~List();
		this->size = other.size;
		this->Head = other.Head;
		this->Tail = other.Tail;
		other.Head = other.Tail = nullptr;
		cout << "MoveAssignment:\t" << this << endl;
		return *this;
	}
	// Subscript Operator
	int& operator [] (int index)
	{
		if (index < 0 || index >= size) throw std::exception("Wrong index!");
		Element* temp;
		if (index < size / 2)
		{
			temp = Head;
			for (int i = 0; i < index; i++)
			{
				temp = temp->pNext;
			}
		}
		else
		{
			temp = Tail;
			for (int i = 0; i < size - index - 1; i++)
			{
				temp = temp->pPrev;
			}
		}
		cout << "Non-Const [] operator..." << endl;
		return temp->data;
	}
	const int& operator [] (int index) const
	{
		if (index < 0 || index >= size) throw std::exception("Wrong index!");
		Element* temp;
		if (index < size / 2)
		{
			temp = Head;
			for (int i = 0; i < index; i++)
			{
				temp = temp->pNext;
			}
		}
		else
		{
			temp = Tail;
			for (int i = 0; i < size - index - 1; i++)
			{
				temp = temp->pPrev;
			}
		}
		cout << "Const [] operator..." << endl;
		return temp->data;
	}
	// ****************************** ADD ELEMENTS ****************************************
	void push_front(int data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			Head = Tail = new Element(data);
			size++;
			return;
		}
		Head = Head->pPrev = new Element(data, Head);
		size++;
	}
	void push_back(int data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			Head = Tail = new Element(data);
			size++;
			return;
		}
		Tail = Tail->pNext = new Element(data, nullptr, Tail);
		size++;
	}
	void insert(int data, int index)
	{
		if (index < 0 || index > size) return;
		if (index == size)
		{
			push_back(data);
			return;
		}
		if (index == 0)
		{
			push_front(data);
			return;
		}
		Element* temp;
		if (index < size / 2)
		{
			temp = Head;
			for (int i = 0; i < index; i++)
			{
				temp = temp->pNext;
			}
		}
		else
		{
			temp = Tail;
			for (int i = 0; i < size - index - 1; i++)
			{
				temp = temp->pPrev;
			}
		}
		temp->pPrev = temp->pPrev->pNext = new Element(data, temp, temp->pPrev);
		size++;
	}
	// *************** REMOVE ELEMENTS **********************************
	void pop_front()
	{
		if (Head == Tail)
		{
			delete Head;
			Head = Tail = nullptr;
			size--;
			return;
		}
		Head = Head->pNext;
		delete Head->pPrev;
		Head->pPrev = nullptr;
		size--;
	}
	void pop_back()
	{
		if (Head == Tail)
		{
			delete Head;
			Head = Tail = nullptr;
			size--;
			return;
		}
		Tail = Tail->pPrev;
		delete Tail->pNext;
		Tail->pNext = nullptr;
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
		Element* temp;
		if (index < size / 2)
		{
			temp = Head;
			for (int i = 0; i < index; i++)
			{
				temp = temp->pNext;
			}
		}
		else
		{
			temp = Tail;
			for (int i = 0; i < size - index - 1; i++)
			{
				temp = temp->pPrev;
			}
		}
		temp->pPrev->pNext = temp->pNext;
		temp->pNext->pPrev = temp->pPrev;
		delete temp;
		size--;
	}
	// *************** METHODS ******************************************
	
	void print()
	{
		for (Element* temp = Head; temp; temp = temp->pNext)
		{
			cout << temp << tab << temp->pPrev << tab << temp->data << tab << temp->pNext << endl;
		}
		cout << "Number of elements in the list: " << size << endl;
	}
	void print_reverse()
	{
		for (Element* temp = Tail; temp; temp = temp->pPrev)
		{
			cout << temp << tab << temp->pPrev << tab << temp->data << tab << temp->pNext << endl;
		}
		cout << "Number of elements in the list: " << size << endl;
	}
	friend List operator + (const List& left, const List& right);
};

List operator + (const List& left, const List& right)
{
	List result = left;
	for (int i : right) result.push_back(i);
	return result;
}

int main()
{
	List list1 = {3, 5, 8, 13, 21};
	for (int i : list1)
	{
		cout << i << tab;
	}
	cout << endl;
	cout << delim;
	for (List::Iterator it = list1.begin(); it != list1.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
	cout << delim;
	for (List::ReverseIterator it = list1.rbegin(); it != list1.rend(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
}