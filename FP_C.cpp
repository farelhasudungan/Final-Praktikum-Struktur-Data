#include <bits/stdc++.h>

int main(){
    int N;
    std::cin >> N;
    
    std::vector<int> X(N);
    for(int i = 0; i < N; ++i){
        std::cin >> X[i];
    }

    int left = 0, right = N - 1;
    int left_max = 0, right_max = 0;
    long long total_energy = 0;

    while(left <= right){
        if(X[left] < X[right]){
            if(X[left] >= left_max)
                left_max = X[left];
            else
                total_energy += left_max - X[left];
            ++left;
        } else {
            if(X[right] >= right_max)
                right_max = X[right];
            else
                total_energy += right_max - X[right];
            --right;
        }
    }

    std::cout << total_energy << std::endl;
    return 0;
}