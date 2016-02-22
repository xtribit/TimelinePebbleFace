#pragma once

typedef struct{
  int second;
  int minute;
  int hour;
  int mday;
  int month;
  int year;
} Datetime;

Datetime tm_to_datetime(struct tm *time);