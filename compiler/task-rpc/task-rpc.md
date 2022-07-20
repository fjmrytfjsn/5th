# 課題1, 2

## 課題1

実行結果のscriptファイルを以下に示す。

```lang-js
Script started on 2022-07-06 10:50:40+09:00 [TERM="xterm-256color" TTY="/dev/pts/0" COLUMNS="104" LINES="49"]
]0;fjsn@SSD: ~/directory/5th/compiler/task-rpc[01;32mfjsn@SSD[00m:[01;34m~/directory/5th/compiler/task-rpc[00m$ flex rpc.l
]0;fjsn@SSD: ~/directory/5th/compiler/task-rpc[01;32mfjsn@SSD[00m:[01;34m~/directory/5th/compiler/task-rpc[00m$ cc lex.yy.c
[01m[Krpc.l:[m[K In function ‘[01m[Kyylex[m[K’:
[01m[Krpc.l:30:3:[m[K [01;35m[Kwarning: [m[K‘[01m[Kreturn[m[K’ with no value, in function returning non-void
   30 | q [01;35m[K      [m[K        { return; }
      |   [01;35m[K^~~~~~[m[K
[01m[Klex.yy.c:632:21:[m[K [01;36m[Knote: [m[Kdeclared here
  632 | #define YY_DECL int [01;36m[Kyylex[m[K (void)
      |                     [01;36m[K^~~~~[m[K
[01m[Klex.yy.c:652:1:[m[K [01;36m[Knote: [m[Kin expansion of macro ‘[01m[KYY_DECL[m[K’
  652 | [01;36m[KYY_DECL[m[K
      | [01;36m[K^~~~~~~[m[K
[01m[Krpc.l:[m[K At top level:
[01m[Krpc.l:34:1:[m[K [01;35m[Kwarning: [m[Kreturn type defaults to ‘[01m[Kint[m[K’ [[01;35m[K-Wimplicit-int[m[K]
   34 | [01;35m[Kmain[m[K() {
      | [01;35m[K^~~~[m[K
]0;fjsn@SSD: ~/directory/5th/compiler/task-rpc[01;32mfjsn@SSD[00m:[01;34m~/directory/5th/compiler/task-rpc[00m$ ./a.out
*** Reverse Polish Calculator 
> 1
1 > 2
1 2 > 3
1 2 3 > 4
1 2 3 4 > 5
1 2 3 4 5 > +
1 2 3 9 > s
1 2 9 3 > /
1 2 3 > *
1 6 > -
-5 > +-
5 > 6
5 6 > 7
5 6 7 > r
6 7 5 > o
6 7 5 7 > p
6 7 5 > d
6 7 5 5 > c
> q
]0;fjsn@SSD: ~/directory/5th/compiler/task-rpc[01;32mfjsn@SSD[00m:[01;34m~/directory/5th/compiler/task-rpc[00m$ exit
exit

Script done on 2022-07-06 10:51:43+09:00 [COMMAND_EXIT_CODE="0"]

```

## 課題2

C言語では整数を省略していても小数として入力できるので、整数部はあっても無くてもいい。よって

```add.l
"-"?"."{DIGIT}+      { sscanf(yytext, "%lf", &S[++P]); }
```

を追加すればよい。
