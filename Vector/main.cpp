#include<iostream> 
#include "CustomVector.h"
#include<algorithm>
using namespace std;

int main()
{
	Vector<int> vector;
	for (int i = 0; i < 10; i++)
		vector.push_back(i);
	for (int i = 10; i < 15; i++)
		vector.push_front(i);

	//for_each(vector.begin(), vector.end(), [](auto a) {cout << a << endl; });
	copy(vector.begin(), vector.end(), ostream_iterator<int>(cout, "\n"));

	cout << "-------------------------------------------------------------------------------" << endl;
	vector.pop_back();
	vector.pop_front();
	copy(vector.begin(), vector.end(), ostream_iterator<int>(cout, "\n"));
	cout << "Size = " << vector.size() << endl;
	cout << "[5]" << vector[5] << endl;
	vector.insert(5, 555);

	cout << "--------------------------------------------------------------------------------" << endl;
	copy(vector.begin(), vector.end(), ostream_iterator<int>(cout, "\n"));


	return 0;
}