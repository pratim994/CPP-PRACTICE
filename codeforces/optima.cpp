#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#define DISABLE_MMAP
// --- Paste the entire fast_io namespace from tk.cpp here ---
// (FastInput, FastOutput, FastIO as-is)

using fast_io::FastIO;
FastIO<1 << 20, 1 << 20> io;

int main() {
    io.init();

    std::string s1, s2;
    io >> s1 >> s2;

    // Two-pointer palindrome check: is s1 == reverse(s2)?
    // Equivalent to checking if s1 reversed == s2
    bool ok = (s1.size() == s2.size());
    if (ok) {
        int l = 0, r = (int)s1.size() - 1;
        while (l <= r) {
            if (s1[l] != s2[r]) { ok = false; break; }
            ++l; --r;
        }
    }

    io << (ok ? "YES" : "NO") << '\n';
    return 0;
}
