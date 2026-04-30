#include <stdio.h> // allows printing
#include <stdlib.h>
#include "waveform.h"
#include "io.h"

int main() {
printf("Power Analyser Started\n");

    int count=0;//how many rows loaded
  //load files and return pointer rows 
    
WaveformSample*samples= loadCSV("power_quality_log.csv", & count);


if (samples==NULL){
printf("Error opening file.\n");
return 1;
}
    printf("Loaded %d samples\n", count);

    free(samples);

    return 0;
}
   
