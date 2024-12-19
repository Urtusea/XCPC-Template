#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

void init() {
    
}

void code() {
    std::string s;

    int cnt = 0;
    for (int i = 1; i <= 8; i++) {
        std::cin >> s;

        if (s == "AC" || s == "NoOut") {
            cnt += 1;
        }
    }

    if (cnt >= 6)
        std::cout << "Win\n";
    else if (cnt >= 5)
        std::cout << "Draw\n";
    else
        std::cout << "Lose\n";
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    // for (int i = 1, n = (std::cin >> n, n); i <= n; i++)
    {
        init();
        code();
    }

    return 0;
}