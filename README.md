
# Image Filtering with Convolution

## Description

This C/C++ program reads in raw format images and performs filtering by convolving them with small operators of 3×3 and 5×5 coefficients. The program applies differentiation by difference using edge operators such as the Sobel Operator in x and y directions. It computes horizontal and vertical differential images separately and saves them for display.

## Input Images

1. **Circle Image**: Created using Photoshop with a dark intensity circle inside it.
2. **Unesco-1.png**: Provided in the file page of CANVAS.
3. **Custom Image**: Any small-sized image selected by the user.

## Output Images

The resulting images are saved in raw format and converted to jpg/png format as well. The output images include:

1. Horizontal and vertical difference images for 3×3 filter size.
2. Horizontal and vertical difference images for 5×5 filter size.

## Program Details

The program applies convolution with 3×3 and 5×5 filters to perform image filtering. It then normalizes the filtered results to prevent overflow.

## Usage

1. Compile the program.
2. Execute the compiled binary.
3. Input the file paths for the raw format images.
4. Check the output images generated in the specified directory.

## Repository Contents

1. **Source Code**: Main.cpp
2. **Input Images**: Circle.raw, Unesco-1.png, CustomImage.raw
3. **Output Images**: (To be generated by running the program)

## Author

Shubham Vats

---
