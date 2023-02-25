function percentage(file_name, s)

%
%percentage - Compression by setting the value below the percentage to 0.
%

I = double(imread(file_name));

th_idx = round(64*s/100);

Z_tmp = [];
Z = [];
for i=1:8:256
    Z_tmp = [];
    for j=1:8:256
        G = I(i:i+7,j:j+7);
        Y = dct2(G);
        tmp = sort(abs(reshape(Y, 1, 8*8)));
        th = tmp(1, th_idx);
        Y(abs(Y) <= th) = 0;
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