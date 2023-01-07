## Ender 2 Pro v423 Updated OEM Firmware.. This firmware is designed to be used with a Stock Hot End at no more than 220c and the Stock Heated bed at no more than 65c. If you change the Hot End out for a Higher temp one, then it is suggested that you attach an external Meanwell Power supply rated at 350watts and 15amps. The OEM PSU is not rated for higher temps and can burn out. You have been warned.
The firmware in this repository only works with the OEM Creality v4.2.3 Motherboard. It must have a STM32F103RET6 CPU. If your Ender 2 Pro has a 2219 Creality Motherboard with a HC32F460KCTA CPU, loading this firmware on this Non-Compatible motherboard can cause damage and/or a short circuit.
## Specific Firmware Functionality:
1. Cleaner Main Information Screen.
2. Single Language Menu System.
3. Cleaner and more detailed Menu System.
4. Cleaner and better labled Menu System.
5. No automatic timeout and return to main information screen. (Really anoying when you turn away for a second, and it is back on the Main Information Screen, and you have to start again.)
6. You must manually scroll and click to return to previous menus and to the Main Information Screen.
Filament Run Out Sensor. (On by Default, but it can be turned off in the Settings Menu.If you do not have a Filament Run Out Sensor, this must be set to Off in the Settings Menu)
7. LCD Assisted Manual 4 Corner Bed Leveling. (Paper method at 4 corners over bed screws, leveling by raising and lowering with bed adjustment wheels)
8. (9)Nine Point LCD Assisted Manual Mesh Bed Leveing. (No need for ABL Probe) Paper method, raising and lower the nozzle with the LCD knob at (9) nine points around the bed to create a mesh, just like an ABL Probe, but none of the waiting, wiring, setup, firmware recompiling, and in my opinion, a simpler way to level the bed.
9. Long File Names Enabled.
10 Scrolling of Longer File Names Enabled.
11. Removal of ABS Preheat, since the Ender 2 Pro cannot print ABS.
13. Single PLA Preheat. Temps are as follows: Hot-End 205c Bed Temp 65c.
14. Thermal Runaway Protection Enabled.
15. No ABL Probe Function is available, and there will not be at this time.

# Sponsorship for this repository: 
##  Cash App, using the cashtag: $The300lbGorilla
