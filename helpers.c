// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{


    //create a buffer to allocate new pixels.
    RGBTRIPLE newImage[height][width];

    // iterate through each row
    for (int i = 0 ; i < height ; i++)
    {
         // iterate through each column passing through every RGBTRIPLE
        for ( int j = 0; j < width ; j++)
        {
            int redSum = 0;
            int greenSum = 0;
            int blueSum = 0;
          
             //DONT PAY ATTENTIO FOR NOW TO THESE BELOW COMMENTS
             //counter for pixels being add in every avg.
             //int count = 0;
             // take the average amount of RGB of every pixel in a range of 3x3 pixels
             // avg for left top corner
             /*if ( r == 0 && l == 0) {

             }
             // avg left bottom corner
             else if ( r == height - 1 && l == 0 ){

             }
             // avg right top corner
             else if ( r == 0 && l == width - 1){

             }
             // avg left bottom corner
             else if ( r == height - 1 && l == width - 1){

             }
             // avg  top side
             else if ( r == 0 && l > 0 && l != width - 1) {

             }
             // avg right side
             else if ( l == width - 1 && r > 0 && r != height - 1) {

             }
             // avg bottom side
             else if ( r == height - 1 && l > 0 && l != width - 1) {

             }
             // avg left side
             else if ( l == 0 && r > 0 && r != height - 1){

             }*/

             for ( int iy = -1 ; iy >= 1 ; iy++)
             {
                 for ( int jx = -1 ; jx >= 1 ; jx++)
                 {
                     redSum = redSum + image[i + iy][j + jx].rgbtRed;
                     greenSum = greenSum + image[i + iy][j + jx].rgbtGreen;
                     blueSum = blueSum + image[i + iy][j + jx].rgbtBlue;
                     //count++;
                     }
             }

             int avgRed = redSum / 9;
             int avgGreen = greenSum / 9;
             int avgBlue = blueSum / 9;
             newImage[i][j].rgbtRed = avgRed;
             newImage[i][j].rgbtGreen = avgGreen;
             newImage[i][j].rgbtBlue = avgBlue;

        }

    }

    for ( int y = 1 ; y < height - 1; y++)
    {
        for ( int x = 1; x < width - 1; x++)
        {
            image[y][x].rgbtRed = newImage[y][x].rgbtRed;
            image[y][x].rgbtGreen = newImage[y][x].rgbtGreen;
            image[y][x].rgbtBlue = newImage[y][x].rgbtBlue;
        }

    }

    return;
}
