#Power Quality Analyser
#overview
This program processes waveform data and calculates key electrical metrics for three phases A,B
,C
#features
analyse Phase A, B and C voltages
calculate RMS
measure peak to peak voltage
DC offset calculation
variance and standard deviation
detection of clipped signals
voltage tolerance checking
bitwise status flag system
sorting samples by voltage magnitude

#How it works
#waveformsample structure
Each sample contains:
timestamp
phase voltages
current,frequency,power factor,thd

#key functions
1.analysePhase()
calculates: RMS Voltage,Min/Max values,Peak to peak,variance& standard deviation, clipping detection and tolerance status
2.getPhaseVoltage()
returns the selected phase voltage from a sample
3.hasStatusFlag()
uses bitwise operations to check system status flags
4.sortSamplesByVoltageMagnitude()
sorts samples in descending order of voltage magnitude

#file structure
main.c
waveform.h
waveform.c
io.h
io.c

#AUTHOR
MAZVITA MAVHAIRE