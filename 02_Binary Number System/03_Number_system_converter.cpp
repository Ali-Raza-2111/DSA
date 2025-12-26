#include <iostream>
#include <string>
using namespace std;

// Function prototypes (students will implement these)
string binaryToDecimal(string bin);
string decimalToBinary(string dec);
string decimalToHex(string dec);
string hexToDecimal(string hex);
string binaryToHex(string bin);
string hexToBinary(string hex);

int main() {
    string number;
    string sourceSystem, targetSystem;

    cout << "Enter the number: ";
    cin >> number;

    cout << "Enter source system (Binary / Decimal / Hexadecimal): ";
    cin >> sourceSystem;

    cout << "Enter target system (Binary / Decimal / Hexadecimal): ";
    cin >> targetSystem;

    string result;

    // Students will complete this logic
    if (sourceSystem == "Binary" && targetSystem == "Decimal") {
        result = binaryToDecimal(number);
    }
    else if (sourceSystem == "Decimal" && targetSystem == "Binary") {
        result = decimalToBinary(number);
    }
    else if (sourceSystem == "Decimal" && targetSystem == "Hexadecimal") {
        result = decimalToHex(number);
    }
    else if (sourceSystem == "Hexadecimal" && targetSystem == "Decimal") {
        result = hexToDecimal(number);
    }
    else if (sourceSystem == "Binary" && targetSystem == "Hexadecimal") {
        result = binaryToHex(number);
    }
    else if (sourceSystem == "Hexadecimal" && targetSystem == "Binary") {
        result = hexToBinary(number);
    }
    else {
        cout << "Invalid conversion selected!" << endl;
        return 0;
    }

    cout << number << " (" << sourceSystem << ") = "
         << result << " (" << targetSystem << ")" << endl;

    return 0;
}

// Students will implement these functions
string binaryToDecimal(string bin) {
    int n = stoi(bin);
    int decNum = 0; //1 
    int pow = 1; //2   

    while (n>0)
    {
        int lastDig = n%10;
        decNum += lastDig *pow;
        pow *=2;
        n/=10;
    }
    return to_string(decNum);
}

string decimalToBinary(string dec) {
    int n = stoi(dec);
    int pow = 1;
    int binNum = 0;

    while (n>0)
    {
        int rem = n % 2;
        binNum += rem *pow;
        pow *=10;
        n/=2;
    }
    
    return to_string(binNum);
}

string decimalToHex(string dec) {
    int n = stoi(dec);
    string HexNum = "";
    int rem;
    while (n>0)
    {
        rem = n %16;
        n = n/16;
        if (rem == 10)
        {
            HexNum.insert(0,"a");
        }else if(rem == 11){
            HexNum.insert(0,"b");
            
        }
        else if (rem == 12)
        {
            HexNum.insert(0,"c");
            
        }else if (rem == 13)
        {
            HexNum.insert(0,"d");
        }else if (rem == 14)
        {
            HexNum.insert(0,"e");
        }else if(rem == 15){
           HexNum.insert(0,"f");
        }else{
            string n = to_string(rem);
            HexNum.insert(0,n);
        }
    }
    
    return HexNum;
}

string hexToDecimal(string hex) {
    int decNum = 0;
    int base = 1; 

    
    for (int i = hex.size() - 1; i >= 0; i--) {
        char c = hex[i];
        int value;

        if (c >= '0' && c <= '9')
            value = c - '0';
        else if (c >= 'A' && c <= 'F')
            value = c - 'A' + 10;
        else if (c >= 'a' && c <= 'f')
            value = c - 'a' + 10;
        else
            throw invalid_argument("Invalid hex digit");

        decNum += value * base;
        base *= 16;
    }

    return to_string(decNum);
}

string binaryToHex(string bin) {
    
    string dec = binaryToDecimal(bin);
    return decimalToHex(dec);
}


string hexToBinary(string hex) {
    string dec = hexToDecimal(hex);
    return decimalToBinary(dec);
}