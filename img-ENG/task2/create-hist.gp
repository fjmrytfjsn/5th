reset
set macros
set encoding utf8

datafile="$0"
emffile="$0.emf"
svgfile="$0.svg"
pdffile="$0.pdf"

minlevel=$1
maxlevel=$2

#凡例の文字を引数から与える時は次の行を生かす（日本語は使えない）
keytitle="$3"
#凡例として日本語を使いたい場合は次の行を生かし、設定する
#keytitle="誤差信号"

plot [minlevel:maxlevel] datafile with boxes fs solid 1 lt -1 title keytitle

set term svg
set output svgfile
replot

set term emf
set output emffile
replot

set term pdf
set output pdffile
replot

reset
set terminal wxt 0
set output

