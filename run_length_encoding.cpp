#include <iostream>
#include <string>

using namespace std;

int main() {
	string str; /*= "abbccd";*/
	getline(cin, str);
	cout << "Str= " << str << endl;
	char prev = str[0];
	int count = 1;

	for (int i = 1; i < str.size(); i++) {
		if (str[i] == prev) {
			++count;
		}
		else {
			cout << prev << count;
			count = 1;
		}
		prev = str[i];
	}
	cout << prev << count;

	cout << endl;
	return 0;
}
