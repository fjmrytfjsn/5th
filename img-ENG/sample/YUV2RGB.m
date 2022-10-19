function [R,G,B]=YUV2RGB(Y,U,V)
%
%RGB2YUV - convert YUV[0-255] to RGB[0-255] color space
%
% see http://vision.kuee.kyoto-u.ac.jp/~hiroaki/firewire/yuv.html
%

% 念のためdouble型へ変換
Y=double(Y);
U=double(U);
V=double(V);

R = fix(1.000*Y           + 1.402*V + 0.5);
G = fix(1.000*Y - 0.344*U - 0.714*V + 0.5);
B = fix(1.000*Y + 1.772*U           + 0.5);

endfunction

