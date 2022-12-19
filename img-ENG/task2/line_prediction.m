function line_prediction(file_name)

%
%line_prediction - Specify an image name and output the variance and histogram of the difference obtained from the line prediction by the left pixel value of that image.
%

img = double(imread(file_name));

pred = zeros(size(img, 1), size(img, 2));

for row = 1:size(img, 1)
    pred(row, 1) = img(row, 1);
end

for row = 1:size(img, 1)
    for col = 2:size(img, 2)
        pred(row, col) = img(row, col-1);
    end
end

dif = pred - img;

var = var(vec(dif));

save -text img.text img;
save -text pred.text pred;
save -text dif.text dif;

disp(var);

hist = myhistgram(dif, -255, 255, 'raw');
save hist.dat hist

% create-hist.gp

endfunction