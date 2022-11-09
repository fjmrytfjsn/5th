function simple_mix(file_name_1, file_name_2, ratio, another_name)

%
%simple_color_change - Two black-and-white images of the same size are loaded, merged at a specified ratio (0 to 1), and the resulting image is saved under a different name. The resulting image is saved with the specified name.
%

img_1 = imread(file_name_1);
img_2 = imread(file_name_2);

converted_img(:,:,[1])=ratio*img_1(:,:,[1])+(1-ratio)*img_2(:,:,[1]);
converted_img(:,:,[2])=ratio*img_1(:,:,[2])+(1-ratio)*img_2(:,:,[2]);
converted_img(:,:,[3])=ratio*img_1(:,:,[3])+(1-ratio)*img_2(:,:,[3]);

imwrite(converted_img, another_name);

endfunction