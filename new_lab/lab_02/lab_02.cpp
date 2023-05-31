#include <iostream>

// Базовый класс Фигура
class Figure {
public:
    virtual void draw() = 0; // Виртуальная функция прорисовки фигуры
    virtual void move(int x, int y) = 0; // Виртуальная функция перемещения фигуры
};

// Прозводный класс Точка от Фигуры
class Point : public Figure {
private:
    int x, y; // Координаты точки
public:
    Point(int x, int y) : x(x), y(y) {}

    void draw() override {
        std::cout << "Прорисовка точки с координатами " << x << "," << y << std::endl;
    }

    void move(int x, int y) override {
        this->x = x;
        this->y = y;
        std::cout << "Перемещение точки в координаты " << x << "," << y << std::endl;
    }
};

// Прозводный класс Линия от Фигуры
class Line : public Figure {
private:
    int x1, y1, x2, y2; // Координаты начальной и конечной точек линии
public:
    Line(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}

    void draw() override {
        std::cout << "Прорисовка линии с координатами " << x1 << "," << y1 << " и " << x2 << "," << y2 << std::endl;
    }

    void move(int x, int y) override {
        int dx = x - x1;
        int dy = y - y1;
        x1 += dx;
        y1 += dy;
        x2 += dx;
        y2 += dy;
        std::cout << "Перемещение линии на (" << dx << "," << dy << ")" << std::endl;
    }
};

// Прозводный класс Окружность от Фигуры
class Circle : public Figure {
private:
    int x, y; // Координаты центра окружности
    int radius; // Радиус окружности
public:
    Circle(int x, int y, int radius) : x(x), y(y), radius(radius) {}

    void draw() override {
        std::cout << "Прорисовка окружности с координатами " << x << "," << y << " и радиусом " << radius << std::endl;
    }

    void move(int x, int y) override {
        this->x = x;
        this->y = y;
        std::cout << "Перемещение окружности в координаты " << x << "," << y << std::endl;
    }
};

// Класс Рисунок
class Drawing {
private:
    static const int MAX_FIGURES = 10;
    Figure* figures[MAX_FIGURES]; // Массив указателей на фигуры
    int count; // Текущее количество фигур в рисунке
public:
    Drawing() : count(0) {}

    void addFigure(Figure* figure) {
        if (count < MAX_FIGURES) {
            figures[count++] = figure;
        }
    }

    void draw() {
        for (int i = 0; i < count; i++) {
            figures[i]->draw();
        }
    }

    void moveAll(int x, int y) {
        for (int i = 0; i < count; i++) {
            figures[i]->move(x, y);
        }
    }
};

int main() {
    // Создание объектов фигур
    Point point(100, 100);
    Line line(100, 100, 200, 200);
    Circle circle(200, 200, 50);

    // Создание рисунка и добавление фигур
    Drawing drawing;
    drawing.addFigure(&point);
    drawing.addFigure(&line);
    drawing.addFigure(&circle);

    // Прорисовка и перемещение фигур
    drawing.draw();
    drawing.moveAll(300, 300);
    drawing.draw();

    return 0;
}

