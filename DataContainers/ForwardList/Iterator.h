#pragma once
class Iterator
{
	Element* Temp;
public:
	Iterator(Element* Temp = nullptr) : Temp(Temp);
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