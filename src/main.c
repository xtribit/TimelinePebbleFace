#include <pebble.h>
#include "ui.h"

static Window *s_main_window;

static void main_window_load(Window *window) {
  create_canvas(window);
}

static void main_window_unload(Window *window) {
  destroy_canvas();
}

static void init(void) {
  s_main_window = window_create();
  
  window_set_window_handlers(s_main_window, (WindowHandlers){
    .load = main_window_load,
    .unload = main_window_unload
  });

  window_stack_push(s_main_window, true);
}

static void deinit(void) {
  window_destroy(s_main_window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
