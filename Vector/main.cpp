#include<iostream> 
#include "CustomVector.h"
#include<algorithm>
using namespace std;

int main()
{
	Vector<int> vector;
	

	Vector<int>::iterator begin = vector.begin();
	//vector.clear();
	vector.push_front(123);

	begin = vector.begin();

	while(begin != vector.end())
	{
		cout << *begin << endl;
		++begin;
	}
	vector.clear();
	return 0;
}