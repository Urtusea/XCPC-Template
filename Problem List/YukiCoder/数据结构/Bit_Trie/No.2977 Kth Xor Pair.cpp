#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <int N, int B, int Build_Mode>
struct Bit_Trie {
    using T = std::conditional_t<(B <= 31), uint, uInt>;
    int idx;
    int cnt[N * B];
    int nxt[N * B][2];

    Bit_Trie() = default;

    void clear() {
        std::memset(cnt, 0, sizeof(cnt[0]) * (idx + 1));
        std::memset(nxt, 0, sizeof(nxt[0]) * (idx + 1));
        idx = 0;
    }

    int get_next(int &p) {
        return p ? p : p = ++idx;
    }

    void insert(const T x, int u = 0) {
        if constexpr (Build_Mode == 1) {
            for (int i = B - 1; i >= 0; i--)
                cnt[u = get_next(nxt[u][x >> i & 1])]++;
        } else {
            for (int i = 0; i < B; i++)
                cnt[u = get_next(nxt[u][x >> i & 1])]++;
        }
    }

    void erase(const T x, int u = 0) {
        if constexpr (Build_Mode == 1) {
            for (int i = B - 1; i >= 0; i--)
                cnt[u = get_next(nxt[u][x >> i & 1])]--;
        } else {
            for (int i = 0; i < B; i++)
                cnt[u = get_next(nxt[u][x >> i & 1])]--;
        }
    }

    int count(const T x, int u = 0) {
        if constexpr (Build_Mode == 1) {
            for (int i = B - 1; i >= 0; i--)
                if ((u = nxt[u][x >> i & 1]) == 0) return 0;
        } else {
            for (int i = 0; i < B; i++)
                if ((u = nxt[u][x >> i & 1]) == 0) return 0;
        }
        return cnt[u];
    }
};

Bit_Trie<200000, 31, 1> bit;

void init() {
    
}

void code() {
    Int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        bit.insert(a[i]);
    }

    const auto query = [](int x, int lim) -> Int {
        Int res = 0;
        auto cnt = bit.cnt;
        auto nxt = bit.nxt;
        
        int u = 0;
        for (int i = 30; i >= 0; i--) {
            int v1 = x >> i & 1;
            int v2 = lim >> i & 1;
            int v = v1 ^ v2;

            if (v2 == 1)
                res += cnt[nxt[u][v ^ 1]];
            if ((u = nxt[u][v]) == 0)
                break;
        }

        return res + cnt[u];
    };

    const auto check = [n, k, &query, &a](Int x) -> bool {
        Int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += query(a[i], x);
            cnt -= (a[i] ^ a[i]) <= x;
        }
        return cnt / 2 >= k;
    };

    Int l = -1, r = (1LL << 30) - 1;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }

    std::cout << r << '\n';
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