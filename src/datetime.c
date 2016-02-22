#include <pebble.h>
#include "datetime.h"

Datetime tm_to_datetime(struct tm *time){
  return (Datetime){
    .second = time->tm_sec,
    .minute = time->tm_min,
    .hour = time->tm_hour,
    .mday = time->tm_mday,
    .month = time->tm_mon,
    .year = time->tm_year
  };  
}