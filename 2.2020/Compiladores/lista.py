nomes = ['marcos', 'junior', 'ana', 'pedro']

for nome in nomes:
    print(nome)

if 'marcos' in nomes:
    print('sim')

nomes.append('maria')

print(nomes)

nomes.sort()

print(nomes)

nome = 'maria'

print(f'oi {nome}')

tp = 1, 2, 3, 4

print(tp)

ls = [1,2,3,4,5]

print(ls)

for quant in tp:
    print(quant)

print(ls[1])

print(len(ls))

a = {1,2,3}

b = {1,3}

print(a.issuperset(b))

lista = [1, 2, 3, 8, 2, 9, 4, 4, 22]

print(set(lista))

print(type({}))

def fat(n):
    if n <= 0:
        return 1
    else:
        return n * fat(n-1)


b = 0
while(b<998):
    fat(b)
    b+=1
    print(b,fat(b))
