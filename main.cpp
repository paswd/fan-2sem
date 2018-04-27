#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void pause(void)
{
    string s;
    //cout << "\nPress the Enter key show correct answer....\n";
    cin >> s;
}

class TTerm {
public:
	string Name;
	string Value;

	TTerm(void) {
		this->Name = "";
		this->Value = "";
	}
	TTerm(string name, string val) {
		this->Name = name;
		this->Value = val;
	}
};

int main(void)
{
	setlocale(LC_ALL, "russian");
	time_t timet;
	srand((unsigned) time(&timet));

	vector <TTerm> terms(0);
	terms.push_back(TTerm("a", "aa"));
	terms.push_back(TTerm("b", "bb"));


	//cout << words[0][1] << endl;
	int numold = -1;
	while (true) {
		int num;
		do {
			num = rand() % terms.size();
		} while (num == numold);
		cout << "-----------------------" << endl;
		cout << terms[num].Name << endl;
		pause();
		cout << terms[num].Value << endl << endl;
		numold = num;
	}
	return 0;
}