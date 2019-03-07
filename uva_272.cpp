#include <iostream>
#include <string>
using namespace std;

void convertString(string& input) {
	//1.Replace the first " with ``
	//2.Remove the second " with ''
	//cout<<input;
	auto found = input.find_first_of("\"");
	while(found != std::string::npos) {
		input.replace(found,1,"``");
		found = input.find_first_of("\"");
		//cout<<input;
		input.replace(found,1,"''");
		found = input.find_first_of("\"");
	}
}

int main() {
	string input;
	while(getline(cin, input)) {
		convertString(input);
		cout<<input<<"\n";
	}
	return 0;
}
