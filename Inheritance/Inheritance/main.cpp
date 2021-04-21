#include <iostream>
using namespace std;

class Box
{
	double width;
	double height;
	double length;
	string material;
public:
	double get_width() const
	{
		return width;
	}
	double get_height() const
	{
		return height;
	}
	double get_length() const
	{
		return length;
	}
	const string& get_material() const
	{
		return material;
	}
	// Constructors
	Box(double width, double height, double length, const string& material):
		width(width), height(height), length(length), material(material)
	{
		cout << "Box Constructor:\t\t" << this << endl;
	}
	~Box()
	{
		cout << "Box Destructor:\t\t" << this << endl;
	}
	// Methods
	void info() const
	{
		cout << "Dimensions: " << width << " x " << height << " x " << length << endl;
		cout << "Material: " << material << endl;
	}
};

class GiftBox :public Box
{
	string cover;
public:
	const string& get_cover()
	{
		return cover;
	}
	GiftBox(double width, double height, double length, const string& material, const string& cover) :Box(width, height, length, material)
	{
		this->cover = cover;
		cout << "GiftBox Constructor:\t" << this << endl;
	}
	~GiftBox()
	{
		cout << "GiftBox Destructor:\t" << this << endl;
	}
	// Methods
	void info() const
	{
		Box::info();
		cout << "Cover:\t" << cover << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "");
	//Box box(2, 5, 8, "Cardboard");
	//box.info();
	GiftBox giftbox(2, 5, 8, "Cardboard", "Cats & Mice");
	giftbox.info();
}