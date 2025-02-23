%{
#include<stdio.h>
int a,b;
%}

%%
# {printf("preprocessing identifier %s \n",yytext);}
 
%%

int yywrap()
{
    return 1;
}

int main()
{
    yyin = fopen("test.c","r");
    yylex();
    return 0;
}