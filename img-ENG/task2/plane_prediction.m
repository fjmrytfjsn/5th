function plane_prediction(file_name)

%
%plane_prediction - Specify an image name and output the variance and histogram of the difference obtained by planar prediction using three pixel values around that image.
%

img = double(imread(file_name));

pred = double(zeros(size(img, 1), size(img, 2)));
dif = double(zeros(size(img, 1), size(img, 2)));

for col = 1:size(img, 1)
    pred(col, 1) = img(col, 1);
end

for row = 1:size(img, 2);
    pred(1, row) = img(1, row);
end

for row = 2:size(img, 1)
    for col = 2:size(img, 2)
        pred(row, col) = img(row-1, col) + img(row, col-1) - img(row-1, col-1);
    end
end

dif = img - pred;
dif = uint8(dif);

variance = var(vec(dif));

disp(variance);

save -text img.text img;
save -text pred.text pred;
save -text dif.text dif;

hist = myhistgram(dif, -255, 255, 'raw');
save hist.dat hist

% create-hist.gp

endfunction