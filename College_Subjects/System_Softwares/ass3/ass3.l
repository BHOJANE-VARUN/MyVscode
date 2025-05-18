%{
#include "ass3.tab.h"
%}

%% 
"int"    { return DT; } 
"float"  { return DT; } 
"char"   { return DT; } 
[a-zA-Z_][a-zA-Z0-9_]*  { return ID; } 
","  { return COMMA; }  
";" { return SC; } 
[ \t\n]  { /* Ignore whitespace */ } 
.        { return yytext[0]; } 
%% 



int yywrap()
{
    return 1;
}