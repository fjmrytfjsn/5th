function res = dt_5(image,imtype)
%
%dither - ディザ法で濃淡画像を三値画像に変換する
%
%使用方法   : kekka=dt_5("boat.pgm",'f')
%
%入力  : image - 原画像
%        imtype - 画像タイプ('f'/'raw')
%                      生データならraw、それ以外はf
%
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

% 16階調に再量子化
req=floor(double(img)/16);

%ディザ行列を設定する。
dith=[0 8 2 10;12 4 14 6;3 11 1 9;15 7 13 5];

% 0：黒
% 255：白
% 出力レベルは0、85、170、255とする

for i=1:4:sr
  for j=1:4:sc
    now=req(i:i+3,j:j+3);
    for inner_i=1:4
      for inner_j=1:4
          ds=sign(now(inner_i,inner_j)-dith(inner_i,inner_j));
          if(now(inner_i,inner_j)<=3)
            if(ds==-1)
              kekka((i-1)+inner_i,(j-1)+inner_j)=0;
            else
              kekka((i-1)+inner_i,(j-1)+inner_j)=64;
            endif
	  elseif(now(inner_i,inner_j)<=7)
            if(ds==-1)
              kekka((i-1)+inner_i,(j-1)+inner_j)=64;
            else
              kekka((i-1)+inner_i,(j-1)+inner_j)=128;
            endif
	  elseif(now(inner_i,inner_j)<=11)
            if(ds==-1)
              kekka((i-1)+inner_i,(j-1)+inner_j)=128;
            else
              kekka((i-1)+inner_i,(j-1)+inner_j)=192;
            endif
	  else
            if(ds==-1)
              kekka((i-1)+inner_i,(j-1)+inner_j)=192;
            else
              kekka((i-1)+inner_i,(j-1)+inner_j)=255;
            endif
          endif
      endfor
    endfor
  endfor
endfor

res=uint8(kekka);

endfunction

