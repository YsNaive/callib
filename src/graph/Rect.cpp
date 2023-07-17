#include "Rect.h"

namespace callib {
    Rect::Rect(double x, double y, double width, double height)
        : x(x), y(y), width(width), height(height) {}

    Rect::Rect(GraphObject& obj)
    {
        x = 0; y = 0; width = 0; height = 0;
        auto type = obj.getType();
        if (type == E_GraphType::POINT) {
            Point& p = (Point&)obj;
            x = p.x;
            y = p.y;
            return;
        }
        if (type == E_GraphType::LINE) {
            Line& l = (Line&)obj;
            x = std::min(l.begin.x, l.end.x);
            y = std::min(l.begin.y, l.end.y);
            width = std::max(l.begin.x, l.end.x);
            height = std::max(l.begin.y, l.end.y);
            width -= x;
            height -= y;
            return;
        }
        std::cout << "callib:: bounding rect from \'" << obj.getTypeName() << "\' Not Implement.\n";
    }

    double Rect::xMax() const
    {
        return x+width;
    }

    double Rect::yMax() const
    {
        return y + height;
    }

    double Rect::area() const {
        return width * height;
    }

    Point Rect::leftTop() const
    {
        return Point(x,y);
    }

    Point Rect::rightBottom() const
    {
        return Point(x + width, y + height);
    }

    Rect Rect::operator-(const Rect& other) const {
        // 计算两个矩形的交集
        double x1 = std::max(x, other.x);
        double y1 = std::max(y, other.y);
        double x2 = std::min(x + width, other.x + other.width);
        double y2 = std::min(y + height, other.y + other.height);

        if (x1 >= x2 || y1 >= y2) {
            return Rect(0, 0, 0, 0);
        }
        return Rect(x1, y1, x2 - x1, y2 - y1);
    }

    Rect Rect::operator+(const Rect& other) const {
        // 计算两个矩形的并集
        double x1 = std::min(x, other.x);
        double y1 = std::min(y, other.y);
        double x2 = std::max(x + width, other.x + other.width);
        double y2 = std::max(y + height, other.y + other.height);

        // 返回并集矩形
        return Rect(x1, y1, x2 - x1, y2 - y1);
    }

    void Rect::borderOffset(double dx, double dy) {
        x -= dx;
        y -= dy;
        width += dx * 2;
        height += dy * 2;
    }

    bool Rect::isCover(const GraphObject& obj)
    {
        auto type = obj.getType();
        if (type == E_GraphType::POINT) {
            Point& p = (Point&)obj;
            return ((p.x >= x) && (p.x <= xMax()) && (p.y >= y) && (p.y <= yMax()));
        }
        if (type == E_GraphType::LINE) {
            Line& l = (Line&)obj;
            return  ((l.begin.x >= x) && (l.begin.x <= xMax()) && (l.begin.y >= y) && (l.begin.y <= yMax())) &&
                    ((l.end.x >= x) && (l.end.x <= xMax()) && (l.end.y >= y) && (l.end.y <= yMax()));
        }
        std::cout << "callib:: is rect cover \'" << obj.getTypeName() << "\' Not Implement.\n";
    }

} // namespace callib
