#include<iostream> 
#include "CustomVector.h"
#include<algorithm>
using namespace std;

int main()
{
	Vector<int> vector;
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);
	vector.insert(3,444);
	vector.push_back(5);

	Vector<int>::iterator begin = vector.begin();
	while (begin != vector.end())
	{
		cout << *begin << endl;
		++begin;
	}
	return 0;
}