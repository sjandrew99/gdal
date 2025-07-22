#include <stdio.h>
#include "gdal_priv.h"

int main(int argc, char ** argv)
{
    if (argc < 2)
    {
        fprintf(stderr,"Usage: %s srtm file\n",argv[0]);
        return 0;
    }
    
    //check to see if file exists:
    FILE * fp = fopen(argv[1],"r");
    if (fp == NULL)
    {
        fprintf(stderr,"%s does not exist!\n",argv[1]);
        //return -1;
    }
    else
        fclose(fp);
    
    fprintf(stdout,"MAIN: Registering gdal drivers...\n");
    GDALAllRegister();
    fprintf(stdout, "MAIN drivers registered\n");
    
    //TODO - check if it's a zip
    
    GDALDataset * dataset = (GDALDataset *)GDALOpen(argv[1],GA_ReadOnly);
    //GDALDatasetUniquePtr dataset;
    //dataset = GDALDatasetUniquePtr(GDALDataset::FromHandle(GDALOpen(argv[1],GA_ReadOnly)));
    
    fprintf(stdout,"successfully opened %s using driver: %s\n", argv[1],dataset->GetDriver()->GetDescription());
    
}