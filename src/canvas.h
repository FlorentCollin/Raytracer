#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include <string>

#include "tuple.h"

class Canvas {
   private:
    int m_width{0};
    int m_height{0};
    std::vector<Color> grid;


    std::string PPM_header() const;
    size_t index(const int x, const int y) const;

   public:
    Canvas(int width, int height);
    Canvas(int width, int height, Color& c);
    int get_width() { return m_width; }
    int get_height() { return m_height; }
    void write_pixel(const int x, const int y, const Color& c);
    Color& pixel_at(const int x, const int y);
    std::string to_PPM();
};

#endif  // CANVAS_H
