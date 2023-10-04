#ifndef DFLAT_COMMAND_LINE_ARGS_HPP
#define DFLAT_COMMAND_LINE_ARGS_HPP

#include <string>

namespace dflat {

class CommandLineArgs {
public:

    CommandLineArgs(int argc, char** argv);
    ~CommandLineArgs() = default;

    std::string get_file_runner() const;
    bool is_valid() const;

private:
    std::string get_file_runner_absolute_path(const std::string& local_file) const;

private:

    std::string m_file_runner;
    bool m_is_valid = true;

}; // CommandLineArgs

} // namespace dflat

#endif // DFLAT_COMMAND_LINE_ARGS_HPP