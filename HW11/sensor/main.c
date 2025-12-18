#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "stdlib.h"
#include "sensor.h"



int main(void)
{
    union sensor_serdes ds = {0};    
    ds.d.number = AddInfo(ds.d.info);

    save_bin_des(&ds);
    load_bin_des(&ds);
    
    PrintInfo(ds.d.info, ds.d.number);

    return 0;
}