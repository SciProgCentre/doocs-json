#include <doocs/Server.h>
#include "EqFctTest.h"

int main(int argc, char *argv[])
{
    doocs::Server server("types_test_server");

    server.register_location_class<EqFctTest>();

    server.run(argc, argv);

    return 0;
}
