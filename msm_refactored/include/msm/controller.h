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
    // Forward declaration of fsm
    // See http://stackoverflow.com/questions/10899641/boost-msm-class/10922799#10922799
    struct Fsm;
    std::shared_ptr<Fsm> fsm_;
};

#endif // CONTROLLER_H
