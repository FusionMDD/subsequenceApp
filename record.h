#ifndef RECORD_H
#define RECORD_H

#include <QPair>

class Record
{
public:
    Record();
    int getStrNumber();
    QPair <int,int> getCordinates();
    void setStrNumber(int number);
    void setCordinates(int begin,int end);

private:
    QPair <int,int> cordinates;
    int strNumber;

};

#endif // RECORD_H
