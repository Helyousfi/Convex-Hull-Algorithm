#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "point.h"
#include "convex_hull.h"

int main() {
    std::vector<Point> points = { {0, 3}, {1, 1}, {2, 2}, {4, 4},
                                  {0, 0}, {1, 2}, {3, 1}, {3, 3} };
    std::vector<Point> hull = ConvexHull::grahamScan(points);

    std::cout << "Points in the Convex Hull:\n";
    for (const auto& point : hull) {
        std::cout << "(" << point.x << ", " << point.y << ")\n";
    }

    sf::RenderWindow window(sf::VideoMode(800, 600), "Convex Hull");

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
            shape.setPosition(point.x * 100, point.y * 100); // Scale points for visibility
            window.draw(shape);
        }

        // Draw convex hull
        sf::VertexArray lines(sf::LinesStrip, hull.size() + 1);
        for (size_t i = 0; i < hull.size(); ++i) {
            lines[i].position = sf::Vector2f(hull[i].x * 100, hull[i].y * 100);
            lines[i].color = sf::Color::Red;
        }
        // Close the hull by connecting the last point to the first
        lines[hull.size()].position = sf::Vector2f(hull[0].x * 100, hull[0].y * 100);
        lines[hull.size()].color = sf::Color::Red;

        window.draw(lines);

        window.display();
    }

    return 0;
}
