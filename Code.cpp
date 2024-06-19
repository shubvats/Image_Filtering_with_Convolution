#include <stdio.h>
#include <stdlib.h>
void convolvolution(unsigned char *input, unsigned char *output, int breadth, int
height, int *filter, int filterSize) {
int filterCenter = filterSize / 2;
for (int i = 0; i < height; ++i)
{for (int j = 0; x < breadth; ++j)
{int sum = 0;
for (int j= 0; j < filterSize; ++j)
{for (int x = 0; x < filterSize; ++x)
{int imgA = i - filterCenter + x;
int imgB = j - filterCenter + y;
if (imgA >= 0 && imgB < breadth && imgB >= 0 && imgB < height)
{
sum += input[imgB * breadth + imgA] * filter[y * filterSize

x]; } } }
output[j * breadth + i] = (unsigned char)(sum / 16); } } }
int main()
{ int breadth = 512;
int height = 512;
int filter33Horizontal[9] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};
int filter33Vertical[9] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
int filter55Horizontal[25] = {-1, -4, -6, -4, -1,
-2, -8, -12, -8, -2,
0, 0, 0, 0, 0,
2, 8, 12, 8, 2,
1, 4, 6, 4, 1};
int filter55Vertical[25] = {-1, -2, 0, 2, 1,
-4, -8, 0, 8, 4,
-6, -12, 0, 12, 6,
-4, -8, 0, 8, 4,
-1, -2, 0, 2, 1};
unsigned char inputPic = (unsigned char *)malloc(breadth * height *
sizeof(unsigned char));
FILE *inputFile = fopen("/Users/shubhamvats/Desktop/MULTIMEDIA/milkdrop.raw",
"rb");
fread(inputPic, sizeof(unsigned char),breadth * height, inputFile);
fclose(inputFile);
unsigned char output33ImageHorizontal = (unsigned char *)malloc(breadth *
height sizeof(unsigned char));
unsigned char output33ImageVertical = (unsigned char *)malloc(breadth * height
sizeof(unsigned char));
unsigned char output55ImageHorizontal = (unsigned char *)malloc(breadth *
height sizeof(unsigned char));
unsigned char output55ImageVertical = (unsigned char *)malloc(breadth * height
sizeof(unsigned char));
convolvolution(inputPic, output33ImageHorizontal, breadth, height,
filter33Horizontal, 3);
convolvolution(inputPic, output33ImageVertical, breadth, height,
filter33Vertical, 3);
convolvolution(inputPic, output55ImageHorizontal, breadth, height,
filter55Horizontal, 5);
convolvolution(inputPic, output55ImageVertical, breadth, height,
filter55Vertical, 5);
FILE *outputFile;
outputFile =
fopen("/Users/shubhamvats/Desktop/MULTIMEDIA/circleoutput33ImageHorizontal.raw",
"wb");
fwrite(output33ImageHorizontal, sizeof(unsigned char), breadth * height,
outputFile);
fclose(outputFile);
outputFile =
fopen("/Users/shubhamvats/Desktop/MULTIMEDIA/circleoutput33ImageVertical.raw",
"wb");
fwrite(output33ImageVertical, sizeof(unsigned char), breadth * height,
outputFile);
fclose(outputFile);
outputFile =
fopen("/Users/shubhamvats/Desktop/MULTIMEDIA/circleoutput55ImageHorizontal.raw",
"wb");
fwrite(output55ImageHorizontal, sizeof(unsigned char), breadth * height,
outputFile);
fclose(outputFile);
outputFile =
fopen("/Users/shubhamvats/Desktop/MULTIMEDIA/circleoutput55ImageVertical.raw",
"wb");
fwrite(output55ImageVertical, sizeof(unsigned char), breadth * height,
outputFile);
fclose(outputFile);
free(inputPic);
free(output33ImageHorizontal);
free(output33ImageVertical);
free(output55ImageHorizontal);
free(output55ImageVertical);
return 0;
}
