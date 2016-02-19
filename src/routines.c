#include <pebble.h>
#include "routines.h"
#include "constants.h"

bool ui_update_needed(struct tm *current_time){
  return 	current_time->tm_sec % UPDATE_IN_SECONDS ? false : true;
}
