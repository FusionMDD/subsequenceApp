#include "record.h"

Record::Record(int number, int begin, int end)
{
strNumber = number;
cordinates = QPair<int,int>(begin, end);
}

Record::Record(const Record & record)
{
   this->setStrNumber(record.strNumber);
   this->setCordinates( record.cordinates.first,record.cordinates.second);

}
Record::Record()
{
   strNumber = 0;
   cordinates.first = 0;
   cordinates.second = 0;
}



int Record::getStrNumber()
{
    return strNumber;

}
int Record:: getCordinatesFirst()
{
    return cordinates.first;

}
int Record:: getCordinatesSecond()
{
    return cordinates.second;

}
void Record:: setStrNumber(int number)
{
    strNumber = number;

}
void Record:: setCordinates(int begin,int end)
{
    cordinates.first = begin;
    cordinates.second = end;
}
