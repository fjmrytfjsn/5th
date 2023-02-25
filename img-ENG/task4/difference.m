function difference(file_name1, file_name2)

%
%difference - Output the difference image of the two images and save the histogram as "hist.dat".
%

img1 = double(imread(file_name1));
img2 = double(imread(file_name2));

diff = img2 - img1;

imshow(uint8(abs(diff)));

hist = myhistgram(round(diff), -255, 255, 'raw');
save hist.dat hist

endfunction