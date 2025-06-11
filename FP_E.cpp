#include <bits/stdc++.h>

void reverseDeque(std::deque<int>& dq) {
    int n = dq.size();
    for(int i = 0; i < n / 2; ++i){
        std::swap(dq[i], dq[n - i - 1]);
    }
}


int main(){
    std::deque<int> dq;

    int N;
    std::cin >> N;

    while(N--){
        std::string inputN;
        std::cin >> inputN;

        if(inputN == "tambahDepan"){
            int inputValue;
            std::cin >> inputValue;
            dq.push_front(inputValue);
        } else if(inputN == "tambahBelakang"){
            int inputValue;
            std::cin >> inputValue;
            dq.push_back(inputValue);
        } else if(inputN == "depan"){
            if(!dq.empty()){
                std::cout << dq.front();
                dq.pop_front();
            }
            std::cout << std::endl;
        } else if(inputN == "belakang"){
            if(!dq.empty()){
                std::cout << dq.back();
                dq.pop_back();
            }
            std::cout << std::endl;
        } else if(inputN == "balik"){
            reverseDeque(dq);
        }
    }
}