function snratio=csnr(image1,image2)
%
%snr - calculate color PNG image SN ratio in dB.
%
%Usage   : snratio = csnr(image1,image2)
%
%Inputs  : image1 - base image
%          image2 - measured image
%
%Outputs : sn ratio in dB
%

[XR XG XB]=imread(image1);
[YR YG YB]=imread(image2);
XR=double(XR);
XG=double(XG);
XB=double(XB);

YR=double(YR);
YG=double(YG);
YB=double(YB);

Diff_R=XR-YR;
Diff_G=XG-YG;
Diff_B=XB-YB;

errors_r=Diff_R.**2;
errors_g=Diff_G.**2;
errors_b=Diff_B.**2;

mean_errors_r=mean(mean(errors_r));
mean_errors_g=mean(mean(errors_g));
mean_errors_b=mean(mean(errors_b));

snratio=10*log10(255**2/(mean_errors_r+mean_errors_g+mean_errors_b)/3);

endfunction

