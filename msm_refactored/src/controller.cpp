#include <boost/msm/back/state_machine.hpp>
#include <iostream>
#include <msm/controller.h>
#include <msm/fsm_impl.h>

// provide complete type definition
struct Controller::Fsm : public boost::msm::back::state_machine<FsmImpl> {
    explicit Fsm(Controller* ctrl)
        : boost::msm::back::state_machine<FsmImpl>(ctrl) {}
};

Controller::Controller()
    : fsm_(std::make_shared<Fsm>(this)) {}

void Controller::startup() {
    fsm_->process_event(ev_start{});
}

void Controller::shutdown() {
    fsm_->process_event(ev_stop{});
}

void Controller::do_start() const {
    std::cout << "do_start\n";
}

void Controller::do_stop() const {
    std::cout << "do_stop\n";
}
