function jpeg(file_name, q)

%
%jpeg - Compression quality is determined and compressed.
%

T = [
    16 11 10 16 24 40 51 61;
    12 12 14 19 26 58 60 55;
    14 13 16 24 40 57 69 56;
    14 17 22 29 51 87 80 62;
    18 22 37 56 68 109 103 77;
    24 35 55 64 81 104 113 92;
    49 64 78 87 103 121 120 101;
    72 92 95 98 112 100 103 99;
];

if (q>=50)
    Q = ((100-q)/50) * T;
else
    Q = (50/q) * T;
end

I = double(imread(file_name));

Z_tmp = [];
Z = [];
for i=1:8:256
    Z_tmp = [];
    for j=1:8:256
        G = I(i:i+7,j:j+7);
        Y = dct2(G);
        Y = round(Y ./ Q);
        Y = Y .* Q;
        Z_tmp = [Z_tmp idct2(Y)];
    endfor
    Z = [Z; Z_tmp];
endfor

err = Z - I;
mse = sumsq(err(:)) / numel(err);
snr = 10 * log10 (255^2 / mse);

disp(snr);

Z8 = uint8(Z);
imshow(Z8);

endfunction