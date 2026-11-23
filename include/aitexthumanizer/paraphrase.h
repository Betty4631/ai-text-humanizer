// paraphrase — part of ai-text-humanizer.

#pragma once

#include <string>
#include <vector>

namespace aitexthumanizer {

class Paraphrase {
public:
    explicit Paraphrase(const std::string& config_path);

    void configure(const std::string& key, const std::string& value);
    bool run();
    bool verbose() const { return verbose_; }

private:
    std::string config_path_;
    bool verbose_ = false;
};

}  // namespace aitexthumanizer
