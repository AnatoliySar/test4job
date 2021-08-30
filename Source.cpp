#include <iostream>
#include <list>
using namespace std;

list<pair<string, string>> foo(list<pair<string, string>> a)
{
	list<pair<string, string>> out;
	bool flag = true;
	
	for (auto i = a.begin(); i != a.end(); i++)
	{
		flag = true;
		for (auto j = out.begin(); j != out.end(); j++)
		{			
			if (j->first == i->first && i->second == j->second || j->first == i->second && i->second == j->first)
			{
				flag = false;
				break;
			}
		}
		if (flag == true)
		{
			out.push_back(*i);
		}
	}
	return out;
}

int main()
{
	list<pair<string, string>> in;
	in.push_back(pair<string, string>("Moscow", "Berlin"));
	in.push_back(pair<string, string>("Berlin", "Vienna"));
	in.push_back(pair<string, string>("Moscow", "Berlin"));
	in.push_back(pair<string, string>("Moscow", "Berlin"));
	in.push_back(pair<string, string>("Berlin", "Moscow"));
	in.push_back(pair<string, string>("Moscow", "Berlin"));
	in.push_back(pair<string, string>("Vienna", "Berlin"));
	in.push_back(pair<string, string>("Moscow", "Vienna"));
	in.push_back(pair<string, string>("London", "Vienna"));

	list<pair<string, string>> out = foo(in);

	for (auto i = out.begin(); i != out.end(); i++)
	{
		cout << i->first << " - " << i->second << endl;
	}
	cout << endl;
}