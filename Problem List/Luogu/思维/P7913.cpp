#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename T>
using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

void init() {
    
}

void code() {
    int N, n, m;
    std::cin >> N >> n >> m;

    std::vector<std::array<int, 2>> a(n + 1);
    std::vector<std::array<int, 2>> b(m + 1);
    for (int i = 1; i <= n; i++) std::cin >> a[i][0] >> a[i][1];
    for (int i = 1; i <= m; i++) std::cin >> b[i][0] >> b[i][1];

    std::sort(a.begin() + 1, a.end(), [](auto l, auto r) {
        return l[0] < r[0];
    });
    std::sort(b.begin() + 1, b.end(), [](auto l, auto r) {
        return l[0] < r[0];
    });

    const auto cal = [&](int n, std::vector<std::array<int, 2>> &a) -> std::vector<int> {
        min_heap<int> heap1;
        min_heap<std::array<int, 2>> heap2;
        std::vector<int> f(N + 1);
        for (int i = 1; i <= N; i++)
            heap1.push(i);
        for (int i = 1; i <= n; i++) {
            while (!heap2.empty() && heap2.top()[0] < a[i][0]) {
                auto x = heap2.top();
                heap2.pop();
                heap1.push(x[1]);
            }
            if (heap1.empty()) continue;
            
            auto x = heap1.top();
            heap1.pop();
            heap2.push({a[i][1], x});

            f[x]++;
        }
        for (int i = 1; i <= N; i++)
            f[i] += f[i - 1];
        return std::move(f);
    };

    auto f = cal(n, a);
    auto g = cal(m, b);

    int ans = 0;
    for (int i = 0; i <= N; i++)
        ans = std::max(ans, f[i] + g[N - i]);

    std::cout << ans << '\n';
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