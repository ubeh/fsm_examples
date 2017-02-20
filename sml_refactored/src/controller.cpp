#include <iostream>
#include <sml/controller.h>
#include <sml/fsm_impl.h>

// provide complete type definition
struct Controller::Fsm : public boost::sml::sm<FsmImpl> {
    explicit Fsm(Controller* ctrl)
        : boost::sml::sm<FsmImpl>(static_cast<Controller*>(ctrl)) {}
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
