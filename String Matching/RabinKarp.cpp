#include <iostream>
#include <cmath>
#include <typeinfo>
using namespace std;

void RabinKarpMatch(string input, string pattern, int d, int q) {
	int n = input.length(), m = pattern.length(), n_val = 0, m_val = 0;

	//PREPROCESSING
	for(int i = 0; i < m; i++) {
		n_val += input.at(i) * pow(d, m-1-i);
		m_val += pattern.at(i) * pow(d, m-1-i);
	}

	//MATCHING
	for(int i = 0; i < n - m + 1; i++) {
		int flag = 1;
		if(n_val == m_val) {
			for(int j = 0; j < m; j++) {
				if(pattern.at(j) != input.at(i+j)) {
					flag = 0;
					break;
				}
			}
			if(flag == 1) {
				cout << "Valid Shift at s = " << i << endl;
			}
		}
		if(i < n - m) {
			n_val = (n_val - (input.at(i) * pow(d, m-1))) * d + input.at(i+m); 
		}
	}

}

int main() {

	string input = "31415926532645678765434567876543456765434567826345432456362626264567654567654678765678765678494857252537596505473554589793", pattern = "56";
	int d = 10, q = 11;

	RabinKarpMatch(input, pattern, d, q);

	return 0;
}