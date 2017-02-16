#ifndef FSM_IMPL_H
#define FSM_IMPL_H

#include <boost/msm/front/functor_row.hpp>
#include <boost/msm/front/state_machine_def.hpp>
#include <msm/icontroller.h>

struct ev_start {};
struct ev_stop {};

struct ac_start {
    template <class FSM, class EVT, class SourceState, class TargetState>
    void operator()(EVT const&, FSM& fsm, SourceState&, TargetState&) {
        fsm.ctrl_->do_start();
    }
};
struct ac_stop {
    template <class FSM, class EVT, class SourceState, class TargetState>
    void operator()(EVT const&, FSM& fsm, SourceState&, TargetState&) {
        fsm.ctrl_->do_stop();
    }
};

struct Idle : public boost::msm::front::state<> {};
struct Driving : public boost::msm::front::state<> {};

// front-end: define the FSM structure
struct FsmImpl : public boost::msm::front::state_machine_def<FsmImpl> {
    explicit FsmImpl(IController* ctrl)
        : ctrl_(ctrl) {}

    typedef Idle initial_state;

    // clang-format off
    struct transition_table
        : boost::mpl::vector<
            //                     Source      Event        Target      Action       Guard
            boost::msm::front::Row<Idle,       ev_start,    Driving,    ac_start,    boost::msm::front::none>,
            boost::msm::front::Row<Driving,    ev_stop,     Idle,       ac_stop,     boost::msm::front::none>
            > {};
    // clang-format on

    IController* ctrl_;
};

#endif // FSM_IMPL_H
