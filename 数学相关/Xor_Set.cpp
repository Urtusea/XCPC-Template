#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

// The Xor-Subset is 'x'
#define Xor_Subset(init, limit) for (int x = init; x >= limit; x = (x - 1) & init)

// The Xor-Supset is 'x'
#define Xor_Supset(init, limit) for (int x = init; x <= limit; x = (x + 1) | init)