#include <iostream>
#include <cstring>
using namespace std;

void NaiveStringMatch(string input, string pattern) {
	for(int i = 0; i < input.length() - pattern.length() + 1; i++) {
		int flag = 1;
		for(int j = 0; j < pattern.length(); j++) {
			if(pattern.at(j) != input.at(i+j)) {
				flag = 0;
				break;
			}
		}
		if(flag == 1) {
			cout << "Valid Shift at s = " << i << endl;
		}
	}
}

int main() {

	string input = "AABAACAADAABAABAABABABABBBBABBAAABAABABABABABABABABABABABABAAAAAABBABBABABBABABABBABBBBABABABABBBABABBBBABABBAAAABAAABBBABBABBABABABABBABABABABBA", pattern = "AABA";

	NaiveStringMatch(input, pattern);

	return 0;

}