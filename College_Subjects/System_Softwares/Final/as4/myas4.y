%{
#include<stdio.h>
#include<stdlib.h>
void yyerror(char* str);
int yylex();
%}

%token NUM
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
%start A

%%
A:E {printf("Result of Arithmetic Expresion is:  %d",$$);}
E:E'+'E {$$=$1+$3;};
| E'-'E {$$=$1-$3;};
| E'*'E {$$=$1*$3;};
| E'/'E {$$=$1/$3;};
| E'%'E {$$=$1%$3;};
|'('E')'{$$=$2;};
| NUM {$$ =$1;};	
%%

void yyerror(char* str)
{
    printf("error occuried");
}
int main()
{
    printf("Enter a Arithmetic Expresion:");
    yyparse();
    return 0;
}