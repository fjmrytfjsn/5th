function snratio=snr(image1,image2,imtype)
%
%snr - calculate SN ratio in dB. Graylevel is fixed to [0,255]
%
%Usage   : snratio = snr(image1,image2,imtype)
%
%Inputs  : image1 - base image
%          image2 - measured image
%          imtype - image type (raw/img)
%
%Outputs : sn ratio in dB
%

if(imtype=="img")
  X=imread(image1);
  Y=imread(image2);
  X=double(X);
  Y=double(Y);
  Diff=X-Y;
elseif(imtype=="raw")
  Diff=double(image1)-double(image2);
else
  printf("Image type is either PNG or RAW format!!!\n");
  return
endif

errors=Diff.**2;
mean_errors=mean(mean(errors));
snratio=10*log10(255**2/mean_errors);

endfunction

