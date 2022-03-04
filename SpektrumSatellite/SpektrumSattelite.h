//SpektrumSattelite Receiver Libriary
#ifndef SPECTRUMRECEIVER_H_
#define SPECTRUMRECEIVER_H_

#include "Arduino.h"
class SpektrumSattelite
{
	public:
		bool getFrame();
		int getChannelValue(int);
		int getThro();
		int getAile();
		int getElev();
		int getRudd();
		int getGear();
		int getPitc();
		int getAux2();
		int getAux3();
		int getAux4();
		bool getTrans();
	private:
		int inData[16];
		int i;
		int inByte;
		
		int chVal[9];
		unsigned int tempData;
		unsigned int temp;
		unsigned int tempId;
		unsigned int tempVal;
		unsigned long time;
};


#endif /* SPECTRUMRECEIVER_H_ */
