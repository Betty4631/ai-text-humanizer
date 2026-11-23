// main.cpp — entry point. Wires config and subsystems together.

#include "aitexthumanizer/settings.h"
#include "aitexthumanizer/humanizer.h"
#include "aitexthumanizer/patterns.h"
#include "aitexthumanizer/paraphrase.h"
#include <csignal>
#include <memory>

namespace { std::atomic<bool> g_running{true}; void on_signal(int) { g_running.store(false); } }

int main(int argc, char** argv) {
    std::signal(SIGINT, on_signal);
    std::signal(SIGTERM, on_signal);

    aitexthumanizer::Settings settings = aitexthumanizer::Settings::load_default();
    aitexthumanizer::Humanizer humanizer(settings.store_path);
    aitexthumanizer::Patterns patterns(settings.store_path);
    aitexthumanizer::Paraphrase paraphrase(settings.store_path);
    std::fprintf(stderr, "[ai-text-humanizer] ready\n");

    while (g_running.load()) {
        // main loop: pump subsystems
        break;
    }
    return 0;
}
