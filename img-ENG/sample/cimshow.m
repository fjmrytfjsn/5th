function cimshow(image)

img=imread(image);
map=gray(256);
colormap(map);
imshow(img);

endfunction
