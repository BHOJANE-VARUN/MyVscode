%{

#include<stdio.h>

%}


%%
# { printf("Preproccesor directive :%s\n",yytext);}
[<][a-z]+[.][h][>] {printf("Header File: %s\n",yytext);}
["].*["] {printf("Literal: %s\n",yytext);}
int|float|double|char { printf("DataTypes: %s\n",yytext);}
include|void|if|else|for|while|return {printf("Keywords : %s\n",yytext);}
[A-Za-z_]+[A-Za-z_0-1]* {printf("Identifier:%s\n",yytext);}
","|";"|"{"|"}"|"("|")" {printf("Punctuations : %s\n",yytext);}
[0-9]+ {printf("Integer: %s\n",yytext);}
[0-9]*[.][0-9]+ {printf("FloatingNumber: %s\n",yytext);}
"+"|"-"|"*"|"/"|"%"|"=" {printf ("Operators : %s\n",yytext);}
"//".* {printf("SingleLineComment: %s\n",yytext);}
"/*"(.|\n)*"*/" {printf("MultilineComment:%s\n",yytext);}
%%


int yywrap() {
	return 1;
}

int main () {
	printf("Enter C file :");
	
	yyin=fopen("ass1.c","r");
	yylex();
	return 0;
}
