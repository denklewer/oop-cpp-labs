#ifndef COUNTER_H
#define COUNTER_H

#include <QtGlobal>
class Counter
{
public:
    Counter();
 static int Count;
    static int CountCircle;
     static int CountTriangle;
      static int CountRect;
			static int CountAll;
			static int maxRec;
			static int maxCir;
			static int maxTri;
			static int maxAll;
    static int getCount();
      static int getCountR();
        static int getCountT();
          static int getCountC();
					static int getCountAll();

};

#endif // COUNTER_H
