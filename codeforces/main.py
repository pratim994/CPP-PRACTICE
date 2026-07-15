import sys

def solve():
    try:
        line1 = sys.stdin.readline().split()
        if not line1: return
        n, k = map(int, line1)
        a = list(map(int, sys.stdin.readline().split()))
    except ValueError:
        return
    lens = []
    if n > 0:
        cur = 1
        for i in range(1, n):
            if a[i] != a[i - 1]:
                lens.append(cur)
                cur = 1
            else:
                cur += 1
        lens.append(cur)
    
    lens.sort()

    m = len(lens)
    d = 0
    ans = 0
    i = 0
    
    while i < m:
        length = lens[i]
        x = length - 1
        q = m - i
        
        curLen = n - d - x * q
        
        if curLen <= k and (k - curLen) % q == 0:
            ans += 1
            
        j = i
        while j < m and lens[j] == length:
            j += 1
        d += (j - i) * lens[i]
        i = j

    print(ans)

def main():
    line = sys.stdin.readline()
    if not line:
        return
    t = int(line)
    for _ in range(t):
        solve()

if __name__ == '__main__':
    main()
