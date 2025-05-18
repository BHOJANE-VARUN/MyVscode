
%{
#include "y.tab.h"
%}
%%
int {return datatype;}
float {return datatype;}
char {return datatype;}
double {return datatype;}
[a-zA-Z0-9_][a-zA-Z0-9_]* {return Identifier ;}
";" {return semicolon;}
"," {return comma;}
[\t]+ {}
[\n] {return 0;}
	
%%

int yywrap() {
	return 1;
}

