#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

void init() {
    
}

void code() {
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;
    
    std::vector<int> cnt(26);
    for (auto c : s)
        cnt[c - 'a']++;
    std::sort(cnt.begin(), cnt.end());

    for (int i = n; i >= 1; i--) {
        bool res = true;
        std::vector<int> vis(i + 1);
        std::vector<int> tmp = cnt;
        for (int j = 1; j <= i; j++) {
            if (vis[j]) continue;
            int idx = j;
            int cnt = 0;
            while (!vis[j]) {
                cnt++;
                vis[j] = 1;
                j = (j + k - 1) % i + 1;
            }
            bool flag = false;
            for (int c = 0; c < 26; c++) {
                if (tmp[c] >= cnt) {
                    flag = true;
                    tmp[c] -= cnt;
                    break;
                }
            }
            if (!flag) {
                res = false;
                break;
            }
            std::sort(tmp.begin(), tmp.end());
        }
        if (res) {
            std::cout << i << '\n';
            return;
        }
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    for (int i = 1, n = (std::cin >> n, n); i <= n; i++)
    {
        init();
        code();
    }

    return 0;
}