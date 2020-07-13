#include "iostream"
#include <bits/stdc++.h>

using namespace std;


/*  
    Adds two decimal digits
*/
string addChar(const char &a, const char &b, bool &carry){
    int ans = (a - '0') + (b - '0') + (carry ? 1 : 0);
    if(ans > 9){
        ans -= 10;
        carry = true;
    }
    else{
        carry = false;
    }

    return to_string(ans);
}

/*
    Subtracts two decimal digits 
*/
string subChar(const char &a, const char &b, bool &borrow){
    int ans = (a - '0') - (b - '0') - (borrow ? 1 : 0);
    if(ans < 0){
        ans += 10;
        borrow = true;
    }
    else{
        borrow = false;
    }

    return to_string(ans);
}

/*
    Adds two decimal strings with carry support
*/
string addStrings(const string &a, const string &b, bool &carry){
    
    string addition = "";
    int ctr_a = a.size() - 1;
    int ctr_b = b.size() - 1;

    while(ctr_a >= 0 && ctr_b >= 0){
        addition = addChar(a[ctr_a], b[ctr_b], carry) + addition;
        --ctr_b;
        --ctr_a;
    }

    while(ctr_a >= 0){
        addition = addChar(a[ctr_a], '0', carry) + addition;
        --ctr_a;
    }

    while(ctr_b >= 0){
        addition = addChar(b[ctr_b], '0', carry) + addition;
        --ctr_b;
    }

    if(carry){
        addition = "1" + addition;
        carry = false;
    }

    return addition;
}


/*
    Subtracts two decimal strings with borrow support
*/
string subStrings(const string &a, const string &b, bool &borrow ){
    
    string subtraction = "";
    int ctr_a = a.size() - 1;
    int ctr_b = b.size() - 1;

    while(ctr_a >= 0 && ctr_b >= 0){
        subtraction = subChar(a[ctr_a], b[ctr_b], borrow) + subtraction;
        --ctr_b;
        --ctr_a;
    }

    while(ctr_a >= 0){
        subtraction = subChar(a[ctr_a], '0', borrow) + subtraction;
        --ctr_a;
    }

    while(ctr_b >= 0){
        subtraction = subChar('0', b[ctr_b], borrow) + subtraction;
        --ctr_b;
    }

    return subtraction;
}

/*
    Multiply two numbers using Karatsuba algorithm
    X = a * 10^m + b
    Y = c * 10^m + d

    X . Y = a*c * 10^(2m) + (a*d + b*c) * 10^m + b*d
*/
string multiplyStrings(string &s1, string &s2) {
    
    // Equalizing length of both strings by pending zeroes
    if(s1.size() != s2.size()){
        if(s1.size() > s2.size()){
            s2 = string(s1.size() - s2.size(), '0') + s2;
        }
        else{
            s1 = string(s2.size() - s1.size(), '0') + s1;
        }
    }

    // Base case
    if(s1 == "" || s2 == ""){
        return "";
    }

    // Base case
    if(s1.size() == 1 && s2.size() == 1){
        return (to_string(stoi(s1) * stoi(s2)));
    }


    bool carry = false, borrow = false;

    string a = s1.substr(0, s1.size()/2);
    string b = s1.substr(s1.size()/2);
    string c = s2.substr(0, s1.size()/2);
    string d = s2.substr(s1.size()/2);

    string ac = multiplyStrings(a,c);
    string bd = multiplyStrings(b,d);

    string a_plus_b = addStrings(a, b, carry);
    string c_plus_d = addStrings(c, d, carry);

    // ad + bc = (a + b)(c + d) - ac - bd
    string ad_plus_bc = subStrings(subStrings(multiplyStrings(a_plus_b, c_plus_d), ac, borrow) , bd, borrow);

    return addStrings(ac + string(2*(s1.size() - s1.size()/2), '0'), addStrings(ad_plus_bc + std::string(s1.size() - s1.size()/2, '0'), bd, carry), carry);
    
}

int main() {
    string a = "3141592653589793238462643383279502884197169399375105820974944592";
    string b = "2718281828459045235360287471352662497757247093699959574966967627";

    cout << multiplyStrings(a,b) << endl;
    
    cout << "success" << endl;
    return 0;
}