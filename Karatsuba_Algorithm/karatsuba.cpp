#include <iostream>
#include <bits/stdc++.h>
#include<string>

using namespace std;

string operator+(string a, string b){
    string str = "";
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int size = min(a.size(), b.size());
    int carry = 0;

    int i = 0;
    while(i < size){
        int add = (a[i] + b[i] + carry - '0');
        carry = 0;
        if(add > '9'){
            add -= 10;
            ++carry;
        }
        str.append(1, (char)add);
        ++i;
    }
    
    while(i < max(a.size(), b.size())){
        int add = '0';
        if(i < a.size()){     
            add = (a[i] + carry);
            carry = 0;
            if(add > '9'){
                add -= 10;
                ++carry;
            }
        }
        else{
            add = (b[i] + carry);
            carry = 0;
            if(add > '9'){
                add -= 10;
                ++carry;
            }
        }
        str.append(1, (char)add);
        ++i; 
    }
    if(carry){
        str.append(1, '0' + carry);
    }

    reverse(str.begin(), str.end());

    return str;
}

string operator-(string a, string b){
    string str = "";
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int size = min(a.size(), b.size());
    int borrow = 0;

    int i = 0;
    while(i < size){
        int sub = (a[i] - b[i] - borrow + '0');
        borrow = 0;
        if(sub < '0'){
            sub += 10;
            ++borrow;
        }
        str.append(1, (char)sub);
        ++i;
    }
    
    while(i < max(a.size(), b.size())){
        int sub = '0';
        if(i < a.size()){     
            sub = (a[i] - borrow);
            borrow = 0;
            if(sub < '0'){
                sub += 10;
                ++borrow;
            }
        }
        else{
            sub = (b[i] + borrow);
            borrow = 0;
            if(sub < '0'){
                sub += 10;
                ++borrow;
            }
        }
        str.append(1, (char)sub);
        ++i; 
    }
    reverse(str.begin(), str.end());

    return str;
}

string operator*(string s1, string s2) {
    
    // Equalizing length of both strings by pending zeroes
    if(s1.size() != s2.size()){
        if(s1.size() > s2.size()){
            s2 = string(s1.size() - s2.size(), '0').append(s2);
        }
        else{
            s1 = string(s2.size() - s1.size(), '0').append(s1);
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


    string a = s1.substr(0, s1.size()/2);
    string b = s1.substr(s1.size()/2);
    string c = s2.substr(0, s1.size()/2);
    string d = s2.substr(s1.size()/2);

    string ac = (a*c);
    string bd = (b*d);

    string a_plus_b = a + b;
    string c_plus_d = c + d;
    string ad_plus_bc = (a_plus_b * c_plus_d) - ac - bd;

    return (ac.append(2*(s1.size() - s1.size()/2), '0') + ad_plus_bc.append(s1.size() - s1.size()/2, '0') +  bd);
    
}

int main() {
    string a = "3141592653589793238462643383279502884197169399375105820974944592";
    string b = "2718281828459045235360287471352662497757247093699959574966967627";

    cout << (a*b) << endl;
    cout << "success" << endl;
    return 0;
}