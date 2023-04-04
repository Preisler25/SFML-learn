#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "sizes.hpp"

void drawall(sf::RenderWindow&win, float nums[]) {
    int len = sizeof(nums) / sizeof(float);
    std::cout << "len: " << len;
    for (int i = 0; i < sizeof(nums); i ++) {
        sf::Vector2f vect(1, nums[i]);
        sf::RectangleShape rect;
        rect.setSize(vect);
        sf::Vector2f pos(i, 0);
        rect.setPosition(pos);
        win.draw(rect);
    }
}

int main()
{
    const int screen_width = 1280;
    const int screen_height = 720;

    sf::RenderWindow window(sf::VideoMode(screen_width, screen_height), "bubble sort");
    window.setFramerateLimit(1);

    float nums[] = { 10, 20, 30, 210, 321, 10, 21, 34, 535, 32, 25, 76, 12, 16, 845, 309, 485, 851, 1167, 1072, 981, 346, 525, 7, 461, 98, 212, 1155, 981, 985, 1098, 205, 838, 123, 362, 148, 446, 949, 604, 270, 674, 1168, 320, 640, 931, 237, 1094, 635, 31, 79, 1083, 908, 562, 415, 305, 302, 613, 336, 662, 676, 680, 162, 26, 240, 109, 1179, 267, 473, 207, 465, 576, 711, 1025, 831, 740, 728, 214, 269, 230, 163, 41, 695, 1137, 1043, 375, 799, 707, 801, 1006, 893, 1060, 1022, 1195, 609, 949, 404, 377, 424, 619, 972, 93, 1200, 463, 625, 313, 1199, 798, 537, 1153, 1081, 872, 1134, 187, 83, 399, 708, 1115, 21, 928, 562, 296, 68, 605, 743, 563, 532, 244, 649, 801, 540, 179, 93, 329, 715, 593, 198, 1126, 1136, 695, 285, 11, 1021, 1062, 69, 202, 387, 259, 818, 838, 1094, 1182, 581, 856, 1056, 469, 842, 971, 764, 212, 485, 861, 1098, 819, 947, 898, 51, 500, 83, 946, 72, 1043, 991, 1132, 1042, 1062, 969, 307, 727, 1100, 206, 84, 43, 683, 786, 694, 1191, 1019, 654, 463, 496, 1108, 212, 315, 569, 574, 603, 981, 832, 373, 163, 1166, 823, 1092, 53, 356, 1172, 480, 1026, 908, 35, 701, 6, 1156, 19, 691, 983, 645, 931, 282, 444, 276, 1004, 969, 1061, 737, 695, 677, 17, 174, 889, 54, 1065, 271, 704, 644, 796, 317, 662, 1084, 211, 64, 753, 775, 940, 785, 344, 582 };


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();

        }
      
        //render
        window.clear();
        drawall(window, nums);
        window.display();
    }

    return 0;
}

