#include "canvas.h"

#include <sstream>

Canvas::Canvas(int width, int height) : m_width{width}, m_height{height} {
    const size_t size = static_cast<size_t>(m_width * m_height);
    grid = std::vector<Color>(size, Color(0, 0, 0));
}

Canvas::Canvas(int width, int height, Color& c) : m_width{width}, m_height{height} {
    const size_t size = static_cast<size_t>(m_width * m_height);
    grid = std::vector<Color>(size, c);
}


size_t Canvas::index(const int x, const int y) const {
    return static_cast<size_t>(y * m_width + x);
}

void Canvas::write_pixel(const int x, const int y, const Color& c) {
    grid[index(x, y)] = c;
}

Color& Canvas::pixel_at(const int x, const int y) { return grid[index(x, y)]; }

std::string Canvas::PPM_header() const {
    std::stringstream s;
    s << "P3\n" << m_width << " " << m_height << "\n255";
    const std::string header = s.str();
    return header;
}

std::string Canvas::to_PPM() {
    std::stringstream s;
    // Start the body of the PPM file with a new line
    s << '\n';

    auto const len = [](int val) {
        if (val < 10) {
            // Then the len of the string corresponding to the color is 2
            // Since 1 character is taken by the color itself and the second
            // character is taken by the space needed between each color.
            return 2;
        }
        return val < 100 ? 3 : 4;
    };

    auto const limit = [](double val) {
        if (val < 0) {
            return 0;
        }
        return val > 255 ? 255 : static_cast<int>(val);
    };

    for (int y = 0; y < m_height; y++) {
        int pos_line = 0;
        for (int x = 0; x < m_width; x++) {
            Color c = pixel_at(x, y);
            c *= 255;
            c.round();
            // Write the RGB value of the Color `c`
            for (size_t i = 0; i < 3; i++) {
                int value_255 = limit(c.m_elems[i]);
                pos_line += len(value_255);
                // The PPM file format doesn't accept line longer than 70 chars.
                if (pos_line > 70) {
                    s << '\n';
                    pos_line = 0;
                }
                s << value_255 << " ";
            }
        }
        s << '\n';
    }
    return PPM_header() + s.str();
}

