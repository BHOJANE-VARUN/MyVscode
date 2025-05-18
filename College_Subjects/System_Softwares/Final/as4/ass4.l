%{
	#include "y.tab.h"
	extern int yylval;
%}
%%
[0-9]+ {yylval = atoi(yytext);
	return Number;}
[\n] {return 0;}
[\t] {}
. {return yytext[0];}
%%
int yywrap() {
return 1; 
}

