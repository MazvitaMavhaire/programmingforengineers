//
// Created by mv2-mavhaire on 30/04/2026.
//


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


#endif
