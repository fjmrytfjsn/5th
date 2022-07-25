%{
#include <stdio.h>
double ans;
double var[60] = {};
%}

%union {
    int varnum;
    double dval;
}

%token <dval> NUM
%token <varnum> NAME
%token <int> LIST
%type <dval> E

%right '='
%left '+' '-'
%left '*' '/'
%right UMINUS

%start	S

%%
/* S → SE<LF> | S<LF> | ε ，(<LF> は改行文字) */
S:    S E '\n'	{ printf("%lf\n> ", ans=$2); }
    | S '\n'	{ printf("> "); }
    | /* ε */	{ printf("> "); }
;

/* E → E+E | E-E | E*E | E/E | -E | (E) | <NUM> | $ | <NAME>=E | <NAME> | list */ 
E:    E '+' E	            { $$ = $1 + $3; }
    | E '-' E	            { $$ = $1 - $3; }
    | E '*' E	            { $$ = $1 * $3; }
    | E '/' E	            { $$ = $1 / $3; }
    | '-' E	%prec UMINUS    { $$ = -$2; }
    | '(' E ')'             { $$ = $2; }
    | NUM	                { $$ = $1; }
    | '$'                   { $$ = ans; }   /* 最後の計算結果を代入 */
    | NAME '=' E            { $$ = $3; var[$1] = $3; }
    | NAME                  { $$ = var[$1]; }
    | LIST                  { int i; for(i=0;i<60;i++){if(var[i]!=0) printf("%c: %lf\n", i+'A', var[i]);} }
;
%%

main() {
  while(!feof(stdin)){
    yyparse();
  }
}

/* エラー処理．yyparse() の中から呼び出される．*/
yyerror(char *str) { fprintf(stderr,"%s\n", str); }
