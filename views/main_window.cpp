#include <iostream>

#include "main_window.h"

main_window::main_window() : m_button ("Hello World")
{
  // Width of the window.
  set_border_width (50);

  m_button.signal_clicked ().connect (sigc::mem_fun(*this,
						    &main_window::on_button_clicked));

  add (m_button);

  m_button.show ();
}

main_window::~main_window() {}

void main_window::on_button_clicked ()
{
  std::cout << "Hello world" << std::endl;
}
