#include <iostream>
#include <vector>

using namespace std;

class mystr
{
private:
	vector<char> str;
public:
	void input();
	void output();
	void search();
	void remove();
};

void mystr::input()
{
	char a = 0;
	while (1)
	{
		a = getchar();
		if (a == '\n')
			break;
		str.push_back(a);
	}
	
}

void mystr::output()
{
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i];
	}
	cout << endl;
}

void mystr::search()
{
	vector<int> ans;
	mystr b;
	b.input();
	for (int j = 0; j < str.size() - b.str.size() + 1; j++)
	{
		for (int k = 0; k < b.str.size(); k++)
		{
			if (str[j + k] != b.str[k])
				break;
			if (k == b.str.size() - 1)
			    ans.push_back(j);
		}
	}
	cout << "str: ";
	b.output();
	cout << "ans: " << ans.size() << " - " << "(";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i];
		if (i != ans.size() - 1)
			cout << ",";
	}
	cout << ")" << endl;
}

void main()
{
	cout << "Please enter a string.\n";
	mystr i;
	i.input();
	int j;
	while (1)
	{

		cout << "S: ";
		i.output();
		cout << endl;
		cout << "1.Frequecy\n" << "2.CharacterDelete\n" << endl;
		cin >> j;
		getchar(); //remove'\n'
		if(j == 1)
			i.search();
		if (j == 2)
			i.remove();
	}
}

void mystr::remove()
{
	mystr c;
	c.input();
	for (int j = 0; j < str.size() - c.str.size() + 1; j++)
	{
		for (int k = 0; k < c.str.size(); k++)
		{
			if (str[j + k] != c.str[k])
				break;
			if (k == c.str.size() - 1)
			{
				str.erase(str.begin() + j, str.begin() + j + k + 1);
			}
		}
	}
	cout << "str: ";
	c.output();
	cout << "ans: ";
	output();
	cout << endl;
}