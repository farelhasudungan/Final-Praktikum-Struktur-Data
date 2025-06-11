#include <bits/stdc++.h>

int main(){
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> hW(n + 1); // hW as height and width
    for(int i = 0; i < n; ++i){
        std::cin >> hW[i].first;
    }
    for(int i = 0; i < n; ++i){
        std::cin >> hW[i].second;
    }
    hW.push_back({0, 0}); ++n;

    std::stack<std::pair<int,long long>> s;
    long long area = 0, idx, w;
    for(int i = 0; i < n; ++i){
        long long width = 0;
        while(!s.empty() && hW[s.top().first].first > hW[i].first){
            idx = s.top().first;
            w = s.top().second;
            s.pop();

            width += w;
            area = std::max(area, hW[idx].first * width);
        }
        s.push({i, hW[i].second + width});
    }

    std::cout << area << std::endl;
}