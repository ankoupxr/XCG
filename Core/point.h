#pragma once

namespace XCG{
    namespace Core
    {
        class Point
        {
            public:
                Point(double x,double y,double z):x(x), y(y),z(z){};
                Point(double x,double y):x(x), y(y){};
                ~Point();



                double Point::getX()
                {
                    return x;
                }
                
                double Point::getY()
                {
                    return y;
                }

                double Point::getY()
                {
                    return z;
                }

            protected:
                double x,y,z;
        };       
    }

}

