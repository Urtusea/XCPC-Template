#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

std::unordered_map<std::string, int> DAY;
std::vector<std::string> word = {
    "I am guilty.",
    "I am not guilty.",
    "is guilty.",
    "is not guilty.",
    "Today is ",
};

void init() {
    DAY["Today is Monday."] = 1;
    DAY["Today is Tuesday."] = 2;
    DAY["Today is Wednesday."] = 3;
    DAY["Today is Thursday."] = 4;
    DAY["Today is Friday."] = 5;
    DAY["Today is Saturday."] = 6;
    DAY["Today is Sunday."] = 7;
}

void code() {
    int n, m, p;
    std::cin >> n >> m >> p;

    std::vector<std::string> name(n + 1);
    std::unordered_map<std::string, int> nameId;
    for (int i = 1; i <= n; i++) {
        std::cin >> name[i];
        nameId[name[i]] = i;
    }
    
    std::vector<int> a(p + 1);
    std::vector<int> b(p + 1);
    std::vector<int> c(p + 1);
    for (int i = 1; i <= p; i++) {
        std::string s;
        std::cin >> s;
        s = s.substr(0, s.size() - 1);

        for (int j = 1; j <= n; j++) {
            if (s == name[j]) {
                a[i] = j;
                break;
            }
        }

        std::getline(std::cin, s);
        s.erase(0, 1);
        if (s.back() == '\n') s.pop_back();
        if (s.back() == '\r') s.pop_back();
        if (s.back() == '\n') s.pop_back();
        if (s.back() == '\r') s.pop_back();

        for (int j = 1; j <= word.size(); j++) {
            if (s.find(word[j - 1]) != std::string::npos) {
                b[i] = j;
                if (j == 3 || j == 4) {
                    c[i] = nameId[s.substr(0, s.find(" is"))];
                } else if (j == 5) {
                    c[i] = DAY[s];
                }
                break;
            }
        }
    }

    const auto check = [&](int id, int day) -> bool {
        std::vector<int> flag(n + 1, -1);
        
        for (int i = 1; i <= p; i++) {
            int now = a[i];
            int opt = b[i];

            if (opt == 1) {
                if (flag[now] == -1) {
                    flag[now] = (id == now);
                } else {
                    if ((id == now) != flag[now])
                        return false;
                }
            }

            if (opt == 2) {
                if (flag[now] == -1) {
                    flag[now] = (id != now);
                } else {
                    if ((id != now) != flag[now])
                        return false;
                }
            }

            if (opt == 3) {
                int otr = c[i];
                if (flag[now] == -1) {
                    flag[now] = (id == otr);
                } else {
                    if ((id == otr) != flag[now])
                        return false;
                }
            }

            if (opt == 4) {
                int otr = c[i];
                if (flag[now] == -1) {
                    flag[now] = (id != otr);
                } else {
                    if ((id != otr) != flag[now])
                        return false;
                }
            }

            if (opt == 5) {
                int otr = c[i];
                if (flag[now] == -1) {
                    flag[now] = (day == otr);
                } else {
                    if ((day == otr) != flag[now])
                        return false;
                }
            }
        }

        int cnt0 = std::count(flag.begin() + 1, flag.end(), 0);
        int cnt1 = std::count(flag.begin() + 1, flag.end(), 1);

        return cnt0 <= m && cnt1 <= n - m;
    };

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 7; j++) {
            if (check(i, j)) {
                if (i != ans && ans) {
                    std::cout << "Cannot Determine\n";
                    return;
                } else {
                    ans = i;
                }
            }
        }
    }

    if (ans == 0) {
        std::cout << "Impossible\n";
    } else {
        std::cout << name[ans] << '\n';
    }
}

int main() {
    // std::cin.tie(nullptr)->sync_with_stdio(false);

    // for (int i = 1, n = (std::cin >> n, n); i <= n; i++)
    {
        init();
        code();
    }

    return 0;
}