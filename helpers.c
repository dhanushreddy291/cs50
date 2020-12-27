#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int averagergb = round(( image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed ) / 3.00 );

            image[i][j].rgbtBlue = averagergb;
            image[i][j].rgbtGreen = averagergb;
            image[i][j].rgbtRed = averagergb;

        }

    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            temp.rgbtBlue = image[i][j].rgbtBlue;
            temp.rgbtGreen = image[i][j].rgbtGreen;
            temp.rgbtRed = image[i][j].rgbtRed;

            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;

            image[i][width - j - 1].rgbtBlue = temp.rgbtBlue;
            image[i][width - j - 1].rgbtGreen = temp.rgbtGreen;
            image[i][width - j - 1].rgbtRed = temp.rgbtRed;

        }

    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tempimage[height][width];

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int sum[3] = {0, 0, 0}, counter = 0;
            
            for (int k = i - 1; k >= 0 && k < height && k < i + 2; k++)
            {
                for (int l = j - 1; l >= 0 && l < width && l < j + 2; l++)
                {
                    sum[0] += image[k][l].rgbtBlue;
                    sum[1] += image[k][l].rgbtGreen;
                    sum[2] += image[k][l].rgbtRed;
                    counter++;
                }
            }
            
            sum[0] = round(sum[0] / ((1.00) * counter));
            sum[1] = round(sum[1] / ((1.00) * counter));
            sum[2] = round(sum[2] / ((1.00) * counter));
            
            
            if(sum[0] > 255)
            {
                tempimage[i][j].rgbtBlue = 255;
            }
            else
            {
                tempimage[i][j].rgbtBlue = sum[0];
            }
            
            if(sum[1] > 255)
            {
                tempimage[i][j].rgbtGreen = 255;
            }
            else
            {
                tempimage[i][j].rgbtGreen = sum[1];
            }
            
            if(sum[2] > 255)
            {
                tempimage[i][j].rgbtRed = 255;
            }
            else
            {
                tempimage[i][j].rgbtRed = sum[2];
            }
        }
    }

    for (int i = 0; i< height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = tempimage[i][j].rgbtBlue;
            image[i][j].rgbtGreen = tempimage[i][j].rgbtGreen;
            image[i][j].rgbtRed = tempimage[i][j].rgbtRed;
        }

    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}