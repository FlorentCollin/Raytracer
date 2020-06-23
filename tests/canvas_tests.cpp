#include <iostream>
#include <string>
#include <vector>

#include "canvas.h"
#include "gtest/gtest.h"

TEST(CanvasTest, InitialColor) {
    constexpr int width = 5;
    constexpr int height = 5;
    Canvas canvas(width, height);
    const Color c(0, 0, 0);
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            EXPECT_TRUE(canvas.pixel_at(x, y) == c);
        }
    }
}

TEST(CanvasTest, Index) {
    Canvas canvas(5, 5);
    Color c(1, 1, 1);
    canvas.write_pixel(2, 3, c);
    EXPECT_TRUE(canvas.pixel_at(2, 3) == c);
}

TEST(CanvasTest, WriteColor) {
    Canvas canvas(10, 20);
    Color red(1, 0, 0);
    canvas.write_pixel(2, 3, red);
    EXPECT_TRUE(canvas.pixel_at(2, 3) == red);
}

TEST(CanvasTest, ToPPMHeader) {
    Canvas canvas(80, 40);
    const std::string ppm = canvas.to_PPM();
    std::istringstream ppm_stream(ppm);
    const std::vector<std::string> expected = {"P3", "80 40", "255"};
    std::string actual_line;
    for (auto expected_line : expected) {
        std::getline(ppm_stream, actual_line);
        EXPECT_EQ(actual_line, expected_line);
    }
}

TEST(CanvasTest, PPMFormat) {
    Canvas canvas(5, 3);
    canvas.write_pixel(0, 0, Color(1.5, 0, 0));
    canvas.write_pixel(2, 1, Color(0, 0.5, 0));
    canvas.write_pixel(4, 2, Color(-0.5, 0, 1));
    const std::string ppm = canvas.to_PPM();
    const std::string expected =
        "P3\n"
        "5 3\n"
        "255\n"
        "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n"
        "0 0 0 0 0 0 0 128 0 0 0 0 0 0 0 \n"
        "0 0 0 0 0 0 0 0 0 0 0 0 0 0 255 \n";
    EXPECT_EQ(ppm, expected);
}

TEST(CanvasTest, PPMFormatMax70) {
    const int width = 10;
    const int height = 2;
    Canvas canvas(width, height);
    Color c(1, 0.8, 0.6);
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            canvas.write_pixel(i, j, c);
        }
    }
    const std::string ppm = canvas.to_PPM();
    const std::string expected =
        "P3\n"
        "10 2\n"
        "255\n"
        "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204 \n"
        "153 255 204 153 255 204 153 255 204 153 255 204 153 \n"
        "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204 \n"
        "153 255 204 153 255 204 153 255 204 153 255 204 153 \n";
    EXPECT_EQ(ppm, expected);
}
