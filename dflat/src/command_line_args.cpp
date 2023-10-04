#include <dflat/command_line_args.hpp>

#include <format>
#include <iostream>
#include <string>
#include <unordered_map>
#include <filesystem>

namespace {

std::unordered_map<std::string, std::string> key_value{
    { "--help", "D-Flat Help!" },
};

} // namespace

namespace dflat {

CommandLineArgs::CommandLineArgs(int argc, char** argv) {
    for (int i{ 1 }; i < argc; ++i) {
        const std::string& value(argv[i]);
        if (key_value.find(value) != key_value.end()) {
            std::cout << key_value.at(value) << "\n";
        }
        else if (value.length() >= 3 && value.substr(value.length() - 3) == ".df") {
            m_file_runner = this->get_file_runner_absolute_path(value);
        }
        else {
            std::cerr << "WARNING: Could not find argv \"" << value << "\"\n";
        }
    }

    if (m_file_runner.empty()) {
        m_is_valid = false;
        std::cerr << "ERROR: Could not find file runner.\nUsage: " << argv[0] << " <filename.df>\n";
    }
}

std::string CommandLineArgs::get_file_runner() const {
    return m_file_runner;
}

bool CommandLineArgs::is_valid() const {
    return m_is_valid;
}

std::string CommandLineArgs::get_file_runner_absolute_path(const std::string& local_file) const {
    if (std::filesystem::exists(local_file)) {
        std::filesystem::path absolute_path{ std::filesystem::absolute(local_file) };
        return absolute_path;
    }
    return {};
}

} // namespace dflat

