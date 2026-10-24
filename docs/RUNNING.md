# Requirements and reproduction workflow

## MATLAB

1. Open `matlab/Assignment6.mlx`, or set MATLAB's Current Folder to `matlab/` and run `calibrate_ntc`.
2. Ensure Curve Fitting Toolbox is installed.
3. Inspect the seven calibration points, fitted coefficients, and generated resistance and voltage plots.
4. Keep new results separate from the supplied plots until the source's calibration-sign issue is resolved.

The `.m` file was extracted from the Live Script. Its text and dependencies were inspected; it was not executed in MATLAB during conversion. The original report mentions CalCurve and Rref, but these are not separate supplied files or calculations in the Live Script.

## Arduino

1. Open `arduino/Calibration/Calibration.ino` in Arduino IDE for the calibration stage.
2. Review the resistance equation before uploading: the original sketch's denominator has the opposite sign to the stated voltage-divider algebra.
3. For measurement, open `arduino/sketch_feb15a/sketch_feb15a.ino` and install a TimerOne library compatible with the actual board.
4. Select the actual board and port. The original schematic shows an Uno; the firmware assumes a 10-bit ADC and a 3.49 V external reference.
5. Verify wiring against the LM324 package pinout and the board's AREF documentation. Amplifier four's output is pin 14 in the depicted 14-pin LM324, not pin 1 as stated in the source narrative.
6. After resolving the implementation issues, use Serial Monitor at 9600 baud to inspect voltage, resistance, and temperature.

No upload, Arduino compilation, or hardware validation was performed. The interrupt updates a shared floating-point value that is not declared volatile; safe synchronization and atomic access need review for the board architecture. Printing every 200 ms is not synchronized to the sampling interrupt.

## Additional source files

The archive already provides two Arduino sketches and the MATLAB Live Script. Add any separately stored code in its relevant folder, preserving helper files and documenting actual dependencies. Use a separate, clearly named revision if fixing the source so the historical implementation remains identifiable.

The demonstration video remains in the original RAR archive. It is larger than GitHub's 25 MiB browser-upload file limit, so it is not included in the prepared browser-upload package.

Official references:

- Arduino analog reference: https://docs.arduino.cc/language-reference/en/functions/analog-io/analogReference/
- TI LM324-family pinout: https://www.ti.com/lit/gpn/LM124-N
