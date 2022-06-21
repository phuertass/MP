#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

int main()
{
	string cad;
	int numero;

	getline(cin, cad);

	while (!cin.eof())
	{
		istringstream iss;
		iss.str(cad);
		iss >> numero;
		while (!iss.eof())
		{
			if (iss.fail())
			{
				iss.clear();
				iss.ignore(100, ' ');
			}
			else
				cout << setw(10) << numero;

			iss >> numero;
		}

		cout << endl;

		getline(cin, cad);
	}

	return 0;
}