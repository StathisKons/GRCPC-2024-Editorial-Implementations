#include <bits/stdc++.h>
using namespace std;

#ifndef M_PI
    #define M_PI acos(-1)
#endif

int main(void) {
    double sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    
    double cx, cy, r;
    cin >> cx >> cy >> r;
    
    auto circ_area = [](double r, double h) -> double {
        return r*r * acos(1 - h/r) - (r - h) * sqrt(r*r - (r-h)*(r-h));
    };
    
    double rectArea = (tx - sx) * (ty - sy);
    double circleArea = M_PI * r * r;
    double target = (rectArea - circleArea) / 2;
    
    double lo = sx;
    double hi = tx;
    while(hi - lo > 1e-6) {
        double m = (lo + hi) / 2;
        
        double area;
        if(m < cx){
            area = (ty - sy) * (m - sx);
            double h = m - (cx - r);
            if(!(m <= cx - r)) area -= circ_area(r, h);
        } else {
            area = (ty - sy) * (tx - m);
            double h = (cx + r) - m;
            if(!(m >= cx + r)) area -= circ_area(r, h);
    
            area = 2*target - area;
        }
    
        if(area < target) lo = m;
        else hi = m;
    }
    
    printf("%.4lf\n", lo);
    
    return 0;
}
