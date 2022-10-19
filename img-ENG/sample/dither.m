function [kekka] = dither(image,imtype)
%
%dither - ディザ法で濃淡画像を二値画像に変換する
%
%使用方法   : kekka=dither(image,'pgm')
%
%入力  : image - 原画像
%        imtype - 画像タイプ('pgm'/'raw')
%
%出力  : kekka - ディザ画像
%

if(imtype=="pgm")
  img=getpgm(image);
elseif(imtype=="raw")
  img=image;
else
  printf("Image type is either PGM or RAW format!!!\n");
  return
endif

sz=quadlength(img);

%原画像を16階調に再量子化する
req=fix(img/16)*16;

%ディザ行列を設定する。再量子化の関係で1づつシフトする
%さらに実際の階調値に合わせるために16倍(256/16)する
dith=[1 9 3 11;13 5 15 7;4 12 2 10;15 7 13 5];
dither=16*dith;

for i=1:4:sz
  for j=1:4:sz
    sa(i:i+3,j:j+3)=sign(req(i:i+3,j:j+3)-dither);
  endfor
endfor

%この時点でsaの内容は1、0、-1である。1、0は白、-1は黒であるので
%厳密には内容を255と0にする必要があるがここでは表示のときに強制的に255と
%0にスケーリングされるように次のような処理を行う
kekka=(sa+1)*300;

endfunction

