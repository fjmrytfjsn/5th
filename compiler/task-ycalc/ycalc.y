%{
#include <stdio.h>
#define VARNUM 10
int var[VARNUM];
int ans;
%}
/* トークンの定義 (NUM:整数) */
/*  この内容は，y.tab.h に書き出され，yylex で利用される．*/

%token NUM
%token VAR
%type E

/* 演算子の結合性．後に書いたものほど結合度が強い．*/
%right '='
%left '+' '-'	/* 結合度 弱 */
%left '*' '/'	/* 結合度 中 */
%right UMINUS	/* 結合度 強 (単項演算子の - の結合度) */

%start	S	/* 出発記号は S */

%%

/* S → SE<LF> | S<LF> | ε ，(<LF> は改行文字) */
S:    S E '\n'	{ printf("%d\n> ", ans=$2); }	/* 還元でEを消すとき */
    | S '\n'	{ printf("> "); }		/* 空行入力の場合    */
    | /* ε */	{ printf("> "); }		/* 実行開始時        */
;

/* E → E+E | E-E | E*E | E/E | -E | (E) | <NUM> | $ | <VAR> | E=E ，(<NUM> は整数) */ 
E:    E '+' E	{ $$ = $1 + $3; }
    | E '-' E	{ $$ = $1 - $3; }
    | E '*' E	{ $$ = $1 * $3; }
    | E '/' E	{ $$ = $1 / $3; }
    | '-' E	%prec UMINUS	/* 結合度の強さはUMINUSと同じ．*/
		{ $$ = -$2; }
    | '(' E ')' { $$ = $2; }
    | NUM	    { $$ = $1; }	/* $1 の値は yylval の値 */
    | '$'         { $$ = ans; }   /* 最後の計算結果を代入 */
    | VAR '=' E   { $$ = $3; var[$1] = $3; }
;
%%
main() {
  while(!feof(stdin)){	/* error が発生しても EOF まで実行を続ける */
    yyparse();		/* yacc が生成する yyparse() を呼び出す．  */
  }
}

/* エラー処理．yyparse() の中から呼び出される．*/
yyerror(char *str) { fprintf(stderr,"%s\n", str); }
