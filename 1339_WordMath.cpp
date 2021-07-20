// Greed Algorithm
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

string input;
int alpha_impo[26] = {0, };
int N, word_sum = 0, word_len, change_num = 9;
int *found;

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i++){
        cin >> input;
        word_len = input.length();
        for (int j = 0; j < word_len; j++)
            alpha_impo[input[j]-'A'] += pow(10,word_len-(j+1));
    }
    
    while (any_of(alpha_impo, alpha_impo+26, [](int i){return i>0;})){
        for(int j = 0; j < 26; j++){
            found = find(alpha_impo, alpha_impo+26, *max_element(alpha_impo, alpha_impo+26));
            if (found != alpha_impo+26){
                word_sum += (*found) * change_num;
                *found = 0;
                change_num--;
            }
            else
                break;
        }
    }
    
    cout << word_sum;
}