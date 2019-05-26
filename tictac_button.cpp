#include "tictac_button.hpp"
#include <vector>
#include "graphics.hpp"
#include <cmath>

using namespace genv;

TicTac_Button::TicTac_Button(float p_x, float p_y, float s_x, float s_y, std::function<void()> f)
    :Button(p_x, p_y, s_x, s_y)
{
    end_game=f;
    win_cond=0;
    turn=false;
    for(int i=0; i<40; i++)
    {
        std::vector<int> row;
        for(int j=0; j<40; j++)
        {
            row.push_back(0);
        }
        tabla.push_back(row);
        row.clear();
    }
}

void TicTac_Button::handle(event ev)
{
    for(size_t i=0; i<tabla.size(); i++)
    {
        for(size_t j=0; j<tabla[i].size(); j++)
        {
            if(ev.pos_x>i*20 && ev.pos_x<(i+1)*20 && ev.pos_y>j*20 && ev.pos_y<(j+1)*20 && ev.button==btn_left)
            {
                if(!turn && tabla[i][j]==0)
                    tabla[i][j]=1, turn=!turn;
                if(turn && tabla[i][j]==0)
                    tabla[i][j]=2, turn=!turn;
            }
        }
    }
    bool p1=false;
    bool p2=false;
    bool draw=true;
    int carry=0;
    int p1t=0;
    int p2t=0;
    for(size_t i=0; i<tabla.size(); i++)
    {
        for(size_t j=0; j<tabla[i].size(); j++)
        {
            if(!p1 && !p2)
            {
                if(carry==0)
                    p1t=0, p2t=0;
                if(carry==1)
                    p2t=0;
                if(carry==2)
                    p1t=0;
                if(tabla[i][j]==1)
                    p1t++, carry=1;
                if(tabla[i][j]==2)
                    p2t++, carry=2;
                if(tabla[i][j]==0)
                    draw=false;
            }
            if(p1t==5)
                p1=true;
            if(p2t==5)
                p2=true;
        }
        carry=0;
    }
    for(size_t i=0; i<tabla[0].size(); i++)
    {
        for(size_t j=0; j<tabla.size(); j++)
        {
            if(!p1 && !p2)
            {
                if(carry==0)
                    p1t=0, p2t=0;
                if(carry==1)
                    p2t=0;
                if(carry==2)
                    p1t=0;
                if(tabla[j][i]==1)
                    p1t++, carry=1;
                if(tabla[j][i]==2)
                    p2t++, carry=2;
                if(tabla[j][i]==0)
                    draw=false;
            }
            if(p1t==5)
                p1=true;
            if(p2t==5)
                p2=true;
        }
        carry=0;
    }
    for(size_t i=0; i<tabla.size(); i++)
    {
        int s=i;
        for(size_t j=0; j<tabla[i].size()-i; j++)
        {
            if(!p1 && !p2)
            {
                if(carry==0)
                    p1t=0, p2t=0;
                if(carry==1)
                    p2t=0;
                if(carry==2)
                    p1t=0;
                if(tabla[s][j]==1)
                    p1t++, carry=1;
                if(tabla[s][j]==2)
                    p2t++, carry=2;
                if(tabla[s][j]==0)
                    draw=false;
            }
            if(p1t==5)
                p1=true;
            if(p2t==5)
                p2=true;
            s++;
        }
        carry=0;
    }
    for(size_t i=0; i<tabla[0].size(); i++)
    {
        int s=i;
        for(size_t j=0; j<tabla.size(); j++)
        {
            if(!p1 && !p2)
            {
                if(carry==0)
                    p1t=0, p2t=0;
                if(carry==1)
                    p2t=0;
                if(carry==2)
                    p1t=0;
                if(tabla[j][s]==1)
                    p1t++, carry=1;
                if(tabla[j][s]==2)
                    p2t++, carry=2;
                if(tabla[j][s]==0)
                    draw=false;
            }
            if(p1t==5)
                p1=true;
            if(p2t==5)
                p2=true;
            s++;
        }
        carry=0;
    }
    for(size_t i=tabla.size()-1; i>0; i--)
    {
        int s=i;
        for(size_t j=0; j<i; j++)
        {
            if(!p1 && !p2)
            {
                if(carry==0)
                    p1t=0, p2t=0;
                if(carry==1)
                    p2t=0;
                if(carry==2)
                    p1t=0;
                if(tabla[s][j]==1)
                    p1t++, carry=1;
                if(tabla[s][j]==2)
                    p2t++, carry=2;
                if(tabla[s][j]==0)
                    draw=false;
            }
            if(p1t==5)
                p1=true;
            if(p2t==5)
                p2=true;
            s--;
        }
        carry=0;
    }
    for(size_t i=tabla.size()-1; i>0; i--)
    {
        int s=i;
        for(size_t j=tabla[i].size()-1; j>i; j--)
        {
            if(!p1 && !p2)
            {
                if(carry==0)
                    p1t=0, p2t=0;
                if(carry==1)
                    p2t=0;
                if(carry==2)
                    p1t=0;
                if(tabla[j][s]==1)
                    p1t++, carry=1;
                if(tabla[j][s]==2)
                    p2t++, carry=2;
                if(tabla[j][s]==0)
                    draw=false;
            }
            if(p1t==5)
                p1=true;
            if(p2t==5)
                p2=true;
            s++;
        }
        carry=0;
    }
    if(p1)
        win_cond=1;
    if(p2)
        win_cond=2;
    if(draw)
        win_cond=3;
    end_game();
}

void TicTac_Button::print() const
{
    canvas tt_btn;
    tt_btn.open(size_x, size_y);
    for(size_t i=0; i<tabla.size(); i++)
    {
        for(size_t j=0; j<tabla[i].size(); j++)
        {
            tt_btn << move_to(i*20, j*20) << color(0, 0, 0) << box(20, 20)
                   << move_to(i*20+1, j*20+1) << color(255, 255, 255) << box(18, 18);
            if(tabla[i][j]==1)
            {
                {
                    tt_btn << color(255,0,0);
                    tt_btn << move_to(i*20+4, j*20+4) << line(12, 12);
                    tt_btn << move_to(i*20+5, j*20+4) << line(12, 12);
                    tt_btn << move_to((i+1)*20-4, j*20+4) << line(-12, 12);
                    tt_btn << move_to((i+1)*20-5, j*20+4) << line(-12, 12);
                }
            }
            if(tabla[i][j]==2)
            {
                tt_btn << color(0, 0, 255);
                for (int u=-8; u<8; u++)
                {
                    for (int v=-8; v<8; v++)
                    {
                        if ((pow(u, 2)+pow(v, 2))<pow(8,2) && (pow(u, 2)+pow(v, 2))>pow(6,2))
                            tt_btn << move_to((2*i+1)*10+u, (2*j+1)*10+v) << dot;
                    }
                }
            }
        }
    }
    gout << stamp(tt_btn, 0, 0);
}
