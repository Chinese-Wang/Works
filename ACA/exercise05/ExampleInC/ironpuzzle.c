/***********************************************************************************
 *  Compilation:  gcc -o ironpuzzle.exe ironpuzzle.c libpng.a -lz
 *  Execution:    ironpuzzle iron-puzzle.png iron-puzzle-solved.png
 *  Dependencies: libpng.a
 * 
 *  @Max, March 8, 2020
 * 
 *  Data type for manipulating individual pixels of an image. The original
 *  image can be read from a file in jpg, gif, or png format, or the
 *  user can create a blank image of a given dimension. Includes methods for
 *  displaying the image in a window on the screen or saving to a file.
 *
 *  Remarks
 *   - pixel (x, y) is column x and row y, where (0, 0) is upper left
 *
 *  Iron Puzzles
 *  http://nifty.stanford.edu/2011/parlante-image-puzzle/
 *   
 *  The iron-puzzle.png image is a puzzle; it contains an image of something famous,
 *  however the image has been distorted. The famous object is in the red values, 
 *  however the red values have all been divided by 10, so they are too small by a 
 *  factor of 10. The blue and green values are all just meaningless random values
 *  ("noise") added to obscure the real image. You must undo these distortions to 
 *  reveal the real image. First, set all the blue and green values to 0 to get them
 *  out of the way. Look at the result .. if you look very carefully, you may see
 *  the real image, although it is very very dark (way down towards 0). Then multiply
 *  each red value by 10, scaling it back up to approximately its proper value. 
 *  What is the famous object?
 ***********************************************************************************/

#include "pngfileio.c"

void process_file (void) {
   for (int y = 0; y < height; y++) {
      png_byte* row = row_pointers[y];
      for (int x = 0; x < width; x++) {
         png_byte* ptr = &(row[x*4]);
         
         // process pixel at position x,y with RGBA values in ptr[0..3]
         // ptr[3] is the ALPHA value, no any change here

         // solve the iron puzzle for the pixel 
         int red = ptr[0] * 10;
         ptr[0] = red > 255 ? 255 : red;     // set red value to red * 10 in [0..255]
         ptr[1] = ptr[2] = 0;                // set green and blue values to 0.
      }
   }
}

void main (int argc, char **argv) {
   if (argc < 3)
      abort_( "Usage: program_name <file_in> <file_out>" );

   read_png_file( argv[1] );
   process_file();
   write_png_file( argv[2] );
}