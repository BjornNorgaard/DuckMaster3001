#ifndef SUPPORTER_H_
#define SUPPORTER_H_

#include "Person.h"

class Supporter : public Person {
   public:
      Supporter(string firstName, string lastName);
      //virtual ~Supporter();
      virtual void getBrugerInfo(string&, string&);
      virtual void setBrugerInfo(string, string);
      virtual void setUserLevel(int) = 0;
      virtual bool addPills(string, int) = 0;
      virtual bool deletePills(string, int) = 0;
      virtual void printPills() = 0;
      int getUserLevel();
      virtual void printUserInfo() = 0;
   private:

};

#endif // SUPPORTER_H_
