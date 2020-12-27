//Find the Nth after removing all numbers containing one nine digit or more
//Incomplete program

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

//Nine digit number count method
int nineDigits(unsigned int pos, unsigned int len) {

    if (len - pos == 1) {
        return 0;

    }
    else if(len>pos) {
        double exp = len - pos;
        pos += 1;
        return 9 * nineDigits(pos, len) + (int)pow(exp, 10);

    }
    
}

//Method to return Nth number after removing all nine digit numbers

int findNth(int N) {
    string str;
    int subtract = 0;
    str = to_string(N);

    for (unsigned int i = 0; i < str.length(); ++i) {
        if (str[i] == '9') {           
             subtract += ((int)(str[i]) - 48) * nineDigits(i, str.length());

             for (int j = 0; j < str.length(); ++j) {
                 subtract += ((int)str[j] - 48) * (int)pow((double)j, 10);

             }
                     
        }
        else if(str[i] != 0) {
            subtract += ((int)(str[i])-48)* nineDigits(i, str.length());

        }
        else if (str[i] == 0) {
            subtract += nineDigits(i, str.length());

        }
    }
    return stoi(str) - subtract;
    
   
}
    



int main()
{
    int choice;
    choice = 0;
    int number;
    while (choice != 9) {
        cout << "Enter a number" << endl;
        cin >> number;
        cout << nineDigits(1,3) << endl;
        cout << "Enter a choice" << endl;
        cin >> choice;
    }
    return 0;

}

