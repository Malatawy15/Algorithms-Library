#include <iostream>

#include <string>
using namespace std;

int main(void)
{
	int n;
	
	string line;
	
	cin >> n;
	getline(cin, line);//flush \n
	
	for (int i = 1; i <= n; i++)
	{
		getline(cin, line);
		cout << line[line.size()-1] << endl;
	
	}
	
	return 0;
}