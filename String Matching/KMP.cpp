#include <iostream>
#include <cstring>
using namespace std;

void computePrefixFunction(string pattern, int prefix[]) {
	int i , j = 0;
	prefix[0] = 0;
	for(int i = 1; i < pattern.length(); i++) {		
		if(j > 0 && pattern[j] != pattern[i]) {
			j = prefix[j-1];
		}
		if(pattern[j] == pattern[i]) {
			j++;
		}
		prefix[i] = j;
	}
}

void KMP(string input, string pattern) {
	//PREPROCESSING
	int n = input.length(), m = pattern.length();
	int prefix[m];
	computePrefixFunction(pattern, prefix);

	//STRING MATCHING
	int j = 0;
	for(int i = 0; i < n; i++) {
		if(j > 0 && input[i] != pattern[j]) {
			j = prefix[j-1];
		}
		if(input[i] == pattern[j]) {
			j++;
		}
		if(j == m) {
			cout << "Valid Shift at s = " << i-(m-1) << endl;
			j = prefix[j-1];
		}

	}
}

int main() {
	string input = "31415926532645678765434567876543456765434567826345432456362626264567654567654678765678765678494857252537596505473554589793", pattern = "56";
	
	KMP(input, pattern);
	
	return 0;
}
