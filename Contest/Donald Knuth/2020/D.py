import math

MOD = 1000000000 + 7 

def gauss(n):
    return n * (n + 1)

def cuadratic_serie(n):
    return (n * (n + 1) * (2 * n + 1)) // 3

n = int(input())

root = int((math.sqrt(4*n + 1) - 1) / 2)

#substract = (gauss(root) - n) * root
#serie_result = cuadratic_serie(root)
#ans = serie_result - substract
ans = cuadratic_serie(root) + ((root + 1) * (n - gauss(root)))
print(int(ans % MOD))