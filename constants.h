#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace WindowConstants
{
    const int WIDTH = 500;
    const int HEIGHT = 500;

}

namespace StringConstants
{
    const std::string deJongFunction1 = "DeJongFunction1";
    const std::string deJongFunction2 = "DeJongFunction2";

}

namespace ModelDefaultConstants
{
    const float defaultBestGlobalRes = 1;
    const float defaultInercia1 = 0.1;
    const float defaultInercia2 = 0.1;
}

class Constants
{
public:
    Constants();
};

#endif // CONSTANTS_H
