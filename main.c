#include <stdio.h> // allows printing
#include <stdlib.h>
#include "waveform.h"
#include "io.h"

int main() {
    printf("Power Analyer Started\n");

    int count=0;// how many rows were loaded

    WaveformSample*samples= loadCSV ("power_quality_log.CSV", & count);// load files and return pointer rows

    if (samples==NULL){
        printf("Error opening file.\n");
        return 1;
    }

     printf("Loaded %d samples\n", count);

 free(samples);


    return 0;
}

