function line_prediction(file_name)

%
%line_prediction - Specify an image name and output the variance and histogram of the difference obtained from the line prediction by the left pixel value of that image.
%

img = double(imread(file_name));

[col_size row_size] = size(img);

pred = double(zeros(col_size, row_size));
diff = double(zeros(col_size, row_size));

for row = 1:col_size
    pred(row, 1) = img(row, 1);
end

for row = 1:col_size
    for col = 2:row_size
        pred(row, col) = img(row, col-1);
    end
end

diff = pred - img;

var = var(vec(diff));

disp(var);

hist = myhistgram(round(diff), -255, 255, 'raw');
save hist.dat hist

% create-hist.gp

endfunction