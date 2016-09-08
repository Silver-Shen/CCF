#include <iostream>
#include <assert.h>
using namespace std;

struct window
{
    int x1,y1,x2,y2;
    int code;
    window *up, *down;
};

int main(int argc, char const *argv[])
{
    int N, M;
    cin >> N >> M;
    window* bottom = NULL, *top = NULL;
    for (int i=0; i<N; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        window* p = new window;
        p->x1 = x1; p->y1 = y1; p->x2 = x2; p->y2 = y2; p->up = p-> down = NULL; p->code = i+1;
        if (!bottom) bottom = top = p;
        else{
            top->up = p;
            p->down = top;
            top = p;
        }        
    }    
    for (int i=0; i<M; i++){
        int x, y, active = 0;
        cin >> x >> y;        
        window* p = top;
        while (p){
            //cout << p->code << endl;
            if (p->x1 <= x && x <= p->x2 && p->y1 <= y && y <= p->y2){
                if (p == top){
                    active = p->code;
                    break;
                }
                active = p->code;
                if (p->up) p->up->down = p->down;
                if (p->down) p->down->up = p->up;
                p->up = NULL;
                p->down = top;
                top->up = p;
                top = p;
                break;
            }
            p = p->down;
        }
        if (active) cout << active << endl;
        else cout << "IGNORED" << endl;
        // p = top;
        // while (p){
        //     cout << p->code << ' ';
        //     p = p->down;
        // }
    }    
    return 0;
}