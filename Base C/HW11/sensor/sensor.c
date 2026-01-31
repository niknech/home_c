#include "sensor.h"

void PrintInfo(sensor_t* info, int n)
{
    for(int i = 0; i<n; i++)
    {
        printf ("%u-%u-%u %d\n", info[i].year, info[i].month, info[i].day, info[i].t);
    }
    printf("=====================\n");
}

void AddRecord(sensor_t info[], uint8_t number, uint16_t year, uint8_t month, uint8_t day, int8_t t)
{
    info[number].year = year;
    info[number].month = month;
    info[number].day = day;
    info[number].t = t;
}

int AddInfo(sensor_t info[])
{
    int counter=0;  
    AddRecord(info,counter++,2021,9,16,9);
    AddRecord(info,counter++,2022,9,2,-9);
    AddRecord(info,counter++,2021,1,7,8);
    AddRecord(info,counter++,2021,9,5,1);
    AddRecord(info,counter++,2021,9,5,1);
    return counter;
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
