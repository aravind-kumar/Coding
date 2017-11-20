#ifndef TIME_H
#define TIME_H

unsigned int combine(unsigned int a,unsigned int b) 
{
  int times;
  if(b)
  {
      times = 1;
  }
  else
  {
     times=100;
  }
  while (times <= b)
      times *= 10;
  return a*times + b;
}
  
unsigned int getMinutes(unsigned int time)
{
   unsigned int onesDigit = time % 10;
   unsigned int hundereds = ((time/10)%10)*10;
   return (hundereds + onesDigit);
}

unsigned int getHours(unsigned int time)
{
   unsigned int onesDigit = ((time/100)%10);
   unsigned int hundreds = ((time/1000)%10)*10;
   return (hundreds+onesDigit);
}

unsigned int convertMinsToUTC(unsigned int time)
{
   unsigned int hours = time/60;
   unsigned int minutes = time%60;
   //Should i do mod 24 of the hours ?
   return (combine(hours,minutes)); 
}

unsigned int getTimeInMinutes(unsigned int time)
{
   unsigned int mins = getMinutes(time);
   unsigned int hours = getHours(time);
   return (mins+(hours*60));
}

unsigned int getDiffTime(unsigned int time1,unsigned int time2)
{
     unsigned int time1inMins = getTimeInMinutes(time1);
     unsigned int time2inMins = getTimeInMinutes(time2);
     return (time1inMins-time2inMins); 
}

unsigned int addTime(unsigned int time1,unsigned int time2)
{
     unsigned int time1inMins = getTimeInMinutes(time1);
     unsigned int time2inMins = getTimeInMinutes(time2);
     return (time1inMins+time2inMins); 
}

unsigned int AddUTC2400(unsigned int time1,unsigned int time2)
{
    unsigned int time1mins = getMinutes(time1);
    unsigned int time2mins = getMinutes(time2);
    unsigned int time1hours = getHours(time1);
    unsigned int time2hours = getHours(time2);
    unsigned int totalTimeMins=time1mins+time2mins;
    unsigned int totalTimeHours=time1hours+time2hours;
    if (totalTimeMins > 60)
    {
	 totalTimeMins=totalTimeMins%60;
	 totalTimeHours+=1;
    }
    totalTimeHours=totalTimeHours%24;
    return (combine(totalTimeHours,totalTimeMins));
}



#endif
