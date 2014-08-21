#pragma once
#include <ostream>
#include <string>
#include "smc_compiler.h"

void gen_swift(std::string const& package_name, std::string const& fsmclass, state_map_list_t const& state_map_list, std::string const& start_map, std::string const& start_state, transition_set_t const& transition_set);
void gen_javascript(std::string const& package_name, std::string const& fsmclass, state_map_list_t const& state_map_list, std::string const& start_map, std::string const& start_state, transition_set_t const& transition_set);

class intented_out
{
    std::ostream& out_;
    int indent_;

public:
    intented_out(std::ostream& out, int indent)
    :   out_(out)
    ,   indent_(indent)
    {}

    std::ostream& operator<<(const char *str)
    {
        do_indent();
        out_ << str;

        return out_;
    }

    std::ostream& operator<<(std::string const& str)
    {
        do_indent();
        out_ << str;

        return out_;
    }

    intented_out operator()(int indent) const
    {
        return intented_out(out_, indent_ + indent);
    }

private:
    void do_indent()
    {
        for (int i = 0; i < indent_; i++) {
            out_ << "    ";
        }
    }
};
