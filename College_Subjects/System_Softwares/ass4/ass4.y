%{
#include <stdio.h>
#include <stdlib.h>
#include "ass4.tab.h"

int yylex();
int yyerror(const char *s);
%}

%token NUM
%left '+' '-'
%left '*' '/' '%'

%%

A: E { printf("Result of Arithmetic Expression: %d\n", $1); }
;

E: E '+' E { $$ = $1 + $3; }
 | E '-' E { $$ = $1 - $3; }
 | E '*' E { $$ = $1 * $3; }
 | E '/' E { $$ = $1 / $3; }
 | E '%' E { $$ = $1 % $3; }
 | '(' E ')' { $$ = $2; }
 | NUM { $$ = $1; }
;

%%

int yyerror(const char *s) {
    printf("Invalid Arithmetic Expression\n");
    return 0;
}

int main() {
    printf("Enter an arithmetic expression:\n");
    yyparse();
    return 0;
}
