function zigzag_scan(file_name, s)

%
%zigzag - Compress by setting the value below the percentage to 0 after a zigzag scan.
%

zigzag_mat = [
    1 3 4 10 11 21 22 36;
    2 5 9 12 20 23 35 37;
    6 8 13 19 24 34 38 49;
    7 14 18 25 33 39 48 50;;
    15 17 26 32 40 47 51 58;
    16 27 31 41 46 52 57 59;
    28 30 42 45 53 56 60 63;
    29 43 44 54 55 61 62 64;
];

I = double(imread(file_name));

th_idx = round(64*(1-s/100));

Z_tmp = [];
Z = [];
for i=1:8:256
    Z_tmp = [];
    for j=1:8:256
        G = I(i:i+7,j:j+7);
        Y = dct2(G);
        tmp = zigzag(Y);
        tmp(1, th_idx:8*8) = 0;
        for r=1:8
            for c=1:8
                Y(r, c) = tmp(1, zigzag_mat(r, c));
            endfor
        endfor
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