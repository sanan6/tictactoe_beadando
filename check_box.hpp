#ifndef CHECK_BOX_HPP_INCLUDED
#define CHECK_BOX_HPP_INCLUDED
#include "widgets.hpp"
#include "graphics.hpp"

using namespace genv;

class Check_Box : public Widgets
{
protected:
    bool marked;
public:
    Check_Box(float p_x, float p_y, float s_x, float s_y);
    virtual void print() const;
    virtual void handle(event ev);
    bool focusable()
    {
        return true;
    }
};

#endif // CHECK_BOX_HPP_INCLUDED
