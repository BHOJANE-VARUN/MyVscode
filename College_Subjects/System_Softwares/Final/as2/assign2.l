%{
   #include<stdio.h>
   int ln_cnt=0;
   int wrd_cnt=0;
   int tb_cnt=0;
   int sp_cnt=0;
   int chr_cnt=0;
   int spch_cnt=0;
   int vol_cnt=0;
%}

%%
[\n] {ln_cnt++; chr_cnt += yyleng;}
[ ] {sp_cnt++; chr_cnt += yyleng;}
[\t] {tb_cnt++; chr_cnt += yyleng;}
[^ \t\n]+ {wrd_cnt++; chr_cnt += yyleng;}
%%

int yywrap(){
   return 1;
}

int main(){
   yyin = fopen("assign.txt", "r");
   yylex();
   printf("Word Count :%d\n",wrd_cnt);
   printf("Space Count: %d\n",sp_cnt);
   printf("Tab Count: %d\n", tb_cnt);
   printf("Line Count: %d\n", ln_cnt);
   printf("Charter Count: %d\n", chr_cnt);
   printf("Special Charcter: %d\n", sp_cnt);
   return 0;
}

