# Infix Expression
&lt;operand&gt;&lt;operator&gt;&lt;operand&gt;
operand = any number or expression

e.g. 5+3, 4+1*5

### Precedence
1. (),{},[] 
2. ^(power)  Associativity = R -> L
3. /* /  Associativity = L -> R
4. /+ /-  Associativity = L -> R 
   
# Prefix Expression (Polish Notation)
&lt;operator&gt;&lt;operand&gt;&lt;operand&gt;
operand = any number or expression

e.g. + 5 3, + 4 * 1 5


# Postfix Expression (Reverse Polish Notation)
&lt;operand&gt;&lt;operand&gt;&lt;operator&gt;
operand = any number or expression

e.g. 5 3 +, 4 1 5 * +