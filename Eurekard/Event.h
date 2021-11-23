#pragma once

class Event
{
    protected:
        Event* object;
    public:
        Event();
        Event(Event *obj, void (Event::* f)());
        void (Event::*accion)();
};

