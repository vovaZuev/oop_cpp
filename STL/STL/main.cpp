#include <iostream>
#include <array>
#include <vector>
using namespace std;

#define tab " "
#define delim "\n*****************************************************************\n\n"
//#define stl_array
#define stl_vector
//#define stl_vector_insert
//#define vector_swap

template <typename T> void vector_properties(const vector<T>& vec);
template <typename T> void print_vector(const vector<T>& vec);

int main()
{
	setlocale(LC_ALL, "");
#ifdef stl_array
	// Array - это контейнер, который хранит данные в виде статического массива
	array<int, 5> arr = {3, 5, 8, 13, 21};
	for (int i = 0; i < arr.size(); i++)
	{
		//cout << arr[i] << tab;
		cout << arr.at(i) << tab;
	}
	cout << endl;
	cout << arr.front() << endl;
	cout << arr.back() << endl;
	cout << *arr.data() << endl;
	arr.fill(123);
	for (int i : arr)
		cout << i << tab;
#endif
#ifdef stl_vector
	// vector - это контейнер, который хранит данные в виде динамического массива
	vector<int> vec = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
	vec.push_back(55);
	vector_properties(vec);
	try
	{
		for (int i = 0; i < vec.capacity(); i++)
		{
			cout << vec.at(i) << tab;
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	vec.reserve(45);
	//vec.shrink_to_fit();
	vector_properties(vec);
	for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
	vec.assign({1024, 2048, 3072});
	cout << delim;
	print_vector(vec);
#endif
#ifdef stl_vector_insert
	int index;
	int count;
	int value;
	do
	{
		cout << "¬ведите индекс добавл€емого элемента:"; cin >> index;
		if (index > vec.size()) cout << "¬ведите меньшее значение.\n";
	} while (index > vec.size());
	cout << "¬ведите количество добавл€емых элементов:"; cin >> count;
	cout << "¬ведите значение добавл€емого элемента:"; cin >> value;
	vector<int>::iterator position = vec.begin() + index;
	vec.insert(position, count, value);
	for (int i : vec)
		cout << i << tab;
	cout << endl;
	vector_properties(vec);
#endif // stl_vector_insert
	/*cout << delim;
	vec.insert(vec.begin() + 5, {1024, 2048, 3072, 4096});
	print_vector(vec);
	cout << delim;
	vector<int> vec2;
	cout << "Empty vector takes " << sizeof(vec) << " bytes" << endl;*/
#ifdef vector_swap
	vector<int> vec1 = { 3, 5, 8, 13, 21 };
	vector<int> vec2 = { 34, 55, 89 };
	print_vector(vec1);
	print_vector(vec2);
	vec1.swap(vec2);
	cout << delim;
	print_vector(vec1);
	print_vector(vec2);
#endif // vector_swap

}

template <typename T> void vector_properties(const vector<T>& vec)
{
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;
	cout << vec.max_size() << endl;
}
template <typename T> void print_vector(const vector<T>& vec)
{
	for (int i : vec) cout << i << tab; cout << endl;
}