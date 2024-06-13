#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "point.h"
#include "convex_hull.h"

int main() {
    std::vector<Point> points = {
        {100, 200}, {300, 400}, {500, 100}, {700, 300}, {900, 500},
        {50, 300}, {150, 100}, {450, 450}, {650, 50},
        {0, 0}, {200, 200}, {400, 600}, {600, 800}, {800, 400},
        {350, 500}, {550, 100}, {750, 400}, {950, 200}, {850, 850},
        {1000, 200}, {700, 550}, {900, 750}, {100, 400}, {1000, 650},
        {600, 500}, {800, 700}, {300, 150}, {500, 350}, {900, 600},
        {300, 800}, {50, 50}, {450, 50}, {250, 250}, {850, 200},
        {400, 50}, {600, 250}, {800, 450}, {200, 850}, {500, 200},
        {900, 400}, {700, 400}, {100, 100}, {200, 300},
        {400, 300}, {650, 650}, {1000, 50}, {150, 300}, {950, 400}
    };

    std::vector<Point> hull = ConvexHull::grahamScan(points);

    std::cout << "Points in the Convex Hull:\n";
    for (const auto& point : hull) {
        std::cout << "(" << point.x << ", " << point.y << ")\n";
    }

    sf::RenderWindow window(sf::VideoMode(1050, 1050), "Convex Hull");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        // Draw points
        for (const auto& point : points) {
            sf::CircleShape shape(5);
            shape.setFillColor(sf::Color::White);
            shape.setPosition(point.x - 2.5 , point.y - 2.5 ); // Scale points for visibility
            window.draw(shape);
        }

        // Draw convex hull
        sf::VertexArray lines(sf::LinesStrip, hull.size() + 1);
        for (size_t i = 0; i < hull.size(); ++i) {
            lines[i].position = sf::Vector2f(hull[i].x , hull[i].y );
            lines[i].color = sf::Color::Red;
        }
        // Close the hull by connecting the last point to the first
        lines[hull.size()].position = sf::Vector2f(hull[0].x , hull[0].y );
        lines[hull.size()].color = sf::Color::Red;

        window.draw(lines);

        window.display();
    }

    return 0;
}
