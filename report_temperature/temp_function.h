#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include <stdlib.h>
#include "getopt.h"

#define DEFAULT_SIZE 100
#define COLUMNS 6
#define LINE_LEN 128
#define BIG_DATA_FILE "temperature_big.csv"
#define SMALL_DATA_FILE "temperature_small.csv"

typedef struct
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t t;
} sensor_t; 

typedef struct
{
    uint32_t size;
    uint32_t number;
    sensor_t* info;
} sensor_data_t;

typedef enum
{
    SINGLE_MONTH,
    ALL_MONTHES,
    YEAR
} StatisticMode;

typedef struct
{
    int minTemp;
    int maxTemp;
    float avgTemp;
    int count;
} Statistic_t;

void PrintInfo(sensor_t* info, int n);
int InitSensorData (sensor_data_t* sensor_data);
int AddRecord(sensor_data_t* sensor_data, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, int8_t t);
void ReadFile(sensor_data_t* sensor_data, const char* filename);
void PrintMonthStatistic(sensor_data_t* sensor_data_t);
void PrintStatistics(sensor_data_t* sensor_data, StatisticMode mode, int target_month);
Statistic_t CalculateMonthStatistic(sensor_data_t* sensor_data, int target_month);
Statistic_t CalculateYearStatistic(sensor_data_t* sensor_data);
void checkArguments(int argc, char* argv[], sensor_data_t sensor_data);