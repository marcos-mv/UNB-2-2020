import json

print(json.loads("42"))

print(json.loads("[40,41,42]"))

# def incr_by(n: int) -> callable[[int],int]:
#     def fn(x: int) -> int:
#         return x + n
#     return fn

# f = incr_by(1)

# g = incr_by(2)

# h = incr_by(10)

# print(f)

m = max([1,-10,55,33])

print(m)

mi = min([1,-10,55,33])

print(mi)

print(sorted([1,-10,55,33]))

lst = [{"nome": "Marcos","idade": 28}, {"nome": "Pedro", "idade": 20}]

def get_name(d):
    return d["nome"]

def get_age(d):
    return d["idade"]

def true_parser(st):
    src,pos = st
    if src.startwith("true",pos):
        return (src, pos + 4)