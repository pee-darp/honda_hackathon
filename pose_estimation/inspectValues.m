img = imread('mcard.jpg');
imshow(img);
disp(size(img));

%Inspect a specific pixel value
disp(img(450,600));

%Inspect the values of a row of pixels
disp(img(450,:));

%Better way to inspect
plot(img(450,:));

%Inspect a slice of image
disp(img(100:150,200:250));