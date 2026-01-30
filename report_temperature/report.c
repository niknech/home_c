#include <stdio.h>
#include "temp_function.h"

int main (int argc, char* argv[])
{
    sensor_data_t sensor_data;
    InitSensorData(&sensor_data);

    checkArguments(argc, argv, sensor_data);
}

