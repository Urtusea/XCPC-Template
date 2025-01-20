#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

void init() {
    
}

void code() {
    Int n, m;
    std::cin >> n >> m;

    if (n == 2) {
        std::cout << "Yes\n";
        return;
    }

    int lg = 0;
    for (Int i = m; i; i /= n) lg++;

    std::vector<Int> f(lg + 1); 
    f[0] = 1;
    for (int i = 1; i <= lg; i++)
        f[i] = f[i - 1] * n;

    for (int s = 0; s < (1 << lg); s++) {
        Int sum = m;
        for (int i = 0; i < lg; i++)
            if (s >> i & 1) sum += f[i];
        
        bool flag = true;
        for (int i = 0; sum; sum /= n, i++) {
            if (sum % n > 1) {
                flag = false;
                break;
            }
        }

        if (flag) {
            std::cout << "Yes\n";
            return;
        }
    }

    std::cout << "No\n";
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