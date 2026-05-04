#ifndef WAVEFORM_H
#define WAVEFORM_H
#include <stddef.h>

#include <stdint.h>

#define NOMINAL_RMS_VOLTAGE 230.0//EXPECTED RMS
#define RMS_TOLERANCE_PERCENT 10.0 //TOLERANCE ALLOWANCE
#define CLIPPING_LIMIT 324.9 // CLIPPING THRESHOLD
#define DC_OFFSET_LIMIT 5.0// if average voltage is more than this, flag the DC offset

//Bitwise status flags
#define STATUS_CLIPPING 0x01// bit0
#define STATUS_OUT_OF_TOLERANCE 0X02// bit1
#define STATUS_DC_OFFSET 0X04// bit 2



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
/*
 * PhaseMetrics: stores calculated results for ONE phase
 * i.e. Phase A will have its own RMS, PEAK TO PEAK, DC OFFSET
 */
typedef struct {
    double rms;
    double peakToPeak;
    double dcOffset;
    double minimum;
    double maximum;
    double variance;
    double standardDeviation;
    int clippedSamples;
    int withinTolerance;
    uint8_t statusFlags;
}PhaseMetrics;
/*
 * PhaseSelector : choose which phase to analyse
 */
typedef enum {
    PHASE_A,
    PHASE_B,
    PHASE_C
}PhaseSelector;

//Analyse one phase and return all calculates metrics

PhaseMetrics analysePhase(const WaveformSample*samples,
                          size_t count,PhaseSelector phase);

void sortSamplesByVoltageMagnitude(WaveformSample*samples,size_t count,PhaseSelector phase);


//check for status flag

int hasStatusFlag(uint8_t flags, uint8_t flag);
#endif
