grammar groot;

program: (statement)* EOF;

statement: expression EOL
        | returnStatement EOL
        ;

returnStatement: 'return' expr=expression;

expression: left=expression op=('*' | '/') right=expression         #mulDivExpression
            | left=expression op=('+' | '-') right=expression       #addSubExpression
            | atom=INT                                              #primitiveExpression
            | var_name=IDENTIFIER '=' expr=expression               #variableAssignment
            | name=IDENTIFIER                                       #variableValueExpression
            ;

IDENTIFIER: [a-zA-Z_] [a-zA-Z_0-9]*;
INT: [0-9]+;
EOL: ';';

WHITEPACE:[ \r\n\t\f] -> skip;