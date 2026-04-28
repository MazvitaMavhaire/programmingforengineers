include <stdio.h> // allows printing
#include <stdlib.h>
#include <math.h>

#ifndef WAVEFORM_H
#define WAVEFORM_H

typedef struct{
    double timestamp;
    double phaseA;
    double phaseB;
    double phaseC;
    double current;
    double frequency;
    double powerFactor;
    double thd;
} WaveformSample;

int main() {
printf("Power Analyer Started\n");

FILE*file;
WaveformSample*samples;
file= fopen("power_quality_log.csv", "r");

if (file==NULL){
printf("Error opening file.\n");
return 1;
}
samples=malloc(1000*sizeof(WaveformSample));

fscanf(file, "%&*[

while (fscanf(file, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf"
                  &samples[count].timestamp,//error
                  &samples[count].phaseA,
                  &samples[count].phaseB,
                  &samples[count].phaseC,
                  &samples[count].current,
                  &samples[count].frequency,
                  &samples[count].powerFactor,
                  &samples[count].thd) == 8) {
        count++;
    }
free(samples);
    fclose(file);
return0;
}

   
