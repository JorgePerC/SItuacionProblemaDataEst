#include <vector>
#include "ConexionesComputadora.h"


/**
 * Class to manage ConexionesComputadora 
 * Just to try reduce ejecution times
 */

class ConnectionManager
{
private:
    vector <ConexionesComputadora> allConnections;

    //Search by IP last number
public:
    ConnectionManager(/* args */);
    ~ConnectionManager();
};