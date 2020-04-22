/***********************************************************************************/
/*   							Detection algorithm 							   */
/*  Detects a set of pixels from a background and calculates the centroid of the   */
/*	detected pixels. This tests the algorithms ability to recognize the pixels     */
/*	that form a "blob", or some sort of object, in an image in order to track      */
/*	said blob/object															   */
/***********************************************************************************/

#include <iostream>
#include <utility>
#include <vector>
#include "Display.hpp"
#include "Pixel.hpp"

using namespace std;


Display disp(25, 25);

void displayPixels();
void setPixels(int row, int pixel, int red, int green, int blue, int alpha);
pair<int, int> blobDetection(Display disp);

/************************************************************************/
/* displayPixels()	-	Declares the colors of certain pixels in order  */
/*						to test the algorithm						    */
/*						Current test sets three red pixels to provide   */
/*						our "blob", expected print-out to provide	    */
/*						location of center of blob at [6][3]		    */
/************************************************************************/
void displayPixels()
{
  /* create the blob vector */
  /* vector<vector> for whole image */
  std::vector<std::vector<Display>> blob; // @depricated

  /* Set various pixels to be 255 red, 0 green, 0 blue and 0 alpha */
  /* centroid expected to be at location [6][3] */
  setPixels(1, 2, 255, 0, 0, 0);
  setPixels(3, 3, 255, 0, 0, 0);
  setPixels(14, 4, 255, 0, 0, 0);
}

/************************************************************************/
/* setPixels()		-	Utility function that sets the colors of pixels */
/*						whos info is passed in by displayPixels()		*/
/************************************************************************/
/* Accepted Values 	- 	  row: What row the pixel is located in			*/
/*						pixel: What col the pixel is located in, 		*/
/*							   ultimately named "pixel" as after row	*/
/*							   is also defined, this is the actual 		*/
/*							   pixel that will be worked with			*/
/*						  red: The value of red for the pixel, will set	*/
/*							   the RedChannel of the Pixel class as		*/
/*							   defined in Pixel.hpp						*/
/*						green: The value of green for the pixel, will 	*/
/*							   set the GreenChannel of the Pixel class 	*/
/*							   as defined in Pixel.hpp					*/
/*						 blue: The value of blue for the pixel, will 	*/
/*						       set the BlueChannel of the Pixel class 	*/
/*							   as defined in Pixel.hpp					*/
/*						alpha: The value of trransparency for the 		*/
/*							   pixel, will set the AlphaChannel of the 	*/
/*							   Pixel  class as defined in Pixel.hpp		*/
/************************************************************************/
void setPixels(int row, int pixel, int red, int green, int blue, int alpha)
{
  (disp.ImageMatrix[row][pixel]).RedChannel   = red;
  (disp.ImageMatrix[row][pixel]).GreenChannel = green; 
  (disp.ImageMatrix[row][pixel]).BlueChannel  = blue;
  (disp.ImageMatrix[row][pixel]).AlphaChannel = alpha;
}

/************************************************************************/
/* blobDetection()	-	The algorithm to detect a "blob" from a given	*/
/*						background/image								*/
/*						The algorithm begins by searching for the given */
/*						pixels, for the blob, in the display. Once a 	*/
/*						pixel is found, its location is stored as the x	*/
/*						and y variables. Once all pixels are found, 	*/
/*						calculations begin to average the rows and cols	*/
/*						- row and pixel - in order to find the center 	*/
/*						of the blob										*/
/************************************************************************/
pair<int, int> blobDetection(Display disp)
{
  int storeRow, avgRow, storePixel, avgPixel;
  int x=0, y=0, count=0;

  // Loop through each pixel in disp
  // Loop through a row of pixels first - vector<Pixel> row
  // Then loop through each pixel in the row - Pixel pixel
  for(vector<Pixel> row : disp.ImageMatrix)
  {
    x=0;

    for(Pixel pixel : row) /* loop through every pixel in the row */
    {
      // Determine pixel's color
      // If correct color, get pixel displacement from the center of image
      // Take displacement and average it 
      if(pixel.RedChannel == 255) /* When the pixel is RED: */
      {
        count++;
        storeRow = storeRow + y; /* Accumulate the location of the y position of the pixel */
        storePixel = storePixel + x; /* Accumulate the location of the x position of the pixel */
      } 
      
      x++;  /* Move the cursor right one pixel */
    }

    y++; /* Move the cursor down one pixel */
  }

  // Average the rows and columns to get center of blob 
  avgRow = storeRow / count;
  avgPixel = storePixel / count; 

  return make_pair(avgRow, avgPixel); 
}

/************************************************************************/
/* main()			-	Main driver program to test algorithm		    */
/************************************************************************/
int main() 
{
  int x, y;
  pair<int,int> returnedPair;
  
  // Call algorithm blobDetection 
  displayPixels();
  
  // Test drive algorithm 
  // Collect the results here and print to screen 
  returnedPair = blobDetection(disp);

  x = returnedPair.first;
  y = returnedPair.second; 
  
  cout << "Here's the center of your blob, at [" << x << "][" << y << "]" << endl;
}
