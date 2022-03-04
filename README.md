# SpektrumSatellite
Rx receiver library for Arduino DUE and the Spektrum DSMX Satellite receiver. 
Probably works with other Arduinos with some modifications like changing all shorts to ints.
Before using, change which serial port the library should read from in SpektrumSattelite.cpp. Default is Serial3. The library has been tested with the Arduino DUE, Orange RX DSMX receiver and a Spektrum DX9 transmitter for totally several hours without failure but make sure to read the warning below before using!

note you have to have the library files in your local arduino libraries folder  for it to work

C:\Users\user\Documents\Arduino\libraries\SpektrumSatellite\SpektrumSattelite.cpp  
C:\Users\user\Documents\Arduino\libraries\SpektrumSatellite\SpektrumSattelite.h  

tested with lemon rx dsmx receiver

using multi protocol module on frsky radio (https://github.com/pascallanger/DIY-Multiprotocol-TX-Module)
Mode DSM X2F
disable telemetry

throttle channel does not work

arduino pro min 5v
added software serial for debugging

Tx on pin 3
DSM to Rx on pin 2 (Rx)



#Important Warning
The transmitter needs to be started AFTER this library gets initiated! Otherwise, you're going to get semi-random data that may harm you or whatever you're creating using this library (I've personally had a quadrocopter crash right in my face because of this). To fix this you need to implement some security features mainly using the getTrans() method like here: https://github.com/Quarduino/quarduino/blob/master/due_pid/due_pid.ino#L124

Originally based on jbudworth's SpektrumSatRx (https://github.com/jbudworth/SpektrumSatRx).
