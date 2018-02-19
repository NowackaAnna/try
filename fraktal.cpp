#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int width = 1500;
    int height = 900;
    ofstream img("img.ppm");
    img << "P3" << endl;
    img << "#.." << endl;
    img << width << " " << height << endl;
    img << "256" << endl;

    for (float py=0; py<height; py++)
    {
        for (float px=0; px<width; px++)
        {
            float x0=(px/width)*3-2;
            float y0=(py/height)*2-1;
            float x=0.0;
            float y=0.0;

            int iteracja=0;
            int maxiteracji=1000;

            while ((x*x + y*y < 4) && (iteracja < maxiteracji))
            {
                float xtemp = x*x - y*y + x0;
                y = 2*x*y+y0;
                x = xtemp;
                iteracja+=1;
            }
            float kolor = 155* 0.95 * (iteracja/maxiteracji);

            img << kolor << " " << kolor+27 << " " << kolor+20 << " " << endl;

        }
    }

}
