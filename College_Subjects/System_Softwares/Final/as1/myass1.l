%{
#include<stdio.h>
%}

%%
#include<[a-z]+.h> {printf("preprocessing directive and header file found %s\n",yytext);}
"//".* {printf("single line comment %s\n",yytext);}
void|int {printf("DataTypes found %s\n",yytext);}
[a-zA-Z_][a-zA-Z_]+"()" {printf("function is found:%s \n",yytext);}
[a-zA-Z_][a-zA-Z_]+"(".*")" {printf("function is called %s \n",yytext);}
[{};\t\n] {  }
[0-9]+ {printf("number is found %d \n",atoi(yytext));}
%%

int yywrap()
{
    return 1;
}

int main()
{
    yyin = fopen("ass1.c","r");
    yylex();
    return 0;
}