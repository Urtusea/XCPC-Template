#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

namespace Base {
    enum uint_size {
        uint_64m  = 1ULL << 25,
        uint_128m = 1ULL << 26,
        uint_256m = 1ULL << 27,
        uint_512m = 1ULL << 28
    };

    constexpr uint size = uint_64m;
    uint mem[size];
    uint idx;

    void clear() {
        std::memset(mem + size, 0, size - idx);
        idx = size;
    }

    template <typename T>
    struct base {
        T *operator () () {
            return (T *)(&mem[idx -= sizeof(T)]);
        }
    };
};

template <typename Info>
struct Segment_Tree_Dynamic {
    struct Node {
        Info data;
        Node *lson;
        Node *rson;

        Node()
        : data(), lson(nullptr), rson(nullptr) {}
    };
    static Node *root;
    Base::base<Info> get;
    
    Segment_Tree_Dynamic() {}

    void clear() {
        Base::clear();
        root = get();
    }

    void push_up(Node *p) {
        p->data = p->lson->data + p->rson->data;
    }

    void update(int l, int r, int u, Info x, Node* &p = root) {
        if (p == nullptr)
            p = get();
        if (l == r)
            return (void)(p->data.update(x, r - l + 1));
        int m = (l + r) >> 1;
        update(l, m, u, x, p->lson);
        update(m + 1, r, u, x, p->rson);
        push_up(p);
    }

    Info query(int l, int r, int L, int R, Node *p = root) {
        if (p == nullptr || R < l || r < L)
            return Info();
        if (L <= l && r <= R)
            return root->data;
        int m = (l + r) >> 1;
        return query(l, m, L, R, root->lson) + query(m + 1, L, R, root->rson);
    }
};