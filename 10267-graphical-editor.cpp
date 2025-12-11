#include <iostream>
#include <vector>
#include <string>


using Image = std::vector<std::vector<char>>;


void colorize(Image& img, int x, int y, char color)
{
    if (y - 1 >= 0 && y - 1 < img.size() &&
        x - 1 >= 0 &&
        x - 1 < img[y - 1].size()) {
        img[y - 1][x - 1] = color;
    }
}


void clear(Image& img)
{
    for (int y = 0; y < img.size(); y++) {
        for (int x = 0; x < img[y].size(); x++) {
            img[y][x] = 'O';
        }
    }
}


void drawHorizontalLine(Image& img, int x1, int x2, int y, char color)
{
    if (x1 > x2)
        std::swap(x1, x2);
    for (int x = x1; x <= x2; x++) {
        colorize(img, x, y, color);
    }
}


void drawVerticalLine(Image& img, int x, int y1, int y2, char color)
{
    if (y1 > y2)
        std::swap(y1, y2);
    for (int y = y1; y <= y2; y++) {
        colorize(img, x, y, color);
    }
}


void fillIter(Image &img, int x, int y, char colorOld, char colorNew) {
  if (x < 1 || x > img[0].size() || y < 1 || y > img.size() ||
      img[y - 1][x - 1] != colorOld)
        return;
    img[y-1][x-1] = colorNew;
    fillIter(img, x - 1, y, colorOld, colorNew);
    fillIter(img, x + 1, y, colorOld, colorNew);
    fillIter(img, x, y - 1, colorOld, colorNew);
    fillIter(img, x, y + 1, colorOld, colorNew);
}


void fill(Image& img, int x, int y, char color)
{
    if (img[y-1][x-1] != color)
        fillIter(img, x, y, img[y-1][x-1], color);
}


void drawRectangle(Image& img, int x1, int y1, int x2, int y2, char color)
{
    if (x1 > x2)
        std::swap(x1, x2);
    if (y1 > y2)
        std::swap(y1, y2);
    for (int y = y1; y <= y2; y++) {
        for (int x = x1; x <= x2; x++) {
            img[y-1][x-1] = color;
        }
    }
}


void save(Image& img, const std::string &filename)
{
    std::cout << filename << '\n';
    for (int y = 0; y < img.size(); y++) {
        for (int x = 0; x < img[y].size(); x++) {
            std::cout << img[y][x];
        }
        std::cout << '\n';
    }
}


int main()
{
    std::vector<std::vector<char>> img;
    char cmd;
    while (std::cin >> cmd) {
        if (cmd == 'I') {
            int m, n;
            std::cin >> m >> n;
            img = std::vector<std::vector<char>>(n, std::vector<char>(m, 'O'));
        }

        else if (cmd == 'C') {
            clear(img);
        }
        else if (cmd == 'L') {
            int x, y;
            char c;
            std::cin >> x >> y >> c;
            colorize(img, x, y, c);
        }
        else if (cmd == 'V') {
            int x, y1, y2;
            char c;
            std::cin >> x >> y1 >> y2 >> c;
            drawVerticalLine(img, x, y1, y2, c);
        }

        else if (cmd == 'H') {
            int x1, x2, y;
            char c;
            std::cin >> x1 >> x2 >> y >> c;
            drawHorizontalLine(img, x1, x2, y, c);
        }

        else if (cmd == 'K') {
            int x1, y1, x2, y2;
            char c;
            std::cin >> x1 >> y1 >> x2 >> y2 >> c;
            drawRectangle(img, x1, y1, x2, y2, c);
        }

        else if (cmd == 'F') {
            int x, y;
            char c;
            std::cin >> x >> y >> c;
            fill(img, x, y, c);
        }

        else if (cmd == 'S') {
            std::string filename;
            std::cin >> filename;
            save(img, filename);
        }

        else if (cmd == 'X') {
            return 0;
        }

        else {
            std::string dummy;
            std::getline(std::cin, dummy); // consume the line
        }
    }
    return 0;
}
