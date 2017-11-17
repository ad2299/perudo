#include <iostream>
#include <gtkmm/application.h>

#include "main_window.h"

using namespace std;

int main (int argc, char* argv [])
{
  auto app = Gtk::Application::create (argc, argv, "org.gtkmm.example");

  main_window perudo;

  return app->run (perudo);
}
