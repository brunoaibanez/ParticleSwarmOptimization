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
    const std::string rastriginFunction6 = "RastriginFunction6";
    const std::string rosenbrockFunction = "RosenbrockFunction";
    const std::string griewankFunction = "GriewankFunction";
    const std::string schafferFunction = "SchafferFunction";
}

namespace ModelDefaultConstants
{
    const float defaultBestGlobalRes = 1;
    const float defaultInercia1 = 0.1;
    const float defaultInercia2 = 0.1;
    const float defaultInercialWeight = 0.9;
    const float defaultMaxVelocity = 30;

}



class Constants
{
public:
    Constants();
};

#endif // CONSTANTS_H
