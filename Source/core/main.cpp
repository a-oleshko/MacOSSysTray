#include "Source/core/AppInstance.h"

int main(int argc, char *argv[])
{
    AppInstance appClient(argc, argv);

    appClient.initApp();

    appClient.startApp();

    return appClient.exec();
}
