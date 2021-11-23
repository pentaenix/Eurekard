#include "Event.h"

Event::Event()
{

}

Event::Event(Event *obj, void (Event::*f)())
{
    object = obj;
    accion = f;
}