function [pdata] = myhistgram(image,p_min,p_max,imtype)
%
%myhistgram - 画像のヒストグラムを求める
%
%使用方法   : pdata=myhistgram("LENNA.png",0,255,'png')
%
%入力  : image - 原画像
%      : p_min/p_max - データの最小値、最大値
%        imtype - 画像タイプ('png'/'raw')
%
%出力  : pdata - 画素値とヒストグラム
%

if(imtype=="png")
  img=imread(image);
elseif(imtype=="raw")
  img=image;
else
  printf("Image type is either PNG or RAW format!!!\n");
  return
endif

% y：横サイズ、x：縦サイズ
[sy sx]=size(img);

hist=zeros(p_max-p_min+1,1);

for i=1:sy
  for j=1:sx
    hist(img(i,j)+1+abs(p_min))+=1;		
  endfor
endfor

p_value=p_min:p_max;
pd=[p_value;hist'];
pdata=pd';


endfunction
