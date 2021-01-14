#include <iostream>
#include <SFML/Graphics.hpp>
#include <string.h>

using namespace  std;

class Cursor {
    public:
        void rectMove();
        void arrowMove();
};

class Camera {
    public:
        void scrollMove();
        void moveCamera();
};

