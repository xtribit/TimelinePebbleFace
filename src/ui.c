#include <pebble.h>
#include "ui.h"
#include "datetime.h"
#include "routines.h"
#include "constants.h"

static Layer *s_canvas_layer;
static Layer *s_layers[TIMELINE_NUMBER];
static Layer *s_timeline_line;
static Datetime s_last_datetime;

static void create_layers(){
}

static void update_layers(){
}

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  if (!ui_update_needed(tick_time))
    return;
  
  s_last_datetime = tm_to_datetime(tick_time);
  
  update_layers();
}

static void update_proc(Layer *layer, GContext *ctx) {
  create_layers();
}

void create_canvas(Window *window){
  Layer *window_layer = window_get_root_layer(window);
  GRect window_bounds = layer_get_bounds(window_layer);
  
  s_canvas_layer = layer_create(window_bounds);
  layer_set_update_proc(s_canvas_layer, update_proc);
  layer_add_child(window_layer, s_canvas_layer);
  
  tick_timer_service_subscribe(SECOND_UNIT, tick_handler);
}

void destroy_canvas(){
  layer_destroy(s_canvas_layer);
  tick_timer_service_unsubscribe();
}