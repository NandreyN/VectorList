#include<iostream> 
#include "CustomList.h"
#include<algorithm>
using namespace std;
using CustomListComponents::CustomList;

int main()
{
	CustomList<int> list;

	for (int i = 0; i < 6; i++)
	{
		list.add(i);
	}
	for (int i = 0; i < 5; i++)
		cout << list.remove() << endl;

	while (list.begin() != list.end())
	{
		cout << list.remove() << endl;
	}
	auto it = list.begin();
	it.setData(100500);
	cout << list.remove() << endl;
	return 0;
}