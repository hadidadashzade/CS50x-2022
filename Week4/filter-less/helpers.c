#include "helpers.h"

// math.h : round
#include <math.h> //round a number to the nearest integer

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float RY;

    for (int r = 0; r < height; r++)
    {
        for (int g = 0; g < width; g++)
        {
            RY = round((image[r][g].rgbtBlue + image[r][g].rgbtGreen + image[r][g].rgbtRed) / 3.00);

            image[r][g].rgbtBlue = RY;
            image[r][g].rgbtGreen = RY;
            image[r][g].rgbtRed = RY;

        }
    }
    return;
}

int limit(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }
    return RGB;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sbe;
    int srd;
    int sgn;
    for (int j = 0; j < height; j++)
    {
        for (int p = 0; p < width; p++)
        {
            sbe = limit(round(0.272 * image[j][p].rgbtRed + 0.534 * image[j][p].rgbtGreen + 0.131 * image[j][p].rgbtBlue));
            sgn = limit(round(0.349 * image[j][p].rgbtRed + 0.686 * image[j][p].rgbtGreen + 0.168 * image[j][p].rgbtBlue));
            srd = limit(round(0.393 * image[j][p].rgbtRed + 0.769 * image[j][p].rgbtGreen + 0.189 * image[j][p].rgbtBlue));

            image[j][p].rgbtBlue = sbe;
            image[j][p].rgbtGreen = sgn;
            image[j][p].rgbtRed = srd;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int TP[3];
    for (int k = 0; k < height; k++)
    {
        for (int i = 0; i < width / 2; i++)
        {
            TP[0] = image[k][i].rgbtBlue;
            TP[1] = image[k][i].rgbtGreen;
            TP[2] = image[k][i].rgbtRed;

            image[k][i].rgbtBlue = image[k][width - i - 1].rgbtBlue;
            image[k][i].rgbtGreen = image[k][width - i - 1].rgbtGreen;
            image[k][i].rgbtRed = image[k][width - i - 1].rgbtRed;

            image[k][width - i - 1].rgbtBlue = TP[0];
            image[k][width - i - 1].rgbtGreen = TP[1];
            image[k][width - i - 1].rgbtRed = TP[2];

        }
    }
    return;
}

int getBlur(int i, int j, int height, int width, RGBTRIPLE image[height][width], int color_position)
{
    float OE = 0;
    int UU = 0;
    
    for (int e = i - 1; e < (i + 2); e++)
    {
        for (int o = j - 1; o < (j + 2); o ++)
        {
            if (e < 0 || o < 0 || e >= height || o >= width)
            {
                continue;
            }
            if (color_position == 0)
            {
                UU += image[e][o].rgbtRed;
            }
            else if (color_position == 1)
            {
                UU += image[e][o].rgbtGreen;
            }
            else
            {
                UU += image[e][o].rgbtBlue;
            }
            OE++;

        }
    }
    return round(UU / OE);
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    
    for (int u = 0; u < height; u++)
    {
        for (int d = 0; d < width; d++)
        {
            copy[u][d] = image[u][d];
        }
    }
    
    for (int s = 0; s < height; s++)
    {
        for (int a = 0; a < width; a++)
        {
            image[s][a].rgbtRed = getBlur(s, a, height, width, copy, 0);
            image[s][a].rgbtGreen = getBlur(s, a, height, width, copy, 1);
            image[s][a].rgbtBlue = getBlur(s, a, height, width, copy, 2);
        }
    }
    return;
}
