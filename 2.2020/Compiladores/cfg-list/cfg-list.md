## [cfg-list]: Representar sequências em notação BNF e EBNF

Resolva uma das questões abaixo para obter a competência. 

**Q1)** Monte uma gramática BNF ou EBNF para identificar listas de elementos em cada um dos casos abaixo:

1. JSON: usa "[]" como delimitadores e exige uma vírgula entre cada elemento da lista
2. LISP: usa "()" como delimitadores e não utiliza vírgulas para separar os elementos.
3. LISP-II: em algumas versões de LISP, a vírgula é opcional, também podendo aparecer após o último elemento.
4. Python: similar ao JSON, mas permite uma vírgula após o último elemento. `[,]` é inválido.
5. Javascript: similar ao JSON, mas aceita **1 ou mais** vírgulas entre os elementos e após o último elemento. `[,]`, assim como `[1,2,,3,,,]` são valores válidos. Em Javascript, o espaço vazio entre duas vírgulas é interpretado como um elemento `undefined`.

## Q1

### 1

```
r"""
?start  :   list
?list   :   "[" elem ("," elem)* "]"    -> json
"""
```

### 2
```
r"""
?start  :   list
?list   :   "(" elem+ ")"   -> lisp
"""
```

### 3

```
r"""
?start  :   list
?list   :  "(" (elem ","?)+ ")"    -> lispii
"""
```

### 4

```
r"""
?start  :   list
?list   :   "[" (elem ",")+ "]"   -> python
"""
```
### 5
```
r"""
?start  :   list
?list   :   "[" (elem? ","+)+ "]"    -> js
"""
```