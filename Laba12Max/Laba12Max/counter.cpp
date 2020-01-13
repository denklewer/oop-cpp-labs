#include "counter.h"




    Counter::Counter()
    {
    }

    int Counter::getCount()
    {
			
        return ++Count;
    }

    int Counter::getCountT()
    {
			if (CountTriangle < maxTri){
				CountTriangle++;
				return ++maxTri;
			}
			maxTri++;
			return ++CountTriangle;
    }

    int Counter::getCountC()
    {
			if (CountCircle < maxCir){
			
				CountCircle++;
				return ++maxCir;
			}
			maxCir++;
			return ++CountCircle;
    }


    int Counter::getCountR()
    {
			if (CountRect < maxRec){
				CountRect++;
				return ++maxRec;
			}
			maxRec++;
			return ++CountRect;
    }

		int Counter::getCountAll()
		{
			if (CountAll < maxAll){
				CountAll++;
				return ++maxAll;
			}
			maxAll++;
			return ++CountAll;
		}




    int Counter::Count = 0;

  int Counter::CountRect = 0;
    int Counter::CountTriangle = 0;
      int Counter::CountCircle = 0;
			int Counter::CountAll = 0;
			int Counter::maxCir = 0;
			int Counter::maxRec = 0;
			int Counter::maxTri = 0;
			int Counter::maxAll = 0;
