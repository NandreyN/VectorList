#include<iostream> 
#include "CustomVector.h"
#include<algorithm>
using namespace std;

int main()
{
	Vector<int> vector;
	

	Vector<int>::iterator begin = vector.begin();
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);
	cout << vector.pop_front() << endl;
	return 0;
}