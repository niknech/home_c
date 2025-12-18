#include "stdint.h"
#include "stdio.h"

#define SIZE 30



typedef struct
{
    uint8_t day;
    uint8_t month;
    uint16_t year;
    int8_t t;
} sensor_t; 

struct data
{
    uint32_t number;
    sensor_t info[SIZE];
};

union sensor_serdes
{
    struct data d;
    uint8_t bytes[sizeof(struct data)];
};

void PrintInfo(sensor_t* info, int n);
void AddRecord(sensor_t info[], uint8_t number, uint16_t year, uint8_t month, uint8_t day, int8_t t);
int AddInfo(sensor_t info[]);
void changeIJ(sensor_t* info, int i, int j);
void SortByT(sensor_t* info, int n);
uint32_t DateToInt(sensor_t* info);
void SortByDate(sensor_t* info, int n);
int Compare (const void* va, const void* vb);
void save_bin (sensor_t* info, int n);
void read_bin(sensor_t* info, int n);
void load_bin_d (struct data* d);
void save_bin_d (struct data d);
void load_bin_des(union sensor_serdes* ds);
void save_bin_des (union sensor_serdes* ds);