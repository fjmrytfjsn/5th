function [Y,U,V]=RGB2YUV(R,G,B)
%
%RGB2YUV - convert RGB[0-255] to YUV[0-255] color space
%
% see http://vision.kuee.kyoto-u.ac.jp/~hiroaki/firewire/yuv.html
%

% 念のためdouble型へ変換
R=double(R);
G=double(G);
B=double(B);

Y =  fix( 0.299*R + 0.587*G + 0.114*B + 0.5);
U =  fix(-0.169*R - 0.331*G + 0.500*B + 0.5);
V =  fix( 0.500*R - 0.419*G - 0.081*B + 0.5);

endfunction

