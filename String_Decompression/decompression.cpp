#include <iostream>

using namespace std;


string decompress(string str, int &i){
    string outs = "";
    int sum = 0;
    while(str[i] != 0){
        
        if(str[i] == '['){
            string temp = decompress(str, ++i);
            for(int count = 0; count < sum; count++){
                outs += temp;
            }
            sum = 0;
        }
        
        else if(str[i] == ']'){
            return outs;
        }
        
        else if(str[i] >= '0' && str[i] <= '9'){
            sum *= 10;
            sum += str[i] - '0';
        }
        
        else{
            outs += str[i];
        }
        
        ++i;
    }
    
    
    return outs;
}

int main()
{
    string str = "4[1[ab]2[c]]";
    int i = 0;
    cout << endl;
    cout << decompress("1[" + str + "]", i) << endl;
    // cout << i << endl;
    return 0;
}
