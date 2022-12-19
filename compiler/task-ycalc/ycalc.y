%{
#include <stdio.h>

double ans;

// 変数用の構造体
struct stab {
    char name;
    double val;
};
struct stab stab[60] = {0};
int count=0;

// 変数への値の代入
double assignment(char name, double val) {
    int i;
    for(i=0;i<count;i++) { 
        if(stab[i].name==name)
            return stab[i].val = val;
    }
    stab[count].name = name;
    return stab[count++].val = val;
}

// 変数の値を出力へプッシュ
double push(char name) {
    int i;
    for(i=0;i<count;i++) {
        if(stab[i].name==name)
            return stab[i].val;
    }
}

// 変数名とその値を列挙
void listing() {
    int i;
    for(i=0;i<count; i++)
        printf("%c = %f\n", stab[i].name, stab[i].val);
}
%}

%union {
    char varname;
    double dval;
}

%token <dval> NUM
%token <varname> NAME
%token LIST CLEAR
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
    | '$'                   { $$ = ans; }               /* 最後の計算結果を代入 */
    | NAME '=' E            { $$ = assignment($1, $3);} /* 変数生成および代入 */
    | NAME                  { $$ = push($1); }          /* 変数の値を返す */
    | LIST                  { listing(); }              /* 変数とその値を列挙 */
    | CLEAR                 { count=0; }                /* 変数をすべて消去 */
;
%%

main() {
    while(!feof(stdin)){
        yyparse();
    }
}

/* エラー処理．yyparse() の中から呼び出される．*/
yyerror(char *str) { fprintf(stderr,"%s\n", str); }
