from lark import Lark

name = "Noam Chomsky"
print(name)

grammar = Lark(r"""
module : "\n"* [stm("\n" stm*) "\n"*]
?stm : assign
        | expr


assign : VAR "=" expr

?expr : STRING -> string
        |VAR   -> var
        |funcall
        |"..."  -> ellipsis

funcall : expr"(" [args]")"
args    : expr("," expr)*

VAR : ("a".."z"|"ç")+
STRING : "\"" ("a".."z" |"A".."Z"|" ")* "\""

%ignore " "+

""", start ="module")

code = """
ç = "Noam Chomsky"
print(ç)
"""

tree = grammar.parse(code)
print(tree.pretty())

# VAR = STRING
# VAR(VAR)

# VAR = expr
# VAR(expr)

# assign
# expr(args)

# stm
# funcall

# stm
# expr

# stm
# stm

# start

