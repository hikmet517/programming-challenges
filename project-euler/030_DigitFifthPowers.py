from itertools import combinations, chain, permutations

digits = list(range(10))

fifth_sum = lambda xs: sum([x**5 for x in xs])
digits_to_num = lambda ns: sum([ns[i]*10**(len(ns)-i-1) for i in range(len(ns))])

def int_to_digits(n):
    if n==0: return [0]
    ns = []
    while n != 0:
        ns.append(n%10)
        n //= 10
    ns.reverse()
    return ns

ress = []
for i in range(10**6):
    if i == fifth_sum(int_to_digits(i)):
        ress.append(i)
        print(i)

print(sum(ress)-1)
