import functools
from itertools import permutations

patterns = []
with open("p079_keylog.txt") as f:
    for line in f:
        line = line.strip()
        patterns.append([int(line[0]), int(line[1])])
        patterns.append([int(line[1]), int(line[2])])
        patterns.append([int(line[0]), int(line[2])])


patterns.sort()

d = []
last = patterns[0]
count = 0
for p in patterns:
    if last == p:
        count += 1
    else:
        d.append([count, last])
        last = p
        count = 1

d.sort(reverse=True)
for p in d:
    print(p)


# def getPerms(i̇np, constriants):
#     for comb in permutations(inp):
#         print(comb)

with open('079_passcode-graph.dot', 'w') as f:
    f.write('digraph {\n')
    for p in d:
        f.write(f'  {p[1][0]} -> {p[1][1]}\n')
    f.write('}\n')
