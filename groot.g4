grammar groot;

program: (functionDefStatement)* EOF;

statement: expression EOL
        | returnStatement EOL
        ;

returnStatement: 'return' expr=expression;

functionDefStatement: 'function' name=IDENTIFIER '(' (IDENTIFIER (',' IDENTIFIER)*)? ')' (EOL| blk=block);

block: '{' (statement)* '}';

expression: left=expression op=('*' | '/') right=expression             #mulDivExpression
            | left=expression op=('+' | '-') right=expression           #addSubExpression
            | atom=INT                                                  #primitiveExpression
            | var_name=IDENTIFIER '=' expr=expression                   #variableAssignment
            | name=IDENTIFIER                                           #variableValueExpression
            | name=IDENTIFIER '(' (expression (',' expression)*)? ')'   #functionCallExpression
            ;

IDENTIFIER: [a-zA-Z_] [a-zA-Z_0-9]*;
INT: [0-9]+;
EOL: ';';

WHITEPACE:[ \r\n\t\f] -> skip;