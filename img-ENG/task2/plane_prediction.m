function plane_prediction(file_name)

%
%plane_prediction - Specify an image name and output the variance and histogram of the difference obtained by planar prediction using three pixel values around that image.
%

img = double(imread(file_name));

[col_size row_size] = size(img);

pred = double(zeros(col_size, row_size));
diff = double(zeros(col_size, row_size));

for col = 1:col_size
    pred(col, 1) = img(col, 1);
end

for row = 1:row_size
    pred(1, row) = img(1, row);
end

for row = 2:col_size
    for col = 2:row_size
        pred(row, col) = img(row-1, col) + img(row, col-1) - img(row-1, col-1);
    end
end

diff = img - pred;

var = var(vec(diff));

disp(var);

hist = myhistgram(round(diff), -255, 255, 'raw');
save hist.dat hist

endfunction