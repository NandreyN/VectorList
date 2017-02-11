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

	Vector<int>::iterator begin = vector.begin();
	*begin = 22;
	//vector.clear();
	begin = vector.begin();

	while(begin != vector.end())
	{
		cout << *begin << endl;
		++begin;
	}
	//cout << vector.pop_back() << endl;
	cout << vector.at(0) << endl;
	cout << vector.at(1) << endl;
	cout << vector.at(2) << endl;
	cout << vector.at(3) << endl;
	return 0;
}