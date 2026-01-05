//convertinus v0.2.2 by jamesananenkovic, on 1.1.2026
//simple conversation software for binary and decimal integers

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int choose;
int output;


// - - - Arayüz İşlemleri - - -

void clearscreen(){
	
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
	
	}

// - - - Yardımcı işlemler - - -

string sekizle(const string& bin){
	
	// Bu işlem sayesinde binary dizileri en fazla sekiz karakterde kalır
	
	string temiz = "";
	
	for (char k : bin){
		if(k == '0' || k == '1')
		temiz += k;
	}
	
	int kalan = temiz.length() % 8;
	if (kalan !=0) {
		
		int eklenecek = 8 - kalan;
		temiz = string(8 - kalan, '0') + temiz;
		
		}
	
	string cikti = "";
	int sayac = 0;
	
	for (size_t i = 0; i < temiz.length(); i += 8) {
		
		cikti += temiz.substr(i,8);
		cikti += "\n";
		}
		
		return cikti;
	}



// - - - UNSIGNED Değerler ile yapılan işlemler - - -


long long xtoii(string binary){ // decimal -> binary
		return stoll(binary, nullptr, 2);
	}

string iitox(long long decimal) { // binary -> decimal
	
	if (decimal == 0) 
		return "00000000";
		
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
		
	string duzenli = sekizle(binary);
	
	if (isNegative)
		return "(-) \n" + duzenli;
	
	return duzenli;
	}
	
	
// - - - SIGNED değerler ile yapılan işlemler - - -

long long iitox_s8(const string& bin){ // binary to decimal
	
	if (bin.size() != 8 )
		return 0;
		
	unsigned char v = 0;
	string out =  "";
	
	for (char c : bin)
		v = (v << 1) | (c - '0');
		
	return static_cast<signed char>(v);
	
	}
	

string xtoii_s8(long long decimal){
	
    string out = "";
    bool isNegative = decimal < 0;
    unsigned long long num = isNegative ? -decimal : decimal;

    vector<string> blocks;

    // 8-bit bloklar oluştur
    do {
        string block = "";
        
        for(int i = 0; i < 8; ++i){
            block = ((num & 1) ? '1' : '0') + block;
            num >>= 1;
        }
        blocks.push_back(block);
    } while(num > 0);

    reverse(blocks.begin(), blocks.end());

    // blokları stringe ekle
    for(size_t i = 0; i < blocks.size(); ++i){
        out += blocks[i];
        if(i != blocks.size()-1) out += "-";
    }

    if(isNegative)
        out = "(- " + out + ")";

    return out;
}


int main(){
	
	while (true){
		
		clearscreen();
		
		cout << "|- - - - - - - - CONVERTINUS - - - - - - - -|\n";
		cout << "|                                           |\n";
		cout << "|- UNSIGNED - - - - - - - = - - - - SIGNED -|\n";
		cout << "|  |1|        binary  -> decimal       |3|  |\n";
		cout << "|  |2|        decimal -> binary        |4|  |\n";
		cout << "|                                           |\n";
		cout << "|                Exit: |0|                  |\n";
		cout << "|                                           |\n";
		cout << "select progress>>>";	
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
			
		else if (choose == 3){
			
			string deger;
			cin >> deger;
			
			if(deger.size() !=8){
				
				cout << "ERROR! INPUT MUST BE 8 BIT WIDE!\n";
				
				}
				
			else{
				
				long long sonuc = iitox_s8(deger);
				cout << "(" << sonuc << ")\n";
				
				}
			
			}
			
			
		else if (choose == 4){
			
			long long deger;
			cin >> deger;
			string sonuc = xtoii_s8(deger);
			cout << sonuc << "\n";
			
			}
			
		else if (choose == 0) {
			return 0;
			}
			
		cout << endl << "Press Enter to continue... ";
		cin.ignore();
		cin.get();
		
		
		}
		return 0;
}
