function variance(file_name)

%
%variance - Specify an image name and output the pixel value variance and histogram diagram of that image.
%

img = imread(file_name);

variance = var(vec(img));

hist = myhistgram(img, 0, 255, 'raw');
save hist.dat hist

% create-hist.gp

endfunction