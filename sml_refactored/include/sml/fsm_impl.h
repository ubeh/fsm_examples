#ifndef FSM_IMPL_H
#define FSM_IMPL_H

#include <boost/sml.hpp>
#include <sml/controller.h>

struct ev_start {};
struct ev_stop {};

auto ac_start = [](Controller* ctrl) { ctrl->do_start(); };
auto ac_stop  = [](Controller* ctrl) { ctrl->do_stop(); };

struct FsmImpl {
    auto operator()() const noexcept {
        using namespace boost::sml;
        // clang-format off
        return make_transition_table(
                 *"Idle"_s       + event<ev_start>    / ac_start    =    "Driving"_s
                , "Driving"_s    + event<ev_stop>     / ac_stop     =    "Idle"_s
        );
        // clang-format on
    }
};

#endif // FSM_IMPL_H
