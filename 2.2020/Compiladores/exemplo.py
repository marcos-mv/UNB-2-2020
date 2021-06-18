from lark import Lark
from hypothesis.extra.lark import from_lark

grammar = Lark(r"""
start: expr
expr: NUMERO
    |expr SP expr SP OP

SP : " "
OP : "+" | "-" | "*" | "/"
NUMERO : "0" | ("1".."9") ("1".."9")*

""")

#Lang5
#40 + 2
#2 * (10 + 10) + 2
#2 10 10 + * 2 +

# Lang1
# (a)
# ((a)a)
# ((((a)(a)aa)(((aa)))))

#Lang2
#[]
#[[]]
#[[[[]]]]

#Lang3
#ab
#aabb
#aaabbb

#Lang4 (*ERRO)
#aabbcc
#aaabbbccc
#abc

#Lang5
#40 + 2
#2 * (10 + 10) + 2
#2 10 10 + * 2 +



st = from_lark(grammar)
txt = st.example()

print('\n\n')

for _ in range(20):
    print(st.example())