grammar groot;

program: expr=expression;

expression: left=expression op=('*' | '/') right=expression         #mulDivExpression
            |left=expression op=('+' | '-') right=expression        #addExpression
            | atom=INT                                              #primitiveExpression
            ;

INT: [0-9]+;

WHITEPACE:[ \r\n\t] -> skip;