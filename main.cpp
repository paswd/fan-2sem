#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

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

	void Clear(void) {
		this->Name = "";
		this->Value = "";
	}
};

typedef enum {
	NAME,
	VALUE
} TState;

void ReadFromFile(vector <TTerm> *arr) {
	arr->resize(0);

	ifstream fin("in.txt");
	string tmp;
	TTerm term_tmp;

	int ch;
	TState state = NAME;
	bool empty = true;
	while ((ch = fin.get()) != EOF) {
		switch (state) {
			case NAME:
				if (ch == '\n') {
					if (term_tmp.Name == "") {
						break;
					}
					state = VALUE;
				} else {
					term_tmp.Name += (char) ch;
					empty = false;
				}
				break;

			case VALUE:
				if (ch == '@') {
					arr->push_back(term_tmp);
					term_tmp.Clear();
					state = NAME;
					empty = true;
				} else {
					term_tmp.Value += (char) ch;
				}
				break;
		}
	}
	if (!empty) {
		arr->push_back(term_tmp);
	}
	fin.close();
}

void pause(void)
{
    string s;
    //cout << "\nPress the Enter key show correct answer....\n";
    cin >> s;
}

int main(void)
{
	setlocale(LC_ALL, "russian");
	time_t timet;
	srand((unsigned) time(&timet));

	vector <TTerm> terms(0);

	cout << "Import from file:" << endl;
	ReadFromFile(&terms);
	cout << "OK" << endl;

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