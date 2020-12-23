#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace WindowConstants
{
    const int WIDTH = 600;
    const int HEIGHT = 400;

}

namespace StringConstants
{
    const std::string deJongFunction1 = "DeJongFunction1";

}

namespace ModelDefaultConstants
{
    const float defaultBestGlobalRes = 1;
    const float defaultInercia1 = 1;
    const float defaultInercia2 = 1;
}

class Constants
{
public:
    Constants();
};

#endif // CONSTANTS_H
