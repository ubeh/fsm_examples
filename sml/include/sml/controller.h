#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <sml/icontroller.h>
#include <sml/fsm_impl.h>

class Controller : public IController {
public:
    Controller();
    void startup();
    void shutdown();
    void do_start() const override;
    void do_stop() const override;

private:
    boost::sml::sm<FsmImpl> fsm_;
};

#endif // CONTROLLER_H
