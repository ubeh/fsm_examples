#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>

class Controller {
public:
    Controller();
    void startup();
    void shutdown();
    void do_start() const;
    void do_stop() const;

private:
    // I want to forward declare the sml state machine
    // There is no example at http://boost-experimental.github.io/sml/examples/index.html
    struct Fsm;
    std::shared_ptr<Fsm> fsm_;
};

#endif // CONTROLLER_H
