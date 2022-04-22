#ifndef DRAW_H
#define DRAW_H

enum RectMode {CENTER, CORNER};

class Draw
{
private:
    // To control whether you draw from corner or center
    RectMode rm;
public:
    Draw();
    void drawLine();
    void drawRectangle();
    void drawSquare();
    void drawEllipse();
};

#endif // DRAW_H
