function threshold(file_name, th)

%
%threshold - Compression by setting values below the threshold to 0.
%

I = double(imread(file_name));

Z_tmp = [];
Z = [];
for i=1:8:256
    Z_tmp = [];
    for j=1:8:256
        G = I(i:i+7,j:j+7);
        Y = dct2(G);
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