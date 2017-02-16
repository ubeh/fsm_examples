#include <iostream>
#include <msm/controller.h>

Controller::Controller()
    : fsm_(static_cast<IController*>(this)) {}

void Controller::startup() {
    fsm_.process_event(ev_start{});
}

void Controller::shutdown() {
    fsm_.process_event(ev_stop{});
}

void Controller::do_start() const {
    std::cout << "do_start\n";
}

void Controller::do_stop() const {
    std::cout << "do_stop\n";
}
