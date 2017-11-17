#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm/window.h>
#include <gtkmm/button.h>

class main_window : public Gtk::Window
{
    
public:
    main_window ();
    virtual ~main_window ();
    
private:
    void on_button_clicked ();

    Gtk::Button m_button;
};

#endif /* MAIN_WINDOW_H */

