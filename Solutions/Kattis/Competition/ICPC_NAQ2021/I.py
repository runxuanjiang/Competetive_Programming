import copy

seen = {}
lines = []
tests = int(input())
for i in range(tests):
    lines.append(input().split(' '))

others = []

for line in lines:
    if len(line) == 1:
        seen[line[0]] = 1
    else:
        others.append(line)

temp1 = []
for o in others:
    curr = []
    if 'or' == o[2]:
        curr.append('or')
    elif 'and' == o[2] or len(o) == 4:
        curr.append('and')
    for topping in o:
        if topping != 'if' and topping != 'or' and topping != 'and' and topping != 'then':
            curr.append(topping)

    temp1.append(curr)

temp2 = []
prog = True
while len(temp1) > 0 and prog:
    prog = False
    for line in temp1:
        req = True
        if line[0] == 'or':
            req = False
            for t in line[1:-1]:
                if t in seen:
                    req = True
                    break
        else:
            for t in line[1:-1]:
                if t not in seen:
                    req = False
                    break
        
        if req:
            seen[line[-1]] = 1
            prog = True
        else:
            temp2.append(line)

    temp1 = copy.deepcopy(temp2)
    temp2 = []


print(len(seen))


