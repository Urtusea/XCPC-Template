#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

void init() {
    
}

void code() {
    std::string s;
    std::cin >> s;

    int n = s.size();
    s = '#' + s;

    std::vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + (s[i] == '(' ? 1 : -1);

    int ans_len = 0, ans_cnt = 1;
    std::vector<int> stk;
    stk.push_back(0);

    for (int i = 1; i <= n; i++) {
        while (!stk.empty() && pref[stk.back()] > pref[i])
            stk.pop_back();
        if (!stk.empty() && pref[i] == pref[stk.back()]) {
            if (i - stk.back() > ans_len) {
                ans_len = i - stk.back();
                ans_cnt = 1;
            } else if (i - stk.back() == ans_len) {
                ans_cnt++;
            }
        } else {
            stk.push_back(i);
        }
    }

    std::cout << ans_len << ' ' << ans_cnt << '\n';
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