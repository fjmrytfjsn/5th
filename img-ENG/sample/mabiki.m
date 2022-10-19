function kekka = mabiki(image,imtype)
%
%mabiki - 単純サブサンプリングで画像を縦横半分に縮小する
%
%使用方法   : kekka=mabiki(image,'img')
%
%入力  : image - 原画像
%        imtype - 画像タイプ('img'/'raw')
%
%出力  : kekka - 縮小画像
%

if(imtype=="img")
  img=imread(image);
elseif(imtype=="raw")
  img=image;
else
  printf("画像形式は画像形式か生データのみです!!!\n");
  return
endif

[sz sy]=size(img);

for i=1:sz/2
  for j=1:sy/2
    kekka(i,j)=img(2*i,2*j);
  endfor
endfor

endfunction
