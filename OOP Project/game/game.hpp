#include <iostream>
#include "menu.hpp"

class Game
{
    private:

        static void console_setup()
        {
            ConsoleUtil::enable_mouse_input();
            ConsoleUtil::custom_screen_setup(150, 53, 11, 16);
            ConsoleUtil::fullscreen();
        }

    public:

        static void run()
        {
            console_setup();
            MainMenu::run();
        }
};
