#ifndef ICONTROLLER_H
#define ICONTROLLER_H

class IController {
public:
    virtual ~IController()        = default;
    virtual void do_start() const = 0;
    virtual void do_stop() const  = 0;
};

#endif // ICONTROLLER_H
