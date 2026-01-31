#include "sensor.h"

void PrintInfo(sensor_t* info, int n)
{
    for(int i = 0; i<n; i++)
    {
        printf ("%u-%u-%u %d\n", info[i].year, info[i].month, info[i].day, info[i].t);
    }
    printf("=====================\n");
}

void AddRecord(union sensor_serdes* ds, uint16_t year, uint8_t month, uint8_t day, int8_t t)
{
    ds->d.info[ds->d.number].year = year;
    ds->d.info[ds->d.number].month = month;
    ds->d.info[ds->d.number].day = day;
    ds->d.info[ds->d.number].t = t;
    ds->d.number++;
}

int AddInfo(union sensor_serdes* ds)
{
    AddRecord(ds,2021,9,16,9);
    AddRecord(ds,2022,9,2,-9);
    AddRecord(ds,2021,1,7,8);
    AddRecord(ds,2021,9,5,1);
    AddRecord(ds,2021,9,5,1);
    return ds->d.number;
}

void DelReccord(int index, union sensor_serdes* ds)
{
    if (index >= ds->d.number || index < 0) return;

    memmove(&ds->d.info[index], &ds->d.info[index+1], (ds->d.number - index - 1)*sizeof(ds->d.info[0]));
    ds->d.number--;
}

void changeIJ(sensor_t* info, int i, int j)
{
    sensor_t tmp = info[i];
    info[i] = info[j];
    info[j] = tmp;
}

void SortByT(sensor_t* info, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = n-1; j>i; j--)
            if (info[j].t<info[j-1].t)
                changeIJ(info, j, j-1);
}

uint32_t DateToInt(sensor_t* info)
{
    return info->year << 16 | info->month << 8 | info->day;
}

void SortByDate(sensor_t* info, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i; j<n; j++)
            if (DateToInt(info+i) > DateToInt(info+j))
                changeIJ(info, i, j);    
}

int Compare (const void* va, const void* vb)
{
    sensor_t* a = (sensor_t*)va;
    sensor_t* b = (sensor_t*)vb;

    if(a->year != b->year)
        return a->year - b->year;
    else if (a->month != b->month)
        return a->month - b->month;
    else
        return a->day - b->day;
}

void save_bin (sensor_t* info, int n)
{
    FILE *f = fopen ("d:\\MIPT\\C_projects\\sensor\\data.bin", "wb");
    fwrite(info, sizeof(sensor_t), n, f);
    fclose(f);
}

void read_bin(sensor_t* info, int n)
{
    FILE *f = fopen ("d:\\MIPT\\C_projects\\sensor\\data.bin", "rb");
    fread(info, sizeof(sensor_t), n, f);
    fclose(f);    
}

void load_bin_d (struct data* d)
{
    FILE *f = fopen ("d:\\MIPT\\C_projects\\sensor\\data.bin", "rb");
    fread(&d->number, sizeof(d->number), 1, f);
    fread(d->info, d->number*sizeof(sensor_t),1,f);
    fclose(f); 
}

void save_bin_d (struct data d)
{
    FILE *f = fopen ("d:\\MIPT\\C_projects\\sensor\\data.bin", "wb");
    fwrite(&d.number, sizeof(d.number), 1, f);
    fwrite(d.info, d.number*sizeof(sensor_t), 1, f);
    fclose(f);
}

void load_bin_des(union sensor_serdes* ds)
{
    FILE* f = fopen("d:\\MIPT\\C_projects\\sensor\\data.bin","rb");
    fread(ds->bytes,sizeof(ds->d.number), 1,f);
    fread(ds->bytes+sizeof(ds->d.number), ds->d.number*sizeof(sensor_t),1,f);
    fclose(f);
}

void save_bin_des (union sensor_serdes* ds)
{
    FILE *f = fopen ("d:\\MIPT\\C_projects\\sensor\\data.bin", "wb");
    fwrite(ds->bytes, sizeof(ds->d.number), 1, f);
    fwrite(ds->bytes + sizeof(ds->d.number), ds->d.number*sizeof(sensor_t),1, f);
    fclose(f);
}

float GetAverageTemperature(int16_t year, uint8_t month, union sensor_serdes* ds)
{
    int count = 0;
    float result = 0;

    for (int i=0; i<ds->d.number; i++)
    {
        if (ds->d.info[i].year != year)
            continue;
        
        if (ds->d.info[i].month != month && month != 0)
            continue;

        result += ds->d.info[i].t;
        count++;
    }

    if (!count)
        return -1;

    return result/count;  
}

int8_t GetMinTemperature(int16_t year, uint8_t month, union sensor_serdes* ds)
{
    int min = INT8_MAX;

    for (int i=0; i<ds->d.number; i++)
    {
        if (ds->d.info[i].year != year)
            continue;
        
        if (ds->d.info[i].month != month && month != 0)
            continue;

        if (ds->d.info[i].t < min)
            min = ds->d.info[i].t;
    }
    
    return min;
}

int8_t GetMaxTemperature(int16_t year, uint8_t month, union sensor_serdes* ds)
{
    int max = INT8_MIN;

    for (int i=0; i< ds->d.number; i++)
    {
        if (ds->d.info[i].year != year)
            continue;
        
        if (ds->d.info[i].month != month && month != 0)
            continue;

        if (ds->d.info[i].t > max)
            max = ds->d.info[i].t;
    }
    
    return max;
}

void GetStatistics(uint16_t year, uint8_t month, union sensor_serdes* ds)
{
    struct statistic stat;
    stat.year = year;
    stat.month = month;
    stat.t_av = GetAverageTemperature(year, month, ds);
    stat.t_max = GetMaxTemperature(year, month, ds);
    stat.t_min = GetMinTemperature(year, month, ds);
  
    char str_month = '\0';
    if (month)
        str_month = month + 0x30;

    printf("===%d %c statistics===\r\nAverage temperature: %.2f\r\nMinimal temperature: %d\r\nMaximum Temperature: %d\n", stat.year, str_month,stat.t_av, stat.t_min, stat.t_max);
}

void ParseSensorInfoFromStr(char* str, union sensor_serdes* ds)
{
    int y, m, d, temp;

    if (sscanf(str, "%d-%d-%d %d", &y, &m, &d, &temp) == 4)
    {
        AddRecord(ds, (uint16_t)y, (uint8_t)m, (uint8_t)d, (int8_t)temp);
        printf("Adding %s\n", str);
    }
    else
        printf("Parsing error\n");
}
