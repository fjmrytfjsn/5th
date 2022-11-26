import math
# nに2以上の整数を入れることで正n角形の頂点を良い感じにできるやつ
# Cloud LaTeXでPDFLaTeXを選択、使用方法を読めば最低限のことは出来そう

# 使用方法
'''
PDFLaTeXを選択
↓
本コードを実行、出てきた結果をCtrl+C
↓
\ documentclass{standalone}
\ usepackage{tikz}
\ begin{document}
\ begin{tikzpicture}
% mininum sizeは頂点の大きさ
\ tikzset{enclosed/.style={draw, circle, inner sep=0pt, minimum size=0.1cm, fill=black}}

ここにCtrl+Vで貼り付け！！

(A)

\ end{tikzpicture}
\ end{document} 
↓
コンパイルしたら良い感じに表示されるらしい
'''
def main():
    print("頂点数を入力してください(2~25程度を想定)")
    n = int(input())


    key = 1 #CR(N, d1, d2)の描画がしたい奴は1にしてね、実行後は0に戻そう
    if key:
        print("d1, d2を入力してください(例:3 5)")
        d1, d2 = map(int,input().split())

    for i in range(n):
        print("\\node[enclosed, label={above,xshift=",round(0.35*math.sin(2*math.pi*i/n),2),"cm,yshift=",round(-0.31+0.35*math.cos(2*math.pi*i/n),2),"cm:"+str(i)+"}] at (",round(2.6+2*math.sin(2*math.pi*i/n),2),",",round(2+2*math.cos(2*math.pi*i/n),2),")",str("(")+str(i)+str("){};"))

    if key:
    #隣同士の頂点を接続
        for i in range(n):
            print("\draw [thick] (" + str(i) + ")--(" + str((i+1)%n) + ");")
    #d1離れている頂点を接続
        for i in range(n):
            print("\draw [thick] (" + str(i) + ")--(" + str((i+d1)%n) + ");")
    #d2離れている頂点を接続
        for i in range(n):
            print("\draw [thick] (" + str(i) + ")--(" + str((i+d2)%n) + ");")

if __name__ == "__main__":
    main()



'''
補足:辺のつなぎ方

Ctrl+Vした内容部分と\ end{tikzpicture}の間(A)に
\ draw [thick] (u)--(v);
と入力すると辺uvが描画される。

これは一筆書きの要領で、
\ draw [thick] (u)--(v)--(w)--(x)--(y);
とすると、
\ draw [thick] (u)--(v);
\ draw [thick] (v)--(w);
\ draw [thick] (w)--(x);
\ draw [thick] (x)--(y);
と同じ描画結果を示す。


A4用紙において3つリングを描画する際の座標に関する補足

1つめ(x, y)
      
        1つ目+右4下2.5(x+4, y+2.5)

1つ目+下5(x, y+5)

プラマイ逆だったかもしれん 
'''

