function res = dt_2(image,imtype)
%
%dither - ディザ法で濃淡画像を二値画像に変換する
%
%使用方法   : kekka=dt_2(image,'f')
%
%入力  : image - 原画像
%        imtype - 画像タイプ('f'/'raw')
%                      生データならraw、それ以外はf
%出力  : kekka - ディザ画像
%

if(imtype=="f")
  img=imread(image);
elseif(imtype=="raw")
img=image;
else
  printf("Image type is either PNG or RAW format!!!\n");
  return
endif

% 画像の大きさを取得
[sr sc]=size(img);

%原画像を16階調に再量子化する。データ型をdoubleとして扱う。
req=floor(double(img)/16);

%ディザ行列を設定する。
dith=[0 8 2 10;12 4 14 6;3 11 1 9;15 7 13 5];

for i=1:4:sr
  for j=1:4:sc
    sa(i:i+3,j:j+3)=sign(req(i:i+3,j:j+3)-dith);
  endfor
endfor

%この時点でsaの内容は1、0、-1である。1、0はディザ行列の値以上な
%ので白、-1はディザ行列より小さいので黒。
%画素値なので内容を255と0にする必要がある
% 画像においては 0：黒、255：白
for i=1:sr
  for j=1:sc
    if(sa(i,j)==-1)
      kekka(i,j)=0;
    else
      kekka(i,j)=255;
    endif
  endfor
endfor

%一応画像のデータ型であるuint8に変換
res=uint8(kekka);

endfunction

