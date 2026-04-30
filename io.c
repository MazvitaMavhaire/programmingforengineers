#include <stdio.h>
#include <stdlib.h>
#include "io.h"


WaveformSample*loadCSV(const char *filename,int*count) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        return NULL;
    }


    int maxRows = 1000;
    WaveformSample *samples = malloc(1000 * sizeof(WaveformSample));

    char line[256];
    fgets(line, sizeof(line), file);


    while (fgets(line, sizeof(line), file)) {
        WaveformSample row;

        sscanf(line, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
               &row.timestamp,
               &row.phaseA
               & row.phaseB,
               &row.phaseC,
               &row.current,
               &row.frequency,
               &row.powerFactor,
               &row.thd);

        samples[*count] = row;


        (*count)++;

    }

    fclose(file);
    return samples;
