#pragma once

#include <iostream>
#include <windows.h>

class Key
{
    private:

        bool curState, prevState;

    public:

        ///constructor
        Key()
        {
            curState = false;
            prevState = false;
        }

        ///accessors
        bool& accessCurState()
        {
            return curState;
        }

        bool& accessPrevState()
        {
            return prevState;
        }

        ///associated methods
        bool isDown() const
        {
            return (curState == true);
        }

        bool isUp() const
        {
            return (curState == false);
        }

        bool isPressed() const
        {
            return (prevState == false && curState == true);
        }
};

class InputDevice
{
    protected:

        Key* keyset;
        int key_count;

        ///device constructor
        InputDevice(int keyCount)
        {
            key_count = keyCount;
            keyset = new Key[key_count];
        }

        ///virtual methods
        virtual void saveKeyState() = 0;
        virtual void resetKeyState() = 0;
        virtual void checkKeyState() = 0;

        ///device destructor
        ~InputDevice()
        {
            delete[] keyset;
        }

    public:

        ///device key getter
        Key getKey(int index) const
        {
            if(index >= 0 && index < key_count) return keyset[index];
            else
            {
                std::cout << "\nERROR:[ invalid device key ]\n";
                return Key();
            }
        }
};

class Keyboard : public InputDevice
{
    private:

        ///keyboard key state handlers
        void saveKeyState()
        {
            for(int i = 0; i < 34; i++)
            {
                keyset[i].accessPrevState() = keyset[i].accessCurState();
            }
        }

        void resetKeyState()
        {
            for(int i = 0; i < 34; i++)
            {
                keyset[i].accessCurState() = false;
            }
        }

    public:

        ///keyboard key mapping
        enum
        {
            A, B, C, D,
            E, F, G, H,
            I, J, K, L,
            M, N, O, P,
            Q, R, S, T,
            U, V, W, X,
            Y, Z,

            LEFT_ARROW,
            UP_ARROW,
            RIGHT_ARROW,
            DOWN_ARROW,

            ENTER,
            SPACEBAR,
            BACKSPACE,
            ESCAPE
        };

        ///keyboard constructor
        Keyboard() : InputDevice(34) {}

        ///keyboard key checker
        void checkKeyState()
        {
            saveKeyState();
            resetKeyState();

            for(int i = 0; i < 26; i++)
            {
                keyset[i].accessCurState() = ((GetKeyState((const short)'A' + i) & 0x8000) != 0);
            }

            for(int i = 0; i < 4; i++)
            {
                keyset[26 + i].accessCurState() = ((GetKeyState(VK_LEFT + i) & 0x8000) != 0);
            }

            keyset[30].accessCurState() = ((GetKeyState(VK_RETURN) & 0x8000) != 0);
            keyset[31].accessCurState() = ((GetKeyState(VK_SPACE) & 0x8000) != 0);
            keyset[32].accessCurState() = ((GetKeyState(VK_BACK) & 0x8000) != 0);
            keyset[33].accessCurState() = ((GetKeyState(VK_ESCAPE) & 0x8000) != 0);
        }
};

class Mouse : public InputDevice
{
    private:

        COORD position;

        ///mouse key state handlers
        void savePrevKeyState()
        {
            keyset[0].accessPrevState() = keyset[0].accessCurState();
            keyset[1].accessPrevState() = keyset[1].accessCurState();
        }

        void resetKeyState()
        {
            keyset[0].accessCurState() = false;
            keyset[1].accessCurState() = false;
        }

    public:

        ///mouse key mapping
        enum
        {
            LEFT_BUTTON,
            RIGHT_BUTTON
        };

        ///mouse constructor
        Mouse() : InputDevice(2)
        {
            position.X = 0;
            position.Y = 0;

            SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_EXTENDED_FLAGS | ENABLE_MOUSE_INPUT);
        }

        ///mouse position getter
        COORD getCursorPosition()
        {
            INPUT_RECORD inputBuffer[32];

            DWORD events = 0;
            GetNumberOfConsoleInputEvents(GetStdHandle(STD_INPUT_HANDLE), &events);

            if(events > 0) ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), inputBuffer, events, &events);

            for(int i = 0; i < events; i++)
            {
                if(inputBuffer[i].EventType == MOUSE_EVENT && inputBuffer[i].Event.MouseEvent.dwEventFlags == MOUSE_MOVED)
                {
                    position = inputBuffer[i].Event.MouseEvent.dwMousePosition;
                }
            }

            return position;
        }

        ///mouse key checker
        void checkKeyState()
        {
            saveKeyState();
            checkKeyState();

            keyset[0].accessCurState() = ((GetKeyState(VK_LBUTTON) & 0x8000) != 0);
            keyset[1].accessCurState() = ((GetKeyState(VK_RBUTTON) & 0x8000) != 0);
        }
};
