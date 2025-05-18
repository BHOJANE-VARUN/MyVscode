%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
int yyerror(const char *s);
%}

%token NUM

%%

S: E { printf("Final value is %d\n", $1); }
 ;

E: E '+' E { $$ = $1 + $3; }
 | E '-' E { $$ = $1 - $3; }
 | NUM     { $$ = $1; }
 ;

%%

int yyerror(const char *s) {
    printf("Error: %s\n", s);
    return 0;
}

int main() {
    printf("Enter an arithmetic expression: ");
    yyparse();
    return 0;
}
