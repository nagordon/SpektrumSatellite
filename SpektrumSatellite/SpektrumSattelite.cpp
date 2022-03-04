//SpektrumSattelite Receiver Libriary
//Tested with Arduino DUE, Orange RX DSMX and Spektrum DX9
//To make it work on UNO or similar, change all ints to ints and select the right serial
#include "SpektrumSattelite.h"

bool SpektrumSattelite::getFrame(void)
{	
	  while (Serial.available() >= 16)
	  {
	  time = millis();
		for (i = 0; i <= 15; i++)
		{
		  inByte = Serial.read();
		  inData[i] = inByte;
		}
	  }

    for (i = 1; i < 8; i++)
    {
      temp = inData[i * 2] * 256 + inData[i * 2 + 1];

      tempId = temp >> 11;

      tempVal = temp << 5;
      tempVal = tempVal >> 5;

		if (tempId < 9)
		{
		  chVal[tempId] = tempVal - 342;
		}
		else 
		{
		  //error, ignore ;)
		}
	}
	
	return getTrans();
  
}

bool SpektrumSattelite::getTrans()
{
	if (millis() - time > 1000)
	{
		return false;
	}
	else	
	{
		return true;
	}
}

int SpektrumSattelite::getChannelValue(int channelId)
{
	return chVal[channelId];
}

int SpektrumSattelite::getThro()
{
	return getChannelValue(0);
}

int SpektrumSattelite::getAile()
{
	return getChannelValue(1);
}

int SpektrumSattelite::getElev()
{
	return getChannelValue(2);
}

int SpektrumSattelite::getRudd()
{
	return getChannelValue(3);
}

int SpektrumSattelite::getGear()
{
	return getChannelValue(4);
}

int SpektrumSattelite::getPitc()
{
	return getChannelValue(5);
}

int SpektrumSattelite::getAux2()
{
	return getChannelValue(6);
}

int SpektrumSattelite::getAux3()
{
	return getChannelValue(7);
}

int SpektrumSattelite::getAux4()
{
	return getChannelValue(8);
}