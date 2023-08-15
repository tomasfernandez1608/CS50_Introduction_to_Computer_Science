#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i=0;i<height;i++)
    {
        for (int j=0;j<width;j++)
        {
            int suma = image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen;
            float average=(float)suma/3;
            image[i][j].rgbtBlue=round(average);
            image[i][j].rgbtRed=round(average);
            image[i][j].rgbtGreen=round(average);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i=0;i<height;i++)
    {
        for (int j=0;j<width;j++)
        {
            float sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            float sepiaGreen = .349 * image[i][j].rgbtRed+ .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            float sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;
            if(sepiaRed>255)
            {
                sepiaRed=255;
            }
            else if(sepiaRed<0)
            {
                sepiaRed=0;
            }
            if(sepiaGreen>255)
            {
                sepiaGreen=255;
            }
            else if(sepiaGreen<0)
            {
                sepiaGreen=0;
            }
            if(sepiaBlue>255)
            {
                sepiaBlue=255;
            }
            else if(sepiaBlue<0)
            {
                sepiaBlue=0;
            }
            image[i][j].rgbtBlue=round(sepiaBlue);
            image[i][j].rgbtRed=round(sepiaRed);
            image[i][j].rgbtGreen=round(sepiaGreen);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i=0;i<height;i++)
    {
        int auxb[width];
        int auxg[width];
        int auxr[width];
        for (int j=0;j<width;j++)
        {

            auxb[j]=image[i][j].rgbtBlue;

            auxg[j]=image[i][j].rgbtGreen;

            auxr[j]=image[i][j].rgbtRed;

        }
        for(int j=0;j<width;j++)
        {
            image[i][j].rgbtBlue=auxb[width-1-j];
            image[i][j].rgbtGreen=auxg[width-1-j];
            image[i][j].rgbtRed=auxr[width-1-j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i=0;i<height;i++)
    {
        for (int j=0;j<width;j++)
        {
            int sumab=0,sumar=0, sumag=0, cont=0;;
            if(i==0 && j==0)// esquina arriba izq
            {
                sumab=image[i][j+1].rgbtBlue + image[i+1][j].rgbtBlue+ image[i+1][j+1].rgbtBlue+image[i][j].rgbtBlue;
                sumar=image[i][j+1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed+image[i][j].rgbtRed;
                sumag=image[i][j+1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen+image[i][j].rgbtGreen;
                float prom;
                prom=(float)sumar/4;
                image[i][j].rgbtRed=round(prom);
                prom=(float)sumag/4;
                image[i][j].rgbtGreen=round(prom);
                prom=(float)sumab/4;
                image[i][j].rgbtBlue=round(prom);
            }
            else if(i==height-1 && j==0)//esquina izq abajo
            {
                    sumab=image[i][j+1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue+image[i][j].rgbtBlue ;
                    sumar=image[i][j+1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed+image[i][j].rgbtRed;
                    sumag=image[i][j+1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen+image[i][j].rgbtGreen;

                    float prom;
                    prom=(float)sumar/4;
                    image[i][j].rgbtRed=round(prom);
                    prom=(float)sumag/4;
                    image[i][j].rgbtGreen=round(prom);
                    prom=(float)sumab/4;
                    image[i][j].rgbtBlue=round(prom);
            }
            else if(i==0 && j==width-1)//esquina derecha arriba
            {
                    sumab=image[i][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j-1].rgbtBlue+image[i][j].rgbtRed ;
                    sumar=image[i][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j-1].rgbtRed+image[i][j].rgbtRed;
                    sumag=image[i][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j-1].rgbtGreen+image[i][j].rgbtGreen;

                    float prom;
                    prom=(float)sumar/4;
                    image[i][j].rgbtRed=round(prom);
                    prom=(float)sumag/4;
                    image[i][j].rgbtGreen=round(prom);
                    prom=(float)sumab/4;
                    image[i][j].rgbtBlue=round(prom);
            }
            else if(i==height-1 && j==width-1)//esquina derecha abajo
            {
                    sumab=image[i][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j-1].rgbtBlue +image[i][j].rgbtRed;
                    sumar=image[i][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j-1].rgbtRed+image[i][j].rgbtRed;
                    sumag=image[i][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen+image[i][j].rgbtGreen;

                    float prom;
                    prom=(float)sumar/4;
                    image[i][j].rgbtRed=round(prom);
                    prom=(float)sumag/4;
                    image[i][j].rgbtGreen=round(prom);
                    prom=(float)sumab/4;
                    image[i][j].rgbtBlue=round(prom);
            }
            else if(i==0 && (j>0 && j<width-1))//fila 0
            {
                    sumab=image[i][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j+1].rgbtBlue +image[i][j+1].rgbtBlue +image[i][j].rgbtBlue;
                    sumar=image[i][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j-1].rgbtRed+image[i+1][j+1].rgbtRed +image[i][j+1].rgbtRed +image[i][j].rgbtRed;
                    sumag=image[i][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j-1].rgbtGreen+image[i+1][j+1].rgbtGreen+ image[i][j+1].rgbtGreen +image[i][j].rgbtGreen;

                    float prom;
                    prom=(float)sumar/6;
                    image[i][j].rgbtRed=round(prom);
                    prom=(float)sumag/6;
                    image[i][j].rgbtGreen=round(prom);
                    prom=(float)sumab/6;
                    image[i][j].rgbtBlue=round(prom);
            }
            else if(i==height-1 && (j>0 && j<width-1))//fila height
            {
                    sumab=image[i][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i-1][j+1].rgbtBlue +image[i][j+1].rgbtBlue+image[i][j].rgbtBlue ;
                    sumar=image[i][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j-1].rgbtRed+image[i-1][j+1].rgbtRed +image[i][j+1].rgbtRed+image[i][j].rgbtRed;
                    sumag=image[i][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen+image[i-1][j+1].rgbtGreen+ image[i][j+1].rgbtGreen+image[i][j].rgbtGreen;

                    float prom;
                    prom=(float)sumar/6;
                    image[i][j].rgbtRed=round(prom);
                    prom=(float)sumag/6;
                    image[i][j].rgbtGreen=round(prom);
                    prom=(float)sumab/6;
                    image[i][j].rgbtBlue=round(prom);
            }
            else if(j==0 && (i>0 && i<height-1))//columna 0
            {
                    sumab=image[i][j+1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue + image[i-1][j+1].rgbtBlue +image[i+1][j].rgbtBlue+image[i][j].rgbtBlue  ;
                    sumar=image[i][j+1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed+image[i-1][j+1].rgbtRed +image[i+1][j].rgbtRed+image[i][j].rgbtRed;
                    sumag=image[i][j+1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen+image[i-1][j+1].rgbtGreen+ image[i+1][j].rgbtGreen+image[i][j].rgbtGreen;

                    float prom;
                    prom=(float)sumar/6;
                    image[i][j].rgbtRed=round(prom);
                    prom=(float)sumag/6;
                    image[i][j].rgbtGreen=round(prom);
                    prom=(float)sumab/6;
                    image[i][j].rgbtBlue=round(prom);
            }
            else if(j==width-1 &&(i>0 && i<height-1))//columna width
            {
                    sumab=image[i-1][j].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i][j-1].rgbtBlue + image[i+1][j-1].rgbtBlue +image[i+1][j].rgbtBlue+image[i][j].rgbtBlue ;
                    sumar=image[i-1][j].rgbtRed + image[i-1][j-1].rgbtRed + image[i][j-1].rgbtRed+image[i+1][j-1].rgbtRed +image[i+1][j].rgbtRed+image[i][j].rgbtRed;
                    sumag=image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i][j-1].rgbtGreen+image[i+1][j-1].rgbtGreen+ image[i+1][j].rgbtGreen+image[i][j].rgbtGreen;

                    float prom;
                    prom=(float)sumar/6;
                    image[i][j].rgbtRed=round(prom);
                    prom=(float)sumag/6;
                    image[i][j].rgbtGreen=round(prom);
                    prom=(float)sumab/6;
                    image[i][j].rgbtBlue=round(prom);
            }
            else
            {
                    sumab=image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i][j-1].rgbtBlue
                    + image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j-1].rgbtBlue +
                     image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue ;

                    sumar=image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed + image[i][j-1].rgbtRed
                    + image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j-1].rgbtRed +
                     image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed ;

                    sumag=image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i][j-1].rgbtGreen
                    + image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j-1].rgbtGreen +
                     image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen ;
                    float prom;
                    prom=(float)sumar/9;
                    image[i][j].rgbtRed=round(prom);
                    prom=(float)sumag/9;
                    image[i][j].rgbtGreen=round(prom);
                    prom=(float)sumab/9;
                    image[i][j].rgbtBlue=round(prom);
            }
        }

    }
    return;
}
/*
if(image[i][j-1].rgbtBlue>=0 && image[i][j-1].rgbtBlue<=255 && image[i][j-1].rgbtGreen>=0 && image[i][j-1].rgbtGreen<=255
            && image[i][j-1].rgbtRed>=0 && image[i][j-1].rgbtRed<=255)//izq - centro
            {
                sumab+=image[i][j-1].rgbtBlue;
                sumar+=image[i][j-1].rgbtRed;
                sumag+=image[i][j-1].rgbtGreen;
                cont++;
            }
            int suma2=0;
            if (image[i][j+1].rgbtBlue>=0 && image[i][j+1].rgbtBlue<=255 && image[i][j+1].rgbtGreen>=0 && image[i][j+1].rgbtGreen<=255
            && image[i][j+1].rgbtRed>=0 && image[i][j+1].rgbtRed<=255)//centro derecha
            {
                sumab+=image[i][j+1].rgbtBlue;
                sumar+=image[i][j+1].rgbtRed;
                sumag+=image[i][j+1].rgbtGreen;
                cont++;
            }
            int suma3=0;
            if (image[i+1][j].rgbtBlue>=0 && image[i+1][j].rgbtBlue<=255 && image[i+1][j].rgbtGreen>=0 && image[i+1][j].rgbtGreen<=255
            && image[i+1][j].rgbtRed>=0 && image[i+1][j].rgbtRed<=255)//centro abajo
            {
                sumab+=image[i+1][j].rgbtBlue;
                sumar+=image[i+1][j].rgbtRed;
                sumag+=image[i+1][j].rgbtGreen;
                cont++;
            }
            int suma4=0;
            if (image[i-1][j].rgbtBlue>=0 && image[i-1][j].rgbtBlue<=255 && image[i-1][j].rgbtGreen>=0 && image[i-1][j].rgbtGreen<=255
            && image[i-1][j].rgbtRed>=0 && image[i-1][j].rgbtRed<=255)//centro arriba
            {
                sumab+=image[i-1][j].rgbtBlue;
                sumar+=image[i-1][j].rgbtRed;
                sumag+=image[i-1][j].rgbtGreen;
                cont++;
            }
            int suma5=0;
            if (image[i+1][j+1].rgbtBlue>=0 && image[i+1][j+1].rgbtBlue<=255 && image[i+1][j+1].rgbtGreen>=0 && image[i+1][j+1].rgbtGreen<=255
            && image[i+1][j+1].rgbtRed>=0 && image[i+1][j+1].rgbtRed<=255)//diagonal abajo derecha
            {
                sumab+=image[i+1][j+1].rgbtBlue;
                sumar+=image[i+1][j+1].rgbtRed;
                sumag+=image[i+1][j+1].rgbtGreen;
                cont++;
            }
            int suma6=0;
            if (image[i-1][j-1].rgbtBlue>=0 && image[i-1][j-1].rgbtBlue<=255 && image[i-1][j-1].rgbtGreen>=0 && image[i-1][j-1].rgbtGreen<=255
            && image[i-1][j-1].rgbtRed>=0 && image[i-1][j-1].rgbtRed<=255)//diagonal izq arriba
            {
                sumab+=image[i-1][j-1].rgbtBlue;
                sumar+=image[i-1][j-1].rgbtRed;
                sumag+=image[i-1][j-1].rgbtGreen;
                cont++;
            }
            int suma7=0;
            if (image[i+1][j-1].rgbtBlue>=0 && image[i+1][j-1].rgbtBlue<=255 && image[i+1][j-1].rgbtGreen>=0 && image[i+1][j-1].rgbtGreen<=255
            && image[i+1][j-1].rgbtRed>=0 && image[i+1][j-1].rgbtRed<=255)//diagonal izq abajo
            {
                sumab+=image[i+1][j-1].rgbtBlue;
                sumar+=image[i+1][j-1].rgbtRed;
                sumag+=image[i+1][j-1].rgbtGreen;
                cont++;
            }
            int suma8=0;
            if (image[i-1][j+1].rgbtBlue>=0 && image[i-1][j+1].rgbtBlue<=255 && image[i-1][j+1].rgbtGreen>=0 && image[i-1][j+1].rgbtGreen<=255
            && image[i-1][j+1].rgbtRed>=0 && image[i-1][j+1].rgbtRed<=255)//diagonal derecha arriba
            {
                sumab+=image[i-1][j+1].rgbtBlue;
                sumar+=image[i-1][j+1].rgbtRed;
                sumag+=image[i-1][j+1].rgbtGreen;
                cont++;
            }
            float prom;
            prom=(float)sumar/cont;
            image[i][j].rgbtRed=round(prom);
            prom=(float)sumag/cont;
            image[i][j].rgbtGreen=round(prom);
            prom=(float)sumab/cont;
            image[i][j].rgbtBlue=round(prom);
*/