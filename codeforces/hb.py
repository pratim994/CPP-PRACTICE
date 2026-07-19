
t = int(input())


while t > 0:
    n, k= map(int, input().split())

    arr = list(map(int, input().split()))

    if(arr == sorted(arr)):
        print("YES")

    elif k >= 2:
        print("YES")

    else:
        print("NO")

    t -= 1
    




