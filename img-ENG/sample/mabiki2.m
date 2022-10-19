function [kekka] = mabiki2(image,imtype)
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
  printf("Image type is either Image or RAW format!!!\n");
  return
endif

[sz sy]=size(img);

i=1:sz/2;
j=1:sy/2;
kekka(i,j)=img(2*i,2*j);

%縮小ファイルをPNG形式で保存もする
imwrite(kekka,"small.png");

endfunction
