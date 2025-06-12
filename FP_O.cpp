#include <bits/stdc++.h>

int main(){
    int N;
    std::cin >> N;

    std::vector<int> Ni;
    int root = INT_MIN;
    for(int i = 0; i < N; ++i){
        int x;
        std::cin >> x;
        if(x < root){
            std::cout << "Ini bukan pohon" << std::endl;
            return 0;
        }
        while (!Ni.empty() && x > Ni.back()){
            root = Ni.back();
            Ni.pop_back();
        }
        Ni.push_back(x);
    }
    
    std::cout << "Ini pohon" << std::endl;
    return 0;
}

// preorder : root -> left -> right
// bst : left < root < right