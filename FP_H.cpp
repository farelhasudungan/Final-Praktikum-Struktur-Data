#include <bits/stdc++.h>

int main(){
    std::vector<int> alpha(26, 0);

    std::string S;
    std::cin >> S;
    int lengthS = S.length();
    for(int i = 0; i < lengthS; ++i){
        if(S[i] >= 'a' && S[i] <= 'z'){
            alpha[S[i] - 'a']++;
        }
    }

    for(int i = 0; i < lengthS; ++i){
        int num = S[i] - 'a';
        if(alpha[num] == 1){
            std::cout << i;
            return 0;
        }
    }

    std::cout << -1;
    return 0;
}