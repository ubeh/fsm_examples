#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <boost/msm/back/state_machine.hpp>
#include <msm/fsm_impl.h>
#include <msm/icontroller.h>

class Controller : public IController {
public:
    Controller();
    void startup();
    void shutdown();
    void do_start() const override;
    void do_stop() const override;

private:
    boost::msm::back::state_machine<FsmImpl> fsm_;
};

#endif // CONTROLLER_H
