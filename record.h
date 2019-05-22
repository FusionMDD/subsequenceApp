#ifndef RECORD_H
#define RECORD_H

#include <QPair>

class Record
{
public:
    Record(int number, int begin, int end);
    Record(const Record & record);
    Record();
    int getStrNumber();
    int getCordinatesFirst();
    int getCordinatesSecond();
    void setStrNumber(int number);
    void setCordinates(int begin,int end);

private:
    QPair <int,int> cordinates;
    int strNumber;

};

#endif // RECORD_H
