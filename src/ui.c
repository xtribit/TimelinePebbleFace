#include <pebble.h>
#include "ui.h"
#include "routines.h"

static Layer *s_canvas_layer;

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  if (!ui_update_needed(tick_time))
    return;
  
}

void create_canvas(Window *window){
  Layer *window_layer = window_get_root_layer(window);
  GRect window_bounds = layer_get_bounds(window_layer);
  
  s_canvas_layer = layer_create(window_bounds);
  layer_add_child(window_layer, s_canvas_layer);
  
  tick_timer_service_subscribe(SECOND_UNIT, tick_handler);
}

void destroy_canvas(){
  layer_destroy(s_canvas_layer);
  tick_timer_service_unsubscribe();
}