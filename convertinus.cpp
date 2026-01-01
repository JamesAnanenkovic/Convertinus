//convertinus v0.1 by jamesananenkovic, on 1.1.2026
//simple conversation software for binary and decimal integers

#include <iostream>
using namespace std;

int choose;
int output;

string iitox(long long decimal) {
	
	if (decimal == 0) return "0";
	string binary = "";
	long long num = decimal;
	bool isNegative = false;
	if (num < 0) {
		isNegative = true;
		num = -num;
		}
	while (num > 0) {
		binary = to_string(num % 2) + binary;
		num /= 2;
		}
	return isNegative ? "-" + binary : binary;
	}

long long xtoii(string binary){
		return stoll(binary, nullptr, 2);
	}


int main(){
	
	while (true){
		cout << "- - - CONVERTINUS - - -\n";
		cout << "|0|  çıkış - exit		\n";
		cout << "|1|  binary  -> decimal\n";
		cout << "|2|  decimal -> binary \n";
		
		cin >> choose;
		
		if (choose == 1){
			
			string deger;
			cin >> deger;
			string output = to_string(xtoii(deger));
			cout << output << "\n";
			
			}
			
		else if (choose == 2){
			
			long long deger;
			cin >> deger;
			string output = iitox(deger);
			cout << output << "\n";
			
			}
			
		else if (choose == 0) {
			return 0;
			}
		}
		return 0;
}
