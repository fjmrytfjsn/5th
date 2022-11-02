function simple_color_change(file_name, color1, color2, another_name)

%
%simple_color_change - Loads a color image by specifying a file name, creates a new color image with the two specified color components exchanged, and saves it under a different name specified.
%

original_img = imread(file_name);

if (color1=='r'&&color2=='g' || color1=='g'&&color2=='r')
    converted_img(:,:,[1,2,3]) = original_img(:,:,[2,1,3]);
elseif (color1=='r'&&color2=='b' || color1=='b'&&color2=='r')
    converted_img(:,:,[1,2,3]) = original_img(:, :, [3, 2, 1]);
elseif (color1=='g'&&color2=='b' || color1=='b'&&color2=='g')
    converted_img(:,:,[1,2,3]) = original_img(:, :, [1, 3, 2]);
endif

imwrite(converted_img, another_name);

endfunction