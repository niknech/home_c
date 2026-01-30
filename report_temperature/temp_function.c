#include "temp_function.h"
const char* MonthNames [12] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};

void PrintInfo(sensor_t* info, int n)
{
    for(int i = 0; i<n; i++)
    {
        printf ("%u-%u-%u %u:%u %d\n", info[i].year, info[i].month, info[i].day, info[i].hour, info[i].minute, info[i].t);
    }
    printf("=====================\n");
}

int InitSensorData (sensor_data_t* sensor_data)
{
    sensor_data->size = DEFAULT_SIZE;
    sensor_data->number = 0;
    sensor_data->info = malloc(sensor_data->size * sizeof(*sensor_data->info));
    return (!sensor_data->info) ? -1 : 0;
}

int AddRecord(sensor_data_t* sensor_data, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, int8_t t)
{
    if (sensor_data->size<=sensor_data->number)
    {
        sensor_t* tmp = realloc(sensor_data->info, sensor_data->size * 2 * sizeof(*sensor_data->info));
        if (!tmp)
        {
            printf("Can't resize sensor_t array\n");
            return -1;
        }
        sensor_data->size *= 2;
        sensor_data->info = tmp;
        printf("There is not enough space in the array [info]. New size: %lu\n", sensor_data->size);
    }

    sensor_data->info[sensor_data->number].year = year;
    sensor_data->info[sensor_data->number].month = month;
    sensor_data->info[sensor_data->number].day = day;
    sensor_data->info[sensor_data->number].hour = hour;
    sensor_data->info[sensor_data->number].minute = minute;
    sensor_data->info[sensor_data->number].t = t;
    sensor_data->number++;
    return 0;
}

void ReadFile(sensor_data_t* sensor_data, const char* filename)
{
    uint16_t year;
    uint8_t  month;
    uint8_t  day;
    uint8_t  hour;
    uint8_t  minute;
    int8_t   t;

    FILE *file = fopen(filename, "r");
    if (!file) 
    {
        printf("Can't open file %s\n", filename);
        return;
    }

    char line[LINE_LEN];
    uint32_t row = 1;
    uint32_t added = 0;

    while (fgets(line, sizeof(line), file)) 
    {

        int status = sscanf(line, "%hu;%hhu;%hhu;%hhu;%hhu;%hhd", &year, &month, &day, &hour, &minute, &t);

        if (status != COLUMNS) 
        {
            printf("Error in row %u: read only %d fields\n", row, status);
            row++;
            continue;
        }

        if (!AddRecord(sensor_data, year, month, day, hour, minute, t)) 
            added++;
        else
            printf("Add record error in row %u\n", row);

        row++;
    }

    fclose(file);
    
    printf("Added %u rows\n", added);
}

void PrintStatistics(sensor_data_t* sensor_data, StatisticMode mode, int target_month) //target_month = 0 for year statistic
{
    Statistic_t stat;
    switch (mode)
    {
    case ALL_MONTHES:
        PrintMonthStatistic(sensor_data);
        break;
    
    case SINGLE_MONTH:
        stat = CalculateMonthStatistic(sensor_data, target_month);
        printf("Average temperature in %s: %.2f\nMinimal temperature in %s: %d\nMaximal temperature in %s: %d\n-----------------------------\n", MonthNames[target_month-1], stat.avgTemp, MonthNames[target_month-1], stat.minTemp, MonthNames[target_month-1], stat.maxTemp);
        break;

    case YEAR:
        stat = CalculateMonthStatistic(sensor_data, 0);
        printf("==============STATISTICS BY YEAR==============\n");
        printf("Average temperature: %.2f\nMinimal temperature: %d\nMaximal temperature: %d\n-----------------------------\n", stat.avgTemp, stat.minTemp, stat.maxTemp);
        break;
    }
}

void PrintMonthStatistic(sensor_data_t* sensor_data)
{
    Statistic_t stat = 
    {
        .maxTemp = INT16_MIN,
        .minTemp = INT16_MAX,
        .avgTemp = 0,
        .count = 0
    };

    printf("==============STATISTICS BY MONTH==============\n");

    for (int i = 1; i < 13; i++)
    {
        stat = CalculateMonthStatistic(sensor_data, i);
        printf("Average temperature in %s: %.2f\nMinimal temperature in %s: %d\nMaximal temperature in %s: %d\n-----------------------------\n", MonthNames[i-1], stat.avgTemp, MonthNames[i-1], stat.minTemp, MonthNames[i-1], stat.maxTemp);
    }
    
}

Statistic_t CalculateMonthStatistic(sensor_data_t* sensor_data, int target_month)
{
    Statistic_t stat = 
    {
        .maxTemp = INT16_MIN,      
        .minTemp = INT16_MAX,
        .avgTemp = 0,
        .count = 0
    };
    
    if (target_month < 0 || target_month > 12) //0 for year statistic
    {
        printf("Incorrect target month\n");
        return stat;
    }
    
    for (int i = 0; i < sensor_data->number; i++)
    {
        if (sensor_data->info[i].month == target_month || target_month == 0)
        {
            if (sensor_data->info[i].t < stat.minTemp)
                stat.minTemp = sensor_data->info[i].t;
            if (sensor_data->info[i].t > stat.maxTemp)
                stat.maxTemp = sensor_data->info[i].t;
            stat.avgTemp += sensor_data->info[i].t;
            stat.count++;
        }
    }

    if (stat.count > 0)
        stat.avgTemp /= stat.count;
    else
        stat.avgTemp = 0;
    
    return stat;
}

void PrintHelpInformation()
{
    printf("=====HELP INFORMATION=====\n");
    printf("-h - help information\n");
    printf("-f [FILENAME] - read csv-file\n");
    printf("-m [NUMBER OF MONTH] - statistic of chosen month\n");
    printf("-y - statistic of year\n");
    printf("-s - statistics of all monthes\n");
    printf("-p - print sensor data\n");
    return;
}

void checkArguments(int argc, char* argv[], sensor_data_t sensor_data)
{
    if (argc == 1)
    {
        PrintHelpInformation();
        return;
    }

    int opt;

    while ((opt = getopt(argc, argv, "hf:m:ysp"))!=-1)
    {
        switch (opt)
        {
        case 'h':
            PrintHelpInformation();
            break;
        
        case 'f':
            ReadFile(&sensor_data, optarg);
            break;

        case 'm':
            int target_month;
            if (!sscanf(optarg, "%d", &target_month))
                break;
            if (target_month < 1)
            {
                printf("Incorrect target month!\n");
                break;
            }
            PrintStatistics(&sensor_data, SINGLE_MONTH, target_month);
            break;
        
        case 'y':
            PrintStatistics(&sensor_data, YEAR, 0);
            break;
        
        case 's':
            PrintMonthStatistic(&sensor_data);
            break;
        
        case 'p':
            PrintInfo(sensor_data.info, sensor_data.number);
            break;

        default:
            break;
        }
    }
}
