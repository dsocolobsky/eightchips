Timers
========

CHIP-8 provides two timers, a delay and a sound timer.

Delay Timer
------------
It is active whenever the delay time register (DT) is non-zero. This timer substracts
1 from the value of DT at a rate of 60Hz. When DT reaches 0, it deactivates.

Sound Timer
------------
It is active whenever the sound timer register (ST) is non-zero. It also decrements at
a rate of 60Hz. As long as ST's value is > 0 the buzzer will sound. When DT reaches 0
the timer deactivates and thus the buzzer stops.
The sound produced by the CHIP-8 system has only one tone.
