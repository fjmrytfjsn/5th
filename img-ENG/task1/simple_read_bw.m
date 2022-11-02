function simple_read_bw(file_name, another_name)

%
%simple_read_bw - read and show image file and save it as another name file
%

img=imread(file_name);
imshow(img);
imwrite(img, another_name);

endfunction