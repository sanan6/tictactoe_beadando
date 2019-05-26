#ifndef STATIC_TEXT_HPP_INCLUDED
#define STATIC_TEXT_HPP_INCLUDED
#include "widgets.hpp"
#include <string>

class Static_Text : public Widgets
{
protected:
    std::string label;
public:
    Static_Text(float p_x, float p_y, float s_x, float s_y, std::string l);
    void print() const;
    void handle(event ev) {};
    bool focusable()
    {
        return false;
    }
};

#endif // STATIC_TEXT_HPP_INCLUDED
