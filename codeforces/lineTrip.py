t = int(input())

while(t > 0):
    n,x = map(int, input().split())

    arr = list(map(int, input().split()))

    if len(arr) == 1:
        print(arr[0])

    else:
        print(x-n)

    t -= 1
