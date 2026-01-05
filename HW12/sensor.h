#include "stdint.h"
#include "stdio.h"
#include "string.h"

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

struct statistic
{
    uint8_t month;
    uint16_t year;
    float t_av;
    int8_t t_min;
    int8_t t_max;
};

union sensor_serdes
{
    struct data d;
    uint8_t bytes[sizeof(struct data)];
};

void PrintInfo(sensor_t* info, int n);
void AddRecord(union sensor_serdes* ds, uint16_t year, uint8_t month, uint8_t day, int8_t t);
int AddInfo(union sensor_serdes* ds);
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
float GetAverageTemperature(int16_t year, uint8_t month, union sensor_serdes* ds);
int8_t GetMinTemperature(int16_t year, uint8_t month, union sensor_serdes* ds);
int8_t GetMaxTemperature(int16_t year, uint8_t month, union sensor_serdes* ds);
void GetStatistics(uint16_t year, uint8_t month, union sensor_serdes* ds);
void DelReccord(int index, union sensor_serdes* ds);
void ParseSensorInfoFromStr(char* str, union sensor_serdes* ds);