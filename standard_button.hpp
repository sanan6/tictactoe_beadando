#ifndef STANDARD_BUTTON_HPP_INCLUDED
#define STANDARD_BUTTON_HPP_INCLUDED
#include "button.hpp"
#include <functional>

class Standard_Button : public Button
{
protected:
    std::string label;
    std::function<void()> fv;
public:
    Standard_Button(float p_x, float p_y, float s_x, float s_y, std::string txt, std::function<void()> f);
    void print() const;
    void handle(event ev);
    bool focusable()
    {
        return true;
    }
    void set_label(std::string t)
    {
        label=t;
    }
};



#endif // STANDARD_BUTTON_HPP_INCLUDED
