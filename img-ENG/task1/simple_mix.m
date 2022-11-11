function simple_mix(file_name_1, file_name_2, ratio, another_name)

%
%simple_color_change - Two black-and-white images of the same size are loaded, merged at a specified ratio (0 to 1), and the resulting image is saved under a different name. The resulting image is saved with the specified name.
%

img_1 = imread(file_name_1);
img_2 = imread(file_name_2);

imwrite(converted_img, another_name);

endfunction