#ifndef MAIN_C_IO_H
#define MAIN_C_IO_H

#include "waveform.h"
#include <stddef.h>
#include "waveform.h"
// Loads CSV file into dynamic memory
int loadCSV(const char *filename,
            WaveformSample **samplesOut,
            size_t *countOut);
// Writes final analysis report
int writeReport(const char *filename,
                const char *inputFilename,
                const WaveformSample *samples,
                size_t count,
                const PhaseMetrics metrics[3],
                const WaveformSample *sortedSamples,
size_t sortedCount);

#endif

