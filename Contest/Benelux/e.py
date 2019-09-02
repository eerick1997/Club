n = int(input())
total = 1

mod = 1000000007

for i in list(input().split()):
    total = total << 1;
    to_rest = int(i)

    if to_rest > total:
        print("error")
        exit(0)

    total -= to_rest

print(int(total % mod))
