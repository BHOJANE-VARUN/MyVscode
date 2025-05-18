%{
#include<stdio.h>
#include<stdlib.h>
void yyerror(char *str);
int yylex();
%}
%token Number 
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
| Number {$$ =$1;};	
%%

void yyerror(char *str) {
	printf("invalid Arithmetic Expression ");
}


int main() {
	printf("Enter the Arithmetic Expression : ");
	yyparse();
	return 0;
}
