
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<cstdlib>
#include<ctime>
#include <conio.h>
#include<iostream>
#include <cmath>
#include<sstream>
#include<string>

int main()
{
    int keyonoff=1;
   	const float a=1000;
	const float b=600;
    srand(time(NULL));
    int i = rand()%(300)+1;
    int score=0;
    sf::RenderWindow window(sf::VideoMode(a,b), "Niby_Gra");
    sf::RectangleShape rectangle(sf::Vector2f(20, 120));
    rectangle.setFillColor(sf::Color::Green);
    sf::CircleShape shape(30.f);
    shape.setFillColor(sf::Color::Blue);
    sf::Text text;
    const float p=400;
    float q=400;
    float vq=0.2;
    float x=900;
    const float y=480;
    float c=x;
    float dt=0.4;
    float z=0.007;
    float dq=0;
    float u=rand()%(110)+70;
    u=u/100;
    u =-u;
    int help=0;
    int try_again=1;
    float vq_up=20;
    while (window.isOpen())
    {
        sf::Event event;
        rectangle.setPosition(c, y);
        shape.setPosition(p, q);
        q=q+vq;
        if(q>=b-60)
        {
            vq=0;
        }
        else
        {
            vq=0.2+dq;
        }
        c=c+u*dt;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if(event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }
            if(event.key.code == sf::Keyboard::Up)
            {
                if (q>=b-60)
                {
                    q=q-220;
                }
            }
            if(try_again==0)
            {
                if(event.key.code == sf::Keyboard::Space)
                {
                    help=0;
                    c=x;
                    rectangle.setPosition(c, y);
                    window.draw(rectangle);
                    i = rand()%(300)+1;
                    u=rand()%(110)+70;
                    u=u/100;
                    u =-u;
                    u=u*dt;
                    dt=dt+z;
                    dt=0.4;
                    z=0.007;
                    dq=dq+z;
                    dq=0;
                    score=0;
                    shape.setFillColor(sf::Color::Blue);
                    rectangle.setFillColor(sf::Color::Green);

                }
            }
        }
        window.clear(sf::Color::White);
        if(keyonoff)
        {
            window.draw(text);
            window.draw(shape);
            window.draw(rectangle);


            if (help==0)
            {


            if (round(c)>=p&&round(c)<=p)
                {

                    if (y-60<=q-15)
                    {
                        vq=0;
                        dq=0;
                        u=0;
                        dt=0;
                        z=0;
                        window.clear(sf::Color::Black);
                        std::cout<<"Game Over"<<std::endl;
                        std::cout<<"Zdobyte punkty: "<<score<<std::endl;
                        std::cout<<"Aby sprobowac ponownie kliknij spacje"<<std::endl;
                        help = 1;
                        try_again=0;
                    }
                    else
                    {
                        score=score+1;
                        if (score%10==0)
                        {
                            shape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
                        }
                        std::cout<<score<<std::endl;
                        help = 1;

                    }
                }
            }
            if (c<=i)
            {
                std::cout<<i<<"---"<<dt<<"---"<<u<<std::endl;
                c=x;
                rectangle.setPosition(c, y);
                window.draw(rectangle);
                i = rand()%(300)+1;
                u=rand()%(110)+70;
                u=u/100;
                u =-u;
                u=u*dt;
                dt=dt+z;
                help = 0;
                dq=dq+z;
                rectangle.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));


        }
        }
        window.display();
    }
    return 0;
}
